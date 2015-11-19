
#include "Camera.h"
#include "Player.h"


Camera::Camera(const Vec2f& inf, const Vec2f& sup) :
  pos(0, 0) {
  using namespace engine2d;
  const auto window = Vec2f(Width, Height) * 0.5f;
  areaInf = inf + window;
  areaSup = sup - window;
}


void Camera::Update(const Player* player) {
  const auto delta = player->getPos() - pos;
  const float deltaRatio = 0.1f;

  pos += delta * deltaRatio;

  //pos.x() = std::max(pos.x(), areaInf.x());
  //pos.x() = std::min(pos.x(), areaSup.x());

  pos.y() = std::max(pos.y(), areaInf.y());
  pos.y() = std::min(pos.y(), areaSup.y());
}
