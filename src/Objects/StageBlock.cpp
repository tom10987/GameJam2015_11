
#include "StageBlock.h"


StageBlock::StageBlock(const Vec2f& pos) :
  pos(pos),
  scale(96, 96),
  texSize(128, 128) {
}


void StageBlock::draw(const Vec2f& camera, Texture& texture) {
  // TIPS: カメラと自分の相対座標を求める
  const Vec2f DrawPos = pos - camera;

  drawTextureBox(DrawPos.x(), DrawPos.y(), scale.x(), scale.y(),
                 0, 0, texSize.x(), texSize.y(),
                 texture, Color::white);
}
