#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[�����C��
class EnemyAppear :public CObj
{
public:
	EnemyAppear() {};
	~EnemyAppear() {};
	void Init();
	void Action();
	void Draw();
private:
	int EnemyAmount;
	int StageID;
	int m_time;
};