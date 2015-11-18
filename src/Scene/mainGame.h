
#pragma once
#include "sceneBase.hpp"


namespace engine2d {
namespace scene {


class MainGame : public SceneBase {
public:
  MainGame();

  void update() override;
  void draw() override;

private:
};


}  // end scene
}  // end engine2d
