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

	void BlockHit(float* x, float* y,
		bool* up, bool* down, bool* left, bool* right,
		float* vx, float* vy,float* x_size, float* y_size);
private:
	//マップ用変数。m_map[立幅][横幅];
	int m_map[10][13];

	void BlockDraw(float x, float y, RECT_F* dst, float c[]);

	float ex;
	float ey;

	//float Dot(float ax, float ay, float bx, float by); //内積
	//float Cross(float ax, float ay, float bx, float by);//外積

	//線と線との交差判定
	//bool CObjBlock::LineCrossPoint(
	//	float a1x, float a1y, float a2x, float a2y,
	//	float b1x, float b1y, float b2x, float b2y,
	//	float* out_px, float* out_py);
};