
#include "title.h"

namespace eg = engine2d;
namespace es = engine2d::scene;


es::Title::Title() :
  SceneBase(SceneName::Title, SceneName::Main) {
}


void es::Title::update() {
  isFinish_ = env().isPushKey(KeyBind::Space);
}


void es::Title::draw() {
  eg::drawCircle(Vec2f::Zero(),
                 Vec2f::Ones() * 20.0f, 20, Color::white);
}
