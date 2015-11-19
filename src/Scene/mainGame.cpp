﻿
#include "mainGame.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

namespace eg = engine2d;
namespace es = engine2d::scene;


es::MainGame::MainGame() :
  SceneBase(SceneName::Main, SceneName::Result),
  camera(Vec2f::Zero(), Vec2f(BG_WIDTH, BG_HEIGHT)),
  bg(0.0f),
  backForce(0, 0),
  constantForce(-3, 3) {

  sprite.block = Texture("res/hoge.png");
  sprite.enemy.clear();
  sprite.enemy.push_back(Texture("res/hoge.png"));
  sprite.enemy.push_back(Texture("res/hoge.png"));
  sprite.enemy.push_back(Texture("res/hoge.png"));

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
      // 当たっていなければ、スキップ
      if (true) { continue; }

      backForce = constantForce * deltaTime;
      player.setJumpState();

      player.HP() -= enemy->getAttack();
      enemy->damage(player.Attack());

      //player.hp <= 0;
      if (player.HP() <= 0) {
        //シーン遷移
        data.isGameOver = true;
        next_ = SceneName::Result;
        isFinish_ = true;
      }
      // 敵のHPが0であれば
      if (enemy->isDead()) {
        //更にプレイヤーの必殺技ゲージを加算
        player.Gauge() += enemy->getGaugePower();
      }

      // プレイヤーが無敵状態であればゲージを減らす
      if (player.isInvincible == true) {
        player.countTimer -= 1.0f;
        if (player.countTimer < 0) {
          player.cancelInvincible();
        }
      }

      // プレイヤーの必殺技ゲージがMAXであれば
      if (player.IsGaugeMax()) {
        player.Invincible();
      }

      break;
    }

    // 死んでる敵を消す
    deadEnemyRemove();

    // ノックバック処理
    force();

    // プレイヤーの移動距離から、次の背景を表示するか判定
    const auto isMoved = bg.checkPoint(player.getPos().x());

    // 背景が移動したら敵キャラと足場を新しく生成する
    //if (isMoved) { LoadData(); }

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
  for (auto& enemy : enemies) { enemy->draw(camera.getPos(), sprite.enemy[enemy->getID()]); }
  player.Draw(camera.getPos());
}


void es::MainGame::LoadData() {
  std::ostringstream out1, out2;
  const auto rand1 = eg::random()(1, 7);
  auto rand2 = eg::random()(1, 7);
  if (rand1 == rand2) { rand2 = (rand1 + 1) % 7 + 1; }
  out1 << "res/save" << rand1 << ".txt";
  out2 << "res/save" << rand2 << ".txt";

  std::ifstream load1(out1.str().c_str());
  if (load1) { loading(load1, false); }

  //std::ifstream load2(out2.str().c_str());
  //if (load2) { loading(load2, true); }
}


void es::MainGame::force() {
  if (backForce.x() < 0.0f) { backForce.x() += 1.0f; }
  if (backForce.y() > 0.0f) { backForce.y() -= 1.0f; }
  player.translate(backForce);
}


void es::MainGame::deadEnemyRemove() {
  auto itr = enemies.begin();
  while (itr != enemies.end()) {
    if (itr->get()->isDead()) {
      itr = enemies.erase(itr);
      continue;
    }
    ++itr;
  }
}


void es::MainGame::loading(std::ifstream& file, const bool isSecond) {
  const auto windowOut = player.getPos().x() - Width / 2;

  // すでに通過したエリアにあるオブジェクトのみ削除
  auto block = blocks.begin();
  while (block != blocks.end()) {
    const bool isThrough = block->getPos().x() < windowOut;
    isThrough ? block = blocks.erase(block) : ++block;
  }
  auto enemy = enemies.begin();
  while (enemy != enemies.end()) {
    const bool isThrough = enemy->get()->getPos().x() < windowOut;
    isThrough ? enemy = enemies.erase(enemy) : ++enemy;
  }

  int count;
  file >> count;

  for (int i = 0; i < count; ++i) {
    int x;
    int y;
    int index;

    file >> x >> y >> index;

    // 背景が動いた回数を取得
    const auto count = bg.getCount();

    const auto size = bg.getSize() - Vec2f(0, bg.getSize().y());
    const auto offset = size * (isSecond ? (count + 1) : count) - size / 2;
    const auto pos = Vec2f(x, y) * 96 + Vec2f(0, StageGround) + offset;

    DOUT << "player.x = " << player.getPos().x() << std::endl;
    DOUT << "player.y = " << player.getPos().y() << std::endl;
    DOUT << "new pos.x = " << pos.x() << std::endl;
    DOUT << "new pos.y = " << pos.y() << std::endl;

    if (index == 1) { blocks.push_back(StageBlock(pos)); }
    else {
      const auto enemyID = index / 2;
      const auto isOdd = index % 2;

      if (!isOdd) {
        switch (enemyID) {
          case 1: enemies.push_back(std::make_shared<EnemyGround>(pos)); break;
          case 2: enemies.push_back(std::make_shared<EnemyFlying>(pos)); break;
          case 3: enemies.push_back(std::make_shared<EnemyGround>(pos)); break;
          default: enemies.push_back(std::make_shared<Boss>(pos)); break;
        }
      }
      // TODO: プレイヤーが無敵だったときに修正する
      else if (isSecond) {
        switch (enemyID) {
          case 1: enemies.push_back(std::make_shared<EnemyGround>(pos)); break;
          case 2: enemies.push_back(std::make_shared<EnemyFlying>(pos)); break;
          case 3: enemies.push_back(std::make_shared<EnemyGround>(pos)); break;
          default: enemies.push_back(std::make_shared<Boss>(pos)); break;
        }
      }
    }
  }
}
