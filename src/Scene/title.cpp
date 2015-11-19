﻿
#include "title.h"

namespace eg = engine2d;
namespace es = engine2d::scene;


es::Title::Title() :
  SceneBase(SceneName::Title, SceneName::Main) {
  font = new Font("res/font.ttf");
  font->size(40);
}


es::Title::~Title() {
  delete font;
}


void es::Title::update() {
  isFinish_ = env().isPushKey(KeyBind::Space);
}


void es::Title::draw() {
  eg::drawCircle(Vec2f::Zero(),
                 Vec2f::Ones() * 20.0f, 20, Color::white);

  eg::drawStringCenter("Title", Vec2f(0, 100), Color::white, *font);
}
