
#include "Player.h"

Player::Player(){
	hp = 0;
	atk = 0;
	pos_x = 0.0f;
	pos_y = 0.0f;
	scale_x = 20.0f;
	scale_y = 50.0f;
	speed = 4.0f;
	jumpPower = 0.0f;
	gaugeBar = 0.0f;
	isJump = false;
	isDeathbrow = false;
};