#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G�R
class CObjEnemy3 :public CObj
{
public:
	CObjEnemy3(float x, float y);
	~CObjEnemy3() {};
	void Init();
	void Action();
	void Draw();

	float GetX() { return m_ex; };
	float GetY() { return m_ey; };
	float GetVX() { return m_vx; }
	float GetVY() { return m_vy; }
	

	void SetX(float x) { m_ex = x; }
	void SetY(float y) { m_ey = y; }
	void SetVY(float vy) { m_vy=vy; }
	void SetVX(float vx) { m_vx = vx; }

	void SetUp(bool eb) { hit_up; }
	void SetDown(bool eb) { hit_down; }
	void SetLeft(bool eb) { hit_left; }
	void SetRight(bool eb) { hit_right; }

private:
	float m_ex;		//X���W
	float m_ey;		//Y���W
	float m_vx;		//�ړ��x�N�g��
	float m_vy;

	float m_mx; //�}�i�̍��W
	float m_my;

	bool jump;
	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool hit_up;
	bool hit_down;
	bool hit_left;
	bool hit_right;
};
