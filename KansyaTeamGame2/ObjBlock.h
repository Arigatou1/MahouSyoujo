#pragma once

#include"GameL/SceneObjManager.h"
#include "GameL\DrawTexture.h"
using namespace GameL;


class CObjBlock :public CObj
{
public :
	CObjBlock(){};
	~CObjBlock() {};
	void Init() ;
	void Action();
	void Draw();
private:
	//�}�b�v�p�ϐ��Bm_map[����][����];
	int m_map[10][12];

	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
};