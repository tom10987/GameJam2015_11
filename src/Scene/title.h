
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
};


}  // end scene
}  // end engine2d
