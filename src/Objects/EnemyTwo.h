
#pragma once
#include "EnemyBase.h"


class EnemyTwo : public EnemyBase{
public:
	EnemyTwo(Vec2f pos, Vec2f size) : EnemyBase(pos, size, Vec2f(3, 3), Vec2f(256, 256)
		, Color::blue
		//,Texture("res/images.png")
		){
	
	}
};