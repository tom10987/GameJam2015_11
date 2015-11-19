
#include "mainGame.h"
#include <fstream>
#include <string>

namespace eg = engine2d;
namespace es = engine2d::scene;


es::MainGame::MainGame() :
  SceneBase(SceneName::Main, SceneName::Result),
  camera(Vec2f::Zero(), Vec2f(BG_WIDTH, BG_HEIGHT)),
  bg(0.0f),
  backForce(0, 0),
  constantForce(-3, 3) {

  sprite.block = Texture("res/hoge.png");
  sprite.enemy = Texture("res/hoge.png");

  // カメラの補正
  // あらかじめプレイヤーの位置に移動させておく
  camera.Update(&player);
}


void es::MainGame::update() {
  const float deltaTime = 8.0f;

  // TIPS: プレイヤーの処理
  // 重力を先に与えてから高さの補正を行うことで、
  // 一瞬地面にめり込むような表示が無くなる
  {
    // ジャンプ判定
    player.jump();

    // 重力
    player.gravity();

    // 足場との当たり判定
    for (auto& block : blocks) {
    }

    // 地面との当たり判定
    if (player.getPos().y() < StageGround) { player.landing(StageGround); }

    // 敵との当たり判定
    // 当たっていたらノックバック処理
    for (auto& enemy : enemies) {
      if (!eg::env().isPushKey(GLFW_KEY_G)) { continue; }
      backForce = constantForce * deltaTime;
    }

    if (eg::env().isPushKey(GLFW_KEY_G)) {
      backForce = constantForce * deltaTime;
      player.setJumpState();
    }

    // ノックバック処理
    force();

    // プレイヤーの移動距離から、次の背景を表示するか判定
    const auto isMoved = bg.checkPoint(player.getPos().x());

    // 背景が移動したら敵キャラと足場を新しく生成する
    if (isMoved) { LoadData(); }

    // 移動
    player.move(deltaTime);
  }

  // カメラ更新
  camera.Update(&player);

  // デバッグ用
#ifdef _DEBUG
  isFinish_ = env().isPushButton(Mouse::RIGHT);
#endif
}


void es::MainGame::draw() {
  bg.Draw(camera.getPos());
  for (auto& block : blocks) { block.draw(camera.getPos(), sprite.block); }
  for (auto& enemy : enemies) { enemy->draw(); }
  player.Draw(camera.getPos());
}


void es::MainGame::LoadData() {
}


void es::MainGame::force() {
  if (backForce.x() < 0.0f) { backForce.x() += 1.0f; }
  if (backForce.y() > 0.0f) { backForce.y() -= 1.0f; }
  player.translate(backForce);
}
