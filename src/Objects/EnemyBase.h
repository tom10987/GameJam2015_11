
#pragma once
#include "../engine2d.hpp"
#include <memory>


class EnemyBase {
public:
  EnemyBase(const Vec2f&, const Vec2f&, const Vec2f&, const Color&);
  virtual ~EnemyBase() {}

  void update();
  void draw(const Vec2f&, Texture&);

  const Vec2f& getPos() const { return pos; }
  const Vec2f& getScale() const { return scale; }

  const int getGaugePower() const { return force; }
  const int getAttack() const { return attackPower; }

  void damage(const int power) { hp -= power; }
  void animeStart() { animeTime = 60; }

protected:
  Vec2f pos;
  Vec2f scale;

  Vec2f texSize;
  Color color;
  int animeTime;

  int hp;
  int attackPower;
  int force;

  const bool isDead() const { return hp <= 0; }
};


typedef std::shared_ptr<EnemyBase>  pEnemyBase;


class EnemyGround : public EnemyBase {
public:
  EnemyGround(const Vec2f& pos, const Vec2f& scale) :
    EnemyBase(pos, scale, Vec2f::Zero(), Color::white) {
    hp = 1;
    attackPower = 1;
    force = 1;
  }
};


class EnemyFlying : public EnemyBase {
public:
  EnemyFlying(const Vec2f& pos, const Vec2f& scale) :
    EnemyBase(pos, scale, Vec2f::Zero(), Color::white) {
    hp = 2;
    attackPower = 3;
    force = 2;
  }
};


class Boss : EnemyBase {
public:
  Boss(const Vec2f& pos, const Vec2f& scale) :
    EnemyBase(pos, scale, Vec2f::Zero(), Color::white) {
    hp = 19000;
    attackPower = 4;
    force = 1;
  }
};
