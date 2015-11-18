
#include "gamePlayer.hpp"


int main() {
  using namespace engine2d;

  env();
  GamePlayer game(scene::SceneName::Title);

  while (game.isRunning()) {
    game.update();
    game.draw();
  }
}
