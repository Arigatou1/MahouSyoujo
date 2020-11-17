#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�{�X
class CObjBoss : public CObj
{
public:
	CObjBoss(float x, float y);
	~CObjBoss() {};
	void Init();
	void Action();
	void Draw();
	float GetE1_ATK();
private:
	float m_ex;
	float m_ey;
	float m_vx;
	float m_vy;
	int e_hp;//�G��HP
	int e1_damege;//�_���[�W��
	int e1_time;//�G�̍U���Ԋu

	float e1_atk;//�G�̍U����

	float b_mx;//�o���A��x�ʒu
	float b_my;//�o���A��y�ʒu

	float m_mx;//�}�i��X�ʒu
	float m_my;//�}�i��Y�ʒu
	

	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool e1_hit_up;
	bool e1_hit_down;
	bool e1_hit_left;
	bool e1_hit_right;

	float e1_xsize;
	float e1_ysize;
};
