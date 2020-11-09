#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
//MenuBlockDraw関数
//表示位置dstの値を受け取って、描画だけできるようにしたい。
void MenuBlockDraw(float x, float y, float width, float height, float r, float g, float b, float a)
{
	float c[4] = { r,g,b,a };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0;
	src.m_left = 0;
	src.m_right = 64;
	src.m_bottom = 64;

	dst.m_top = y;
	dst.m_left = x;
	dst.m_right = dst.m_left + width;
	dst.m_bottom = dst.m_top + height;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}
//重力
// v = gt  v = v0 + gt
// v速度 g重力 t時間 v0初速度
bool Gravity(float *v0)
{
	float g = 9.8f;
	float v = 0.0f;
	float t_time = 0;
	float t = 0;

	t_time++;

	t = t_time / 60;

	if (*v0 == 0)
	{
		v = g;
	}
	else
	{
		v = *v0 + (g * t);
	}

	return v;
}