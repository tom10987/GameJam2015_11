
#pragma once
#include "sceneBase.hpp"


namespace engine2d {
namespace scene {


class Title : public SceneBase {
public:
  Title();
  ~Title();

  void update() override;
  void draw() override;

private:
  Font* font;
  Font* small_font;
  Font* title_font;

  Texture texture;
  float title_angle;
  float y;
};

}  // end scene
}  // end engine2d
