
#pragma once
#include "../engine2d.hpp"
#include <memory>


class EnemyBase {
public:
  EnemyBase(const Vec2f&, const Vec2f&, const Vec2f&, const Color&);
  virtual ~EnemyBase() {}

  void update();
  void draw();

  const Vec2f& getPos() const { return pos; }
  const Vec2f& getScale() const { return scale; }

  const int getLevel() const { return level; }
  const int getAttack() const { return attackPower; }

protected:
  Vec2f pos;
  Vec2f scale;

  Vec2f textureSize;

  //Texture texture;
  Color color;

  int level;
  int attackPower;
};


typedef std::shared_ptr<EnemyBase>  pEnemyBase;


class Enemy1 : public EnemyBase {
public:
  Enemy1(const Vec2f& pos, const Vec2f& scale) :
    EnemyBase(pos, scale, Vec2f::Zero(), Color::red) {
  }
};


class Enemy2 : public EnemyBase {
public:
  Enemy2(const Vec2f& pos, const Vec2f& scale) :
    EnemyBase(pos, scale, Vec2f::Zero(), Color::blue) {
  }
};
