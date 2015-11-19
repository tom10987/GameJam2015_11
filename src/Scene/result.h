
#pragma once
#include "sceneBase.hpp"


namespace engine2d {
namespace scene {

	
class Result : public SceneBase {
public:
	float result_angle;
	float x;
	float y;
	
  Texture clear;
  Texture gameover;

  Result();
  ~Result();

  void update() override;
  void draw() override;
 
private:
	Font* font;
	Font* small_font;
	Font* big_font;

	Vec2f gameover_scale;
	Vec2f Clear_scale;

	Vec2f gameover_size;
	Vec2f clear_size;

  Data data;
};


}  // end scene
}  // end engine2d
