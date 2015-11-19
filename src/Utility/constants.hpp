
#pragma once
#include "../engine2d.hpp"


namespace engine2d {


enum WindowSize {
  Width = 1440,
  Height = 810,
};


enum KeyBind {
  Escape = GLFW_KEY_ESCAPE,
  Enter = GLFW_KEY_ENTER,
  Space = GLFW_KEY_SPACE,

  Up = GLFW_KEY_UP,
  Down = GLFW_KEY_DOWN,
};


}  // end engine2d


enum ParameterSize {
  StageGround = 90,
};


enum TextureSize {
  HeroDot = 32,
};


enum BackGroundSize {
  BG_WIDTH = 2048,
  BG_HEIGHT = 1024,
};
