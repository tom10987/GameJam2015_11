
#include "gamePlayer.hpp"


bool engine2d::Data::isGameOver = false;
int engine2d::Data::playerHP = 0;
int engine2d::Data::playerGauge = 0;

Texture engine2d::Sprite::block;
std::vector<Texture> engine2d::Sprite::enemy;

namespace engine2d {
extern void applicationSetup();
extern void applicationRelease();
}


int main() {
  using namespace engine2d;
  applicationSetup();

  env().bgColor(Color::gray);
  GamePlayer game(scene::SceneName::Title);

  while (game.isRunning()) {
    frameUpdate();
    game.update();
    game.draw();
  }

  applicationRelease();
}
