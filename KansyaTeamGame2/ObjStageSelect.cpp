//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "ObjMenuBlock.h"
#include "GameHead.h"
#include "ObjStageSelect.h"
#include "GameL\WinInputs.h"
#include "GameL\UserData.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjStageSelect::Init()
{
	m_key_flag = false;//キーフラグ
	cursor_x = 140;
	cursor_y = 32;
	StageID = 0;
	PageID = 0;
	MaxPage = 4;
}

//アクション
void CObjStageSelect::Action()
{
	//ステージ選択画面
	//今いるカーソルの場所から位置を取得し、
	//ステージIDを計算し設定するには？？

	((UserData*)Save::GetData())->Stage = ((cursor_y - 32) / 144)+1 +(PageID*4);

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
			cursor_y -= 144;
			m_key_flag = false;
		}
	}
	else if (Input::GetVKey(VK_DOWN) == true )
	{
		if (m_key_flag == true)
		{
			cursor_y += 144;
			m_key_flag = false;
		}
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		if (m_key_flag == true)
		{
			if (PageID > 0)
				PageID -= 1;
			m_key_flag = false;
		}
	}

	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		if (m_key_flag == true)
		{
			if (PageID < MaxPage )
				PageID += 1;

			m_key_flag = false;
		}
	}

	else
	{
		m_key_flag = true;
	}

	//カーソルが画面外いかない処理
	if (cursor_y < 32)
		cursor_y = 32;

	if (cursor_y > 464)
		cursor_y = 464;

	

}

//ドロー
void CObjStageSelect::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };



	
	
	//ステージセレクト
	for (int i = 0; i < 4; i++)
	{
		MenuBlockDraw(140, i * 144.0f + 32.0f, 512, 128, 1, 0, 0, 1);
		
	}


	MenuBlockDraw(cursor_x, cursor_y, 512, 128, 1, 0.8f, 0, 1);


	for (int i = 0; i < 2; i++)
		MenuBlockDraw(16 + i * 674, 200, 96, 200, 0, 0, 1, 1);
	/*
	
	
	{
		c[2] = 1.0f;
		c[1] = 0.0f;
		c[0] = 0.0f;
		//表示位置の設定
		dst.m_top = 200 + 0.0f;
		dst.m_left = 16.0f + i*674.0f;
		dst.m_right = dst.m_left + 96.0f;
		dst.m_bottom = dst.m_top + 200.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}

	//描画
	*/
	
	Font::StrDraw(L"GAME StageSelect", 2, 2, 32, c);
	
	for (int i = 0; i < 4; i++)
	{
		wchar_t str[128];
		swprintf_s(str,L"ステージ%d",i+1+ (PageID * 4));

		Font::StrDraw(str, 176, 48+(i*144), 96, c);
	}

	Font::StrDraw(L"←", 40, 284, 48, c);

	Font::StrDraw(L"→", 712, 284, 48, c);
}

int CObjStageSelect::GetStageID()
{
	return StageID;
}