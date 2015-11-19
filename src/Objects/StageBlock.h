
#pragma once
#include "../engine2d.hpp"


class StageBlock {
public:
  StageBlock(const Vec2f&);

  void draw(const Vec2f&, Texture&);
  const Vec2f& getPos() const { return pos; }
  const Vec2f& getSize() const { return scale; }

private:
  Vec2f pos;
  Vec2f scale;
  Vec2f texSize;
};
