
#pragma once
#include "../engine2d.hpp"


class Player;

class Camera {
public:
  Camera(const Vec2f&, const Vec2f&);

  void Update(const Player*);
  const Vec2f& getPos() const { return pos; }

private:
  Vec2f pos;
  Vec2f areaInf;
  Vec2f areaSup;
};
