
#include "title.h"

namespace eg = engine2d;
namespace es = engine2d::scene;

//BG_WIDTH = 2048,
//BG_HEIGHT = 1024,

es::Title::Title() :
  SceneBase(SceneName::Title, SceneName::Main) {
  font = new Font("res/font.ttf");
  font->size(50);
  small_font = new Font("res/font.ttf");
  small_font->size(25);
  title_font = new Font("res/font.ttf");
  title_font->size(170);
  texture = Texture("res/title.png");
  title_angle = 0.0f;
  y = 0;

}


es::Title::~Title() {
  delete font;
  delete small_font;
}


void es::Title::update() {
  isFinish_ = env().isPushKey(KeyBind::Space);

  y = std::abs(std::sin(title_angle)) * 20.0f;
  title_angle += 0.08f;
}


void es::Title::draw() {

  drawTextureBox(-Width / 2, -Height / 2, Width, Height, 0, 0, 1430, 790,
                 texture, Color::white);

  eg::drawStringCenter("ドット勇者", Vec2f(-280, 250 + y), Color::white, *title_font);
  eg::drawStringCenter("GAME START", Vec2f(-250, 0), Color::white, *font);
  eg::drawStringCenter("[PUSH SPACE KEY]", Vec2f(-250, -45), Color::white, *small_font);
}
