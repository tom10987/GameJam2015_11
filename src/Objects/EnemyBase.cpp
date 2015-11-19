
#include "EnemyBase.h"


EnemyBase::EnemyBase(const Vec2f& pos,
                     const Vec2f& scale,
                     const Vec2f& textureSize) :
  pos(pos),
  scale(scale),
  texSize(textureSize) {
}


void EnemyBase::update() {
}


void EnemyBase::draw(const Vec2f& camera, Texture& texture) {
  if (animeTime > 0) { --animeTime; }
  color = Color(1, 1, 1, 1 - (animeTime / 10) % 2);

  // TIPS: カメラと自分の相対座標を求める
  const Vec2f DrawPos = pos - camera;

  drawTextureBox(DrawPos.x(), DrawPos.y(), scale.x(), scale.y(),
                 texSize.x(), 0, texSize.x(), texSize.y(),
                 texture, color,
                 0.0f, Vec2f::Ones(), Vec2f(scale.x() * 0.5f, 0));
}
