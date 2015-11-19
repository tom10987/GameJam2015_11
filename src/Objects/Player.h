
#pragma once
#include "Camera.h"


class Player {
public:
	Player();

	void Draw(const Vec2f&);

	//------------------------------------------------------------
	// 他のオブジェクトとの判定用

	const Vec2f& getPos() const { return pos; }
	const Vec2f& getScale() const { return scale; }

	//------------------------------------------------------------
	// プレイヤー更新の機能

	void move(const float);
	void jump();
	void gravity();
	void landing(const float);

	void translate(const Vec2f&);

	const bool isJumping() const { return isJump; }
	void setJumpState(const bool jump = true);

	//------------------------------------------------------------
	// 必殺技とか攻撃力とか

	const bool IsGaugeMax() const { return gauge >= gaugeMax; }

	int& HP() { return hp; }
	int& Attack() { return attack; }
	int& Gauge() { return gauge; }

	//------------------------------------------------------------

private:
	Vec2f pos;
	Vec2f scale;

	Texture texture;
	Vec2f texSize;
	int animeTime;

	int hp;
	int attack;

	float jumpPower;
	bool isJump;

	int gauge;
	int gaugeMax = 5;
};
