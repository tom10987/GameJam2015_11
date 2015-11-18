
#include "EnemyBase.h"


EnemyBase::EnemyBase(const Vec2f& pos,
                     const Vec2f& scale,
                     const Vec2f& textureSize,
                     const Color& color) :
  pos(pos),
  scale(scale),
  textureSize(textureSize),
  color(color) {
}


void EnemyBase::update() {
}


void EnemyBase::draw() {
  drawFillBox(pos.x(), pos.y(), scale.x(), scale.y(), color);
}
