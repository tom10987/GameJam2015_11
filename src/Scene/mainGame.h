
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

  Media normal;
  Media special;
  Media bossBattle;
  Media bossBattleSpecial;

  Camera camera;
  Player player;
  Vec2f backForce;
  const Vec2f constantForce;

  bool inGroundFlag;

  bool hoge;

  BackGround bg;
  std::list<StageBlock> blocks;
  std::list<pEnemyBase> enemies;

  Texture cut;
  Vec2f cutSize;

  void LoadData();
  void addForce();
  void deadEnemyRemove();

  void loading(std::ifstream&, const bool);
};


}  // end scene
}  // end engine2d
