
#pragma once
#include "sceneBase.hpp"
#include "../Objects/Player.h"
#include "../Objects/EnemyBase.h"


namespace engine2d {
namespace scene {


class MainGame : public SceneBase {
public:
  MainGame();

  void update() override;
  void draw() override;

private:
	Player player;
  std::vector<pEnemyBase> enemies;
};


}  // end scene
}  // end engine2d
