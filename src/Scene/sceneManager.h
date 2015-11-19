
#pragma once
#include "sceneBase.hpp"
#include "screenFilter.h"


namespace engine2d {
namespace scene {


class SceneManager {
public:
  SceneManager(const SceneName scene);

  void update();
  void draw();

private:
  pScene scene_;
  SceneName next_;

  Wipe wipe;

  void SceneChange();
};


}  // end scene
}  // end engine2d
