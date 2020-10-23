#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"

#include"GameHead.h"
#include"Objstage.h"

using namespace GameL;

//イニシャライズ
void CObjstage::Init()
{
	//マップ情報
	int block_data[10][10] =
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
	};
	//
	memcpy(m_b, block_data, sizeof(int) * (10 * 10));
}

void CObjstage::Action()
{

}

//ドロー
void CObjstage::Draw()
{
	//
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	RECT_F src;
	RECT_F dst;

	
	//背景表示
	src.m_top = 256.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 521.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 0.0f;
	dst.m_bottom = 620.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);
		

	//切り取り位置の設定(ブロック)
	src.m_top = 192.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0;
	src.m_bottom = 246.0f;

	

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (m_b[i][j] > 0)
			{	
				//表示位置の設定
				dst.m_top =300.0f*i;
				dst.m_left = 300.0f*j;
				dst.m_right = 400.0f ;
				dst.m_bottom = 400.0f  ;

				//描画
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
		}
	}
}