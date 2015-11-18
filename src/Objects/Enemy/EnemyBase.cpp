
#include "EnemyBase.h"


EnemyBase::EnemyBase(Vec2f pos0, Vec2f size0, Vec2f t_pos0, Vec2f t_size0, Color color0){
	pos = pos0;
	size = size0;

	t_pos = t_pos0;
	t_size = t_size0;
	color = color0;

	level = 1;
	attack_power = 1;
	isHit = false;

}

bool isHitPlayer(Vec2f pos, Vec2f size/*,player‚Ìpos,player‚Ìsize*/,bool isHit)
{//player
	/*
	if (player.pos.x + player.size.x >= enemy.pos.x && 
	    player.pos.x <= enemy.pos.x + enemy.size.x &&
		player.pos.y + player.size.y >= enemy.pos.y &&
		player.pos.y <= enemy.pos.y + enemy.size.y)
		{
		isHit = true;
		}
	*/
	return isHit = false;;
}



void EnemyBase::update(){}

void EnemyBase::draw(){
	
	drawFillCircle(pos.x(), pos.y(), size.x(),size.y(),10, color);

	
	
}