
#pragma once
#include "../engine2d.hpp"
#include <memory>


class EnemyBase {
public:
  EnemyBase(const Vec2f&, const Vec2f&, const Vec2f&);
  virtual ~EnemyBase() {}

  void update();
  void draw(const Vec2f&, Texture&);

  const Vec2f& getPos() const { return pos; }
  const Vec2f& getScale() const { return scale; }

  const int getGaugePower() const { return force; }
  const int getAttack() const { return attackPower; }

  void damage(const int power) { hp -= power; }
  void animeStart() { animeTime = 60; }

  const bool isDead() const { return hp <= 0; }
  const int getID() const { return textureID; }

protected:
  Vec2f pos;
  Vec2f scale;

  Vec2f texSize;
  Color color;
  int animeTime;

  int hp;
  int attackPower;
  int force;
  int textureID;
};


typedef std::shared_ptr<EnemyBase>  pEnemyBase;


class EnemyGround : public EnemyBase {
public:
  EnemyGround(const Vec2f& pos) :
    EnemyBase(pos, Vec2f(96, 96), Vec2f::Ones() * 256) {
    hp = 1;
    attackPower = 1;
    force = 1;
    textureID = 0;
  }
};


class EnemyFlying : public EnemyBase {
public:
  EnemyFlying(const Vec2f& pos) :
    EnemyBase(pos, Vec2f(96, 96), Vec2f::Ones() * 256) {
    hp = 2;
    attackPower = 3;
    force = 2;
    textureID = 1;
  }
};


class Boss : public EnemyBase {
public:
  Boss(const Vec2f& pos) :
    EnemyBase(pos, Vec2f::Ones() * 1024, Vec2f::Ones() * 512) {
    hp = 30000;
    attackPower = 4;
    force = 1;
    textureID = 2;
  }
};
