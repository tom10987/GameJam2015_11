
#pragma once
#include "../engine2d.hpp"


class BackGround {
public:
  BackGround(const float);

  void Draw(const Vec2f&);
  const bool checkPoint(const float);

  const Vec2f& getPos() const { return pos; }
  const Vec2f& getSize() const { return texSize; }
  const int getCount() const { return checkCount; }

private:
  Texture texture;
  Vec2f texSize;

  Vec2f pos;
  int checkCount;
};
