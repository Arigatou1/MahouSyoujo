#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�}�i
class CObjGaugeMANAHP :public CObj
{
public:
	CObjGaugeMANAHP() {};
	~CObjGaugeMANAHP() {};
	void Init();
	void Action();
	void Draw();
private:
	float MANAHP;
	
	float GaugePercent;

	float Manag_x;
	float Manag_y;
};

