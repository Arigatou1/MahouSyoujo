#pragma once

#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"

using namespace GameL;


class CObjBlock :public CObj
{
public :
	CObjBlock(int map[10][13]);
	~CObjBlock() {};
	void Init() ;
	void Action();
	void Draw();
private:
	//}bvpÏBm_map[§][Ħ];
	int m_map[10][13];

	void BlockDraw(float x, float y, RECT_F* dst, float c[]);

	float ex;
	float ey;
};
