#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�z�[�~���O�e
class CObjHomingBullet :public CObj
{
public:
	CObjHomingBullet() {};
	~CObjHomingBullet() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_bx;//�e�ۂ�X�ʒu
	float m_by;//�e�ۂ�Y�ʒu
};