#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G�R
class CObjEnemy4 :public CObj
{
public:
	CObjEnemy4() {};
	~CObjEnemy4() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_ex;//X���W
	float m_ey;//Y���W
	float m_vx;//�ړ��x�N�g��	
	float m_vy;

	float m_mx;//�}�i��X�ʒu
	float m_my;//�}�i��Y�ʒu
	//int Amount;
};