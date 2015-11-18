
#include "sceneManager.h"
#include "sceneMaker.hpp"

namespace es = engine2d::scene;


es::SceneManager::SceneManager(const SceneName scene) :
scene_(SceneMaker::create(scene)),
next_(SceneName::None),
prev_(SceneName::None) {
}


void es::SceneManager::update() {
  //if (scene_->isFinish()) { return; }
  scene_->update();
  if (scene_->isFinish()) { scene_ = SceneMaker::create(scene_->getNextScene()); }
}


void es::SceneManager::draw() {
  scene_->draw();
  // TODO: 画面切り替え演出
  if (isSceneChange()) {}
}


bool es::SceneManager::isSceneChange() {
  return false;
}
