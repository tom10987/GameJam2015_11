
#pragma once
#include "sceneBase.hpp"


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
  SceneName prev_;

  bool isSceneChange();
};


}  // end scene
}  // end engine2d
