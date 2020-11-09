#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�G�@
class CObjEnemy : public CObj
{
public:
	CObjEnemy(float x,float y);
	~CObjEnemy() {};
	void Init();
	void Action();
	void Draw();
//	int EneAmo();
private:
	float m_ex;
	float m_ey;
	float m_vx;
	float m_vy;
	int e_hp;//�G��HP
	int e_damege;//�_���[�W��

	float b_mx;//�o���A��x�ʒu
	float b_my;//�o���A��y�ʒu

	float m_mx;//�}�i��X�ʒu
	float m_my;//�}�i��Y�ʒu
	//int Amount;
	
	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool e1_hit_up;
	bool e1_hit_down;
	bool e1_hit_left;
	bool e1_hit_right;

	float e1_xsize;
	float e1_ysize;
};
