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
	//int EneAmo();
private:
	float m_ex;
	float m_ey;
	float m_vx;
	float m_vy;

	float m_mx;//�}�i��X�ʒu
	float m_my;//�}�i��Y�ʒu

	//int Amount;
};
