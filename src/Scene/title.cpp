
#include "title.h"
#include "../Objects/Enemy/EnemyBase.h"

namespace eg = engine2d;
namespace es = engine2d::scene;



es::Title::Title() :
  SceneBase(SceneName::Title, SceneName::Main) {
	enemy_one = std::make_shared<EnemyOne>(Vec2f(10,0),Vec2f(100,100));
	enemy_two = std::make_shared<EnemyTwo>(Vec2f(-10, 0), Vec2f(100, 100));
}


void es::Title::update() {
  isFinish_ = env().isPushKey(KeyBind::Space);
}


void es::Title::draw() {
  eg::drawCircle(Vec2f::Zero(),
                 Vec2f::Ones() * 20.0f, 20, Color::white);

  enemy_one->draw();
  enemy_two->draw();
}
