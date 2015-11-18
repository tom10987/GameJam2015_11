
#pragma once
#include "EnemyBase.h"

class EnemyBase;

class EnemyOne : public EnemyBase
{
public:

	EnemyOne(Vec2f pos, Vec2f size) : EnemyBase(pos, size, Vec2f(-3, -3), Vec2f(256, 256)
		, Color::red
		//,Texture("res/***.png")
		){
	}
};
