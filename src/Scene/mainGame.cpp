
#include "mainGame.h"

namespace eg = engine2d;
namespace es = engine2d::scene;


es::MainGame::MainGame() :
  SceneBase(SceneName::Main, SceneName::Result) {
}


void es::MainGame::update() {
  //プレイヤー移動
  player.pos_x += player.speed;

  // 画面右から飛び出したら左に戻る
  if (player.pos_x > Width / 2) { player.pos_x = -Width / 2; }

  //落下加速度を加える
  player.jumpPower -= 3.0f;
  //もし地面についていたら止まる
  if (player.pos_y < 0) {
    player.isJump = false;
    player.pos_y = 0.0f;
    player.jumpPower = 0.0f;

  }
  //ジャンプボタンを押していて、地面についていたらジャンプ
  if ((env().isPushKey(KeyBind::Space)) && player.isJump == false) {
    player.isJump = true;
    player.jumpPower = 40;
  }
  //床とのあたり判定
  if (player.pos_x >= 100 && player.pos_x <= 300 && player.pos_y >= 250) {
    player.pos_y = 250;
    player.jumpPower = 0;
  }
  else
    //落下処理
    player.pos_y += player.jumpPower;
  /*
  if (player.pos_x == 100)
  {
    player.pos_x = 5;
    player.pos_y = 50;
    //落下処理
    player.pos_y += player.jumpPower;
  }*/

  isFinish_ = env().isPushButton(Mouse::RIGHT);
}

void es::MainGame::draw() {
  eg::drawCircle(Vec2f(player.pos_x, player.pos_y), Vec2f(player.scale_x, player.scale_y), 20, Color::blue);
  //eg::drawBox(Vec2f(player.pos_x, player.pos_y), Vec2f(player.scale_x, player.scale_y), Color::green);
  eg::drawBox(Vec2f(100, 150), Vec2f(200, 50), Color::green);
  eg::drawBox(Vec2f(100, -50), Vec2f(50, 50), Color::red);
}