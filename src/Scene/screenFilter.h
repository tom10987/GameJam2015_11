
#pragma once
#include "sceneBase.hpp"
#include <map>
#include <functional>


namespace engine2d {
namespace scene {


class ScreenFilter {
public:
  void update();
  virtual void draw() = 0;

  void SequenceStart() { state = State::SequenceOut; }
  void SequenceReset() { state = State::SequenceIn; }

  const bool isFadeActive() const { return state != State::Update; }
  const bool isFinish() const { return state == State::Finish; }

protected:
  ScreenFilter() : state(State::SequenceIn) {}
  virtual ~ScreenFilter() {}

  const Vec2f& windowSize() const { return env().viewSize(); }

  enum class State {
    SequenceIn,
    Update,
    SequenceOut,
    Finish,

    AllState,
  };

  State state;

  typedef std::function<void()>  Sequence;
  std::map<State, Sequence> SequenceList;
};


class Fade : public ScreenFilter {
public:
  Fade(const float);

  void draw() override;

private:
  float alpha;
  const float alphaSpeed;

  void Fadein();
  void Fadeout();
};


class Wipe : public ScreenFilter {
public:
  Wipe(const float);

  void draw() override;

private:
  float wipeTime;
  const float wipeSpeed;

  void Wipein();
  void Wipeout();
};


}  // end scene
}  // end engine2d
