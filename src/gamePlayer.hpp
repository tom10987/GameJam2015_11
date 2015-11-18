
#pragma once
#include "engine2d.hpp"
#include "Scene/sceneManager.h"


namespace engine2d {

class GamePlayer {
public:
  GamePlayer(const scene::SceneName scene) : manager_(scene) {}

  void update() {
    manager_.update();
  }

  void draw() {
    env().begin();
    manager_.draw();
    env().end();
  }

  const inline bool isRunning() const {
    return env().isOpen() && !env().isPushKey(KeyBind::Escape);
  }

private:
  scene::SceneManager manager_;
};

}  // end engine2d
