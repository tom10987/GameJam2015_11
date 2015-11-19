
#pragma once
#include "sceneBase.hpp"
#include "../Objects/Camera.h"
#include "../Objects/Player.h"
#include "../Objects/EnemyBase.h"
#include "../Objects/BackGround.h"
#include "../Objects/StageBlock.h"
#include <list>
#include <fstream>


namespace engine2d {
namespace scene {


class MainGame : public SceneBase {
public:
  MainGame();

  void update() override;
  void draw() override;

private:
  Data data;
  Sprite sprite;

  Camera camera;
  Player player;
  Vec2f backForce;
  const Vec2f constantForce;

  BackGround bg;
  std::list<StageBlock> blocks;
  std::list<pEnemyBase> enemies;

  void LoadData();
  void force();
  void deadEnemyRemove();

  void loading(std::ifstream&, const bool);
};


}  // end scene
}  // end engine2d
