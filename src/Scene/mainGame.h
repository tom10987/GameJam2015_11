
#pragma once
#include "sceneBase.hpp"
#include "../Objects/Player.h"


namespace engine2d {
namespace scene {


class MainGame : public SceneBase {
public:
  MainGame();

  void update() override;
  void draw() override;

private:
	Player player;
};


}  // end scene
}  // end engine2d
