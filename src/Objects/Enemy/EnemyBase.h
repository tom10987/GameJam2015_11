
#pragma once
#include "../../engine2d.hpp"
#include "../../Scene/sceneManager.h"


class EnemyBase{

protected:

	Vec2f pos;
	Vec2f size;

	Vec2f t_pos;
	Vec2f t_size;

	Color color;

	//Texture texture;

	int level;
	int attack_power;

public:
	
	EnemyBase(Vec2f pos, Vec2f size, Vec2f t_pos, Vec2f t_size, Color color);
	bool isHitPlayer;
	bool isHit;
	void update();
	void draw();
};


class Zako1 : public EnemyBase {
	Zako1(Vec2f pos, Vec2f size) : EnemyBase(pos, size, Vec2f(0, 0), Vec2f(100, 100)
		, Color::red
		//,Texture("res/***.png")
		){
	}
};


