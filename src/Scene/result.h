
#pragma once
#include "sceneBase.hpp"


namespace engine2d {
namespace scene {


class Result : public SceneBase {
public:
	bool isGameOver;
	bool isClear;

  Result();
  ~Result();

  void update() override;
  void draw() override;

private:
	Font* font;
};


}  // end scene
}  // end engine2d
