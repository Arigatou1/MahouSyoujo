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
	StageID = 0;
}

//アクション
void CObjMenu::Action()
{
	//ステージ選択画面
	//今いるカーソルの場所から位置を取得し、
	//ステージIDを計算し設定するには？？

	StageID = ((cursor_y - 16) / 80)+1;

	//cursor_y = 16,96,176,256,336,416,496
	//カーソルの初期位置は16なので、
	//96から16を引き、80を出し、80で割ることで1が出てくる。
	//それに1を足す。

	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else if (Input::GetVKey(VK_UP) == true)
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

	//カーソルが画面外いかない処理
	if (cursor_y < 16)
		cursor_y = 16;

	if (cursor_y > 496)
		cursor_y = 496;

	

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
		dst.m_top = (i * 16.0f) + i * 64.0f + 16.0f;
		dst.m_left = 272.0f;
		dst.m_right = dst.m_left + 256.0f;
		dst.m_bottom = dst.m_top + 64.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}





	c[1] = 0.8f;
	//表示位置の設定
	dst.m_top = cursor_y + 0.0f;
	dst.m_left = cursor_x + 0.0f;
	dst.m_right = dst.m_left + 256.0f;
	dst.m_bottom = dst.m_top + 64.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	Draw::Draw(0, &src, &dst, c, 0.0f);


	//描画

	c[2] = 1.0f;
	c[1] = 1.0f;
	Font::StrDraw(L"GAME Menu", 2, 2, 32, c);

	for (int i = 0; i < 4; i++)
	{
		wchar_t str[128];
		swprintf_s(str,L"ステージ%d",i+1);

		Font::StrDraw(str, 284, 24+(i*80), 48, c);
	}
}

int CObjMenu::GetStageID()
{
	return StageID;
}