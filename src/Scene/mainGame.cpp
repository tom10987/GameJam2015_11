
#include "mainGame.h"

namespace eg = engine2d;
namespace es = engine2d::scene;


es::MainGame::MainGame() :
  SceneBase(SceneName::Main, SceneName::Result) {
}


void es::MainGame::update() {
  isFinish_ = env().isPushKey(KeyBind::Space);
  auto hoge = env().isPushButton(Mouse::LEFT);

}


void es::MainGame::draw() {
  eg::drawCircle(Vec2f::Zero(),
                 Vec2f::Ones() * 20.0f, 20, Color::blue);
}
