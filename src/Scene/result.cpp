﻿
#include "result.h"

namespace eg = engine2d;
namespace es = engine2d::scene;


es::Result::Result() :
  SceneBase(SceneName::Result, SceneName::Title) {
  font = new Font("res/font.ttf");
  font->size(40);
  small_font = new Font("res/font.ttf");
  small_font->size(25);
  big_font = new Font("res/font.ttf");
  big_font->size(110);
  result_angle = 0.0f;
  y = 0;
  Texture texture("res/title.png");

}


es::Result::~Result() {
  delete font;
  delete small_font;
  delete big_font;
}


void es::Result::update() {
  // キー入力

  y = std::abs(std::sin(result_angle)) * 20.0f;
  result_angle += 0.08f;
}




void es::Result::draw() {
  if (data.isGameOver) {
    //GameOver画面
    eg::drawString("GAME OVER", Vec2f(-300, 300 + y), Color::red, *big_font);

    eg::drawBox(Vec2f(Width / 4 - 120, -1), Vec2f(160, 50), Color::cyan);
    eg::drawString("タイトル", Vec2f(Width / 4 - 120, 11), Color::white, *font);
    eg::drawString("[SPACE]", Vec2f(Width / 4 - 90, -30), Color::white, *small_font);

    eg::drawBox(Vec2f(-Width / 4, -1), Vec2f(165, 50), Color::lime);
    eg::drawString("リトライ", Vec2f(-Width / 4, 11), Color::white, *font);
    eg::drawString("[ENTER]", Vec2f(-Width / 4 + 30, -30), Color::white, *small_font);
  }
  else {
    //GameClear画面
    eg::drawString("GAME CLEAR", Vec2f(-325, 300), Color::white, *big_font);
    eg::drawBox(Vec2f(Width / 3, -Height / 2 + 60), Vec2f(200, 50), Color::cyan);
    eg::drawString("タイトルへ", Vec2f(Width / 3, -Height / 2 + 70), Color::white, *font);
    eg::drawString("[SPACE]", Vec2f(Width / 3 + 20, -Height / 2 + 30), Color::white, *font);
  }
}
