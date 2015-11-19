
#pragma once
#include "Camera.h"


class Player {
public:
  Player();

  void Draw(const Vec2f&);

  //------------------------------------------------------------
  // 他のオブジェクトとの判定用

  const Vec2f& getPos() const { return pos; }
  const Vec2f& getDotScale() const { return dot_scale; }
  const Vec2f& getRealScale() const { return real_scale; }

  //------------------------------------------------------------
  // プレイヤー更新の機能

  void move(const float);
  void jump();
  void gravity();
  void landing(const float);

  void translate(const Vec2f&);

  const bool isJumping() const { return isJump; }
  void setJumpState(const bool jump = true);
  void resetJumpPower() { jumpPower = 0.0f; }

  //------------------------------------------------------------
  // 必殺技とか攻撃力とか

  const bool IsGaugeMax() const { return countTimer >= (60.0f * 5.0f); }

  int& HP() { return hp; }
  int& Attack() { return attack; }
  //int& Gauge() { return gauge; }

  //------------------------------------------------------------
  // 必殺技の内容

  bool isInvincible = false;
  float countTimer;

  void Invincible();
  void cancelInvincible();

private:
  Vec2f pos;
  Vec2f dot_scale;
  Vec2f real_scale;

  Texture dot;
  Texture real;

  Vec2f texSize;
  int animeTime;

  int hp;
  int attack;

  float jumpPower;
  bool isJump;
};
