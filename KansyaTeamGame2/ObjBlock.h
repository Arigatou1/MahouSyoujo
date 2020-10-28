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
	//マップ用変数。m_map[立幅][横幅];
	int m_map[10][13];

	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
};
	int m_b[10][10];//マップ情報
};
