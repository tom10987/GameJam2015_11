
#pragma once

class Player {
public:
	Player();
	//�����o�[�ϐ�
	int hp, atk;			//�̗́A�U����
	float pos_x, pos_y;		//���Wx, y 
	float scale_x, scale_y;	//�X�P�[��x, y
	float speed;			//�X�s�[�h
	float jumpPower;		//�W�����v��
	float gaugeBar;			//�K�E�Z�̃Q�[�W�o�[
	bool isJump;			//�W�����v�̃t���O
	bool isDeathbrow;		//�K�E�Z�̃t���O
	//�����o�[���\�b�h
	void update();
	void draw();
};
