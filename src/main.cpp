
#include "gamePlayer.hpp"


bool engine2d::Data::isGameOver = false;
int engine2d::Data::playerHP = 0;
int engine2d::Data::playerAttack = 0;

Texture engine2d::Sprite::block;
Texture engine2d::Sprite::enemy;
Texture engine2d::Sprite::boss;


int main() {
  using namespace engine2d;

  env().bgColor(Color::gray);
  GamePlayer game(scene::SceneName::Title);

  while (game.isRunning()) {
    frameUpdate();
    game.update();
    game.draw();
  }
}
