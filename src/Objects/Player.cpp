
#include "Player.h"

namespace eg = engine2d;


Player::Player() :
dot("res/HeroDot256.png"),
real("res/HeroRun256.png"),
pos(BG_WIDTH / 2, BG_HEIGHT / 2),
dot_scale(96, 96),
real_scale(128, 128),
  texSize(256, 256),
  animeTime(0),
  hp(10),
  attack(1),
  isJump(false),
  jumpPower(0.0f),
  gauge(0) {
	countTimer = 0.0f;
	isInvincible = true;
};

void Player::Invincible()
{
	isInvincible = true;
	hp = 10;
	attack = 9999;
	countTimer = 60.0f * gauge;
	gauge = 0;
}

void Player::cancelInvincible()
{
	isInvincible = false;
	attack = 1;
}

void Player::move(const float deltaTime) {
  pos.x() += deltaTime;
}


void Player::jump() {
  const auto space = eg::KeyBind::Space;
  const auto push = eg::env().isPushKey(space);

  // ジャンプしてないときにキーを押したらジャンプする
  if (!push || isJump) { return; }
  isJump = true;
  jumpPower = 30.0f;
}


// 重力をかける処理
void Player::gravity() {
  // ジャンプしてなければ重力をかけない
  if (!isJump) { return; }

  pos.y() += jumpPower;
  jumpPower -= 1.0f;
}


// 足場に着地したときの処理
// 足場との当たり判定をとり、足場の高さを引数に渡す
void Player::landing(const float ground) {
  pos.y() = ground;
  setJumpState(false);
}


// ふっとばされた時の処理
void Player::translate(const Vec2f& distance) {
  pos += distance;
}


void Player::setJumpState(const bool jump) {
  isJump = jump;
  jumpPower = 0.0f;
}


void Player::Draw(const Vec2f& camera) {
	++animeTime;

	// TIPS: カメラと自分の相対座標を求める
	const Vec2f DrawPos = pos - camera;

  if (isInvincible == false){
	  const auto blink = (animeTime / 10) % 2;

	  drawTextureBox(DrawPos.x(), DrawPos.y(), dot_scale.x(), dot_scale.y(),
		  blink * texSize.x(), 0, texSize.x(), texSize.y(),
		  dot, Color::white,
		  0.0f, Vec2f::Ones(), Vec2f(dot_scale.x() * 0.5f, 0));
  }
  else{
	  const auto blink = (animeTime / 5) % 3;

	  drawTextureBox(DrawPos.x(), DrawPos.y(), real_scale.x(), real_scale.y(),
		  blink * texSize.x(), 0, texSize.x(), texSize.y(),
		  real, Color::white,
		  0.0f, Vec2f::Ones(), Vec2f(real_scale.x() * 0.5f, 0));
  }
}
