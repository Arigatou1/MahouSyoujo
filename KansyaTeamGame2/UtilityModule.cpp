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