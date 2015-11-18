
#pragma once
#include "sceneBase.hpp"


namespace engine2d {
namespace scene {


class Result : public SceneBase {
public:
  Result();

  void update() override;
  void draw() override;

private:
};


}  // end scene
}  // end engine2d
