#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G�R
class CObjEnemy3 :public CObj
{
public :
	CObjEnemy3(float x,float y);
	~CObjEnemy3() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_ex;		//X���W
	float m_ey;		//Y���W
	float m_vx;		//�ړ��x�N�g��
	float m_vy;		
	float m_posture;

	bool isjump;//�W�����v
};
