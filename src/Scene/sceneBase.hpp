
#pragma once
#include "../Utility/renderer.h"
#include <memory>


namespace engine2d {
namespace scene {


enum class SceneName {
  Title,
  Main,
  Result,

  AllScene,
  None,
};


class SceneBase {
public:
  SceneBase(const SceneName current,
            const SceneName next) :
    current_(current), next_(next), isFinish_(false) {}

  virtual ~SceneBase() {}

  virtual void update() {}
  virtual void draw() {}

  const inline SceneName getSceneName() const { return current_; }
  const inline SceneName getNextScene() const { return next_; }

  const inline bool isFinish() const { return isFinish_; }

protected:
  bool isFinish_;
  SceneName next_;

private:
  SceneName current_;
};


typedef std::shared_ptr<SceneBase>  pScene;


}  // end scene
}  // end engine2d
