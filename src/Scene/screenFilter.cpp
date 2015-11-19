
#include "screenFilter.h"

namespace eg = engine2d;
namespace es = engine2d::scene;


void es::ScreenFilter::update() {
  auto sequence = SequenceList.find(state);
  if (sequence != SequenceList.end()) { SequenceList[state](); }
}


//------------------------------------------------------------
// Fade

es::Fade::Fade(const float speed) : alphaSpeed(speed) {
  SequenceList.insert(std::make_pair(State::SequenceIn, std::bind(&Fade::Fadein, this)));
  SequenceList.insert(std::make_pair(State::SequenceOut, std::bind(&Fade::Fadeout, this)));
}


void es::Fade::draw() {
  eg::drawBox(-windowSize() * 0.5f, windowSize(), Color(0, 0, 0, alpha));
}


void es::Fade::Fadein() {
  if (alpha > 0.0f) { alpha -= 0.02f; return; }
  state = State::Update;
}


void es::Fade::Fadeout() {
  if (alpha < 1.0f) { alpha += 0.02f; return; }
  state = State::Finish;
}


//------------------------------------------------------------
// Wipe

es::Wipe::Wipe(const float speed) : wipeTime(-Width / 2), wipeSpeed(speed) {
  SequenceList.insert(std::make_pair(State::SequenceIn, std::bind(&Wipe::Wipein, this)));
  SequenceList.insert(std::make_pair(State::SequenceOut, std::bind(&Wipe::Wipeout, this)));
}


void es::Wipe::draw() {
  const auto window = windowSize();
  drawFillBox(wipeTime, -window.y() * 0.5f,
              windowSize().x(), windowSize().y(), Color(0, 0, 0, 1));
}


void es::Wipe::Wipein() {
  if (wipeTime > -windowSize().x() * 1.5f) { wipeTime -= wipeSpeed; return; }
  state = State::Update;
  wipeTime = windowSize().x() * 0.5f;
}


void es::Wipe::Wipeout() {
  if (wipeTime > -windowSize().x() * 0.5f) { wipeTime -= wipeSpeed; return; }
  state = State::Finish;
}
