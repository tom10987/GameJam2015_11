
#include "result.h"

namespace eg = engine2d;
namespace es = engine2d::scene;


es::Result::Result() :
  SceneBase(SceneName::Result, SceneName::Title) {
	isGameOver = false;
	isClear = false;
	font = new Font("res/meiryo.ttc");
	font->size(40);
}


es::Result::~Result(){
	delete font;
}


void es::Result::update() {
  /*isFinish_ = env().isPushKey(GLFW_KEY_UP);
  isFinish_ = env().isPushKey(GLFW_KEY_DOWN);*/
  isFinish_ = env().isPushKey(KeyBind::Escape);
}


void es::Result::draw() {
	//GameOver画面
	//eg::drawString("GAME OVER", Vec2f(-120, 200), Color::white, *font);
	//eg::drawBox(Vec2f(-100, 50), Vec2f(200, 50), Color::cyan);
	//eg::drawString("タイトル", Vec2f(-80, 62), Color::white, *font);
	//eg::drawBox(Vec2f(-100, -50), Vec2f(200, 50), Color::lime);
	//eg::drawString("リトライ", Vec2f(-80, -40), Color::white, *font);
	//GameClear画面
	eg::drawString("Game Clear", Vec2f(-120, 200), Color::white, *font);
	eg::drawBox(Vec2f(-100, 50), Vec2f(200, 50), Color::cyan);
	eg::drawString("タイトル", Vec2f(-80, 62), Color::white, *font);

}
 