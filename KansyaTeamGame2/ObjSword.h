#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "ObjHero.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�\�[�h
class CObjSword :public CObj
{
public:
	CObjSword(float x,float y,int posture) ;
	~CObjSword() {};
	void Init();
	void Action();
	void Draw();
private:
	float a_px;
	float a_py;
	int a_posture;
	bool m_f;
	int atk_time;
};

