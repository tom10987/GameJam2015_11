
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

}  // end engine2d
