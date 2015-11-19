
#pragma once
#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/random.hpp"
#include "Utility/constants.hpp"


namespace engine2d {

extern AppEnv& env();
extern Random& random();

extern void frameUpdate();
extern const double getElapsedTime();

class Data {
public:
  static bool isGameOver;

  static int playerHP;
  static int playerAttack;
};

class Sprite {
public:
  static Texture block;
  static Texture enemy;
  static Texture boss;
};

}  // end engine2d
