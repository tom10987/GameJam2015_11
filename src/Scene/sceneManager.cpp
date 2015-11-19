
#include "sceneManager.h"
#include "sceneMaker.hpp"

namespace es = engine2d::scene;


es::SceneManager::SceneManager(const SceneName scene) :
  scene_(SceneMaker::create(scene)),
  next_(SceneName::None),
  wipe(40.0f) {
}


void es::SceneManager::update() {
  wipe.update();
  if (wipe.isFinish()) { SceneChange(); }
  if (wipe.isFadeActive()) { return; }

  scene_->update();
  if (scene_->isFinish()) { wipe.SequenceStart(); }
}


void es::SceneManager::draw() {
  scene_->draw();
  wipe.draw();
}


void es::SceneManager::SceneChange() {
  scene_ = SceneMaker::create(scene_->getNextScene());
  wipe.SequenceReset();
}
