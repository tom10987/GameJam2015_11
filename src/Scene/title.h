
#pragma once
#include "sceneBase.hpp"
#include "../Objects/Enemy/EnemyOne.h"
#include "../Objects/Enemy/EnemyTwo.h"
#include <memory>


namespace engine2d {
namespace scene {


class Title : public SceneBase {
public:
  Title();

  void update() override;
  void draw() override;

private:
	std::shared_ptr<EnemyOne> enemy_one;
	std::shared_ptr<EnemyTwo> enemy_two;
};


}  // end scene
}  // end engine2d
