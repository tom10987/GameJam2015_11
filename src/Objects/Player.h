
#pragma once

class Player {
public:
	Player();
	//メンバー変数
	int hp, atk;			//体力、攻撃力
	float pos_x, pos_y;		//座標x, y 
	float scale_x, scale_y;	//スケールx, y
	float speed;			//スピード
	float jumpPower;		//ジャンプ力
	float gaugeBar;			//必殺技のゲージバー
	bool isJump;			//ジャンプのフラグ
	bool isDeathbrow;		//必殺技のフラグ
	//メンバーメソッド
  void update() {}
  void draw() {}
};
