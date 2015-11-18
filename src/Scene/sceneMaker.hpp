
#pragma once
#include "title.h"
#include "mainGame.h"
#include "result.h"
#include <functional>
#include <map>


namespace engine2d {
namespace scene {

class SceneMaker {
  typedef std::function<pScene()>     Scene;
  typedef std::map<SceneName, Scene>  SceneList;

public:
  static pScene create(const SceneName scene) {
    SceneList list = {
      { SceneName::Title,
      []() { return std::make_shared<Title>(); } },

      { SceneName::Main,
      []() { return std::make_shared<MainGame>(); } },

      { SceneName::Result,
      []() { return std::make_shared<Result>(); } },
    };

    return (list.find(scene)->second)();
  }

private:
  SceneMaker() = default;
};

}  // end scene
}  // end engine2d
