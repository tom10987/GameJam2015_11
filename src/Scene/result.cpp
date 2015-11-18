
#include "result.h"

namespace eg = engine2d;
namespace es = engine2d::scene;


es::Result::Result() :
  SceneBase(SceneName::Result, SceneName::Title) {
}


void es::Result::update() {
  isFinish_ = env().isPushKey(KeyBind::Space);
}


void es::Result::draw() {
  eg::drawCircle(Vec2f::Zero(),
                 Vec2f::Ones() * 20.0f, 20, Color::red);
}
