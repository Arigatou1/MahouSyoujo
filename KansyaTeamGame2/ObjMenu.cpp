//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjMenu.h"
#include "GameL\WinInputs.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMenu::Init()
{
	m_key_flag = false;//キーフラグ
	cursor_x = 272;
	cursor_y = 16;
}

//アクション
void CObjMenu::Action()
{
	if (Input::GetVKey(VK_UP) == true)
	{
		if (m_key_flag == true)
		{
			cursor_y -= 80;
			m_key_flag = false;
		}
	}
	else if (Input::GetVKey(VK_DOWN) == true )
	{
		if (m_key_flag == true)
		{
			cursor_y += 80;

			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjMenu::Draw()
{
	float c[4] = { 1.0f,0.0f,0.0f,1.0f };

	

	//描画カラー情報


	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	for (int i = 0; i < 5; i++)
	{
		//表示位置の設定
		dst.m_top =(i*16.0f)+ i * 64.0f+16.0f;
		dst.m_left =272.0f;
		dst.m_right = dst.m_left + 256.0f;
		dst.m_bottom = dst.m_top + 64.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}





	c[1] = 1.0f;
		//表示位置の設定
		dst.m_top = cursor_y+0.0f;
		dst.m_left = cursor_x+0.0f;
		dst.m_right = dst.m_left + 256.0f;
		dst.m_bottom = dst.m_top + 64.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	
	Draw::Draw(0, &src, &dst, c, 0.0f);


	//描画

	c[2] = 1.0f;
	c[1] = 1.0f;
	Font::StrDraw(L"GAME Menu", 2, 2, 32, c);


}