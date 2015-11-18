
#include "../engine2d.hpp"
#include <chrono>

//
// アプリの初期化、その他の雑多な処理をまとめる
//

namespace engine2d {


class Application {
public:
  static Application& get() {
    static Application s_app;
    return s_app;
  }

  void release() {
    appEnvRelease();
    randomRelease();
  }

  AppEnv& env() { return *app_; }
  Random& random() { return *rand_; }

private:
  std::unique_ptr<AppEnv> app_;
  std::unique_ptr<Random> rand_;

  Application() :
    app_(std::make_unique<AppEnv>(Width, Height, false, true)),
    rand_(std::make_unique<Random>()) {}

  void appEnvRelease() {
    if (!app_) return;
    auto p = app_.release();
    delete p;
  }

  void randomRelease() {
    if (!rand_) return;
    auto p = rand_.release();
    delete p;
  }
};


class Fps {
  typedef std::chrono::steady_clock  std_clock;
  typedef std::chrono::milliseconds  m_sec;

public:
  static Fps& get() {
    static Fps s_fps;
    return s_fps;
  }

  void update() {
    using namespace std::chrono;
    current_ = std_clock::now();
    elapsedTime_ = duration_cast<m_sec>(current_ - prev_);
    prev_ = current_;
  }

  const inline double deltaTime() const {
    return static_cast<double>(elapsedTime_.count()) * 0.001;
  }

private:
  std_clock::time_point current_;
  std_clock::time_point prev_;
  m_sec elapsedTime_;

  Fps() :
    current_(std::chrono::steady_clock::now()),
    prev_(std::chrono::steady_clock::now()),
    elapsedTime_(0) {}
};


extern void assetManagerSetup();
extern void assetRelease();


void applicationSetup() {
  Application::get();
  Fps::get();
  assetManagerSetup();

  using namespace std::chrono;
  auto clock = steady_clock::now();
  auto seed = clock.time_since_epoch().count();
  Application::get().random().setSeed(seed);
}


void applicationRelease() {
  assetRelease();
  Application::get().release();
}


AppEnv& env() { return Application::get().env(); }
Random& random() { return Application::get().random(); }

void frameUpdate() { Fps::get().update(); }
const double getElapsedTime() { return Fps::get().deltaTime(); }


}
