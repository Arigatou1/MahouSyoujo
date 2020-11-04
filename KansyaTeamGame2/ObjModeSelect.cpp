//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjModeSelect.h"
#include "GameL\WinInputs.h"
#include "ObjMenuBlock.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjModeSelect::Init()
{
	m_key_flag = false;//キーフラグ
	cursor_x = 40;
	cursor_y = 96;
	nowSelect = 0;
}

//アクション
void CObjModeSelect::Action()
{
	//モード選択画面
	//今いるカーソルの場所から位置を取得し、
	//モード設定する

	nowSelect = ((cursor_x - 40) / 400) ;

	//cursor_x = 40,440
	//カーソルの初期位置は40なので、
	//440から40を引き、400を出し、400で割ることで1が出てくる。
	

	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			if (nowSelect == 0)
			{
				this->SetStatus(false);
				//メニューオブジェクト作成
				CObjStageSelect* obj = new CObjStageSelect();
				Objs::InsertObj(obj, OBJ_STAGESELECT, 0);
			}
			
			m_key_flag = false;
		}
	}
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		if (m_key_flag == true)
		{
			cursor_x += 400;
			m_key_flag = false;
		}
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		if (m_key_flag == true)
		{
			cursor_x -= 400;
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}

	//カーソルが画面買い行かない処理
	if (cursor_x > 440)
	{
		cursor_x = 440;
	}
	else if (cursor_x < 40)
	{
		cursor_x = 40;
	}
}

//ドロー
void CObjModeSelect::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	//描画カラー情報

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

/*	for (int i = 0; i < 2; i++)
	{
		c[1] = 0.0f;
		c[2] = 0.0f;
		dst.m_top = 96;
		dst.m_left=40 + (i * 400);
		dst.m_right =dst.m_left+320;
		dst.m_bottom = dst.m_top + 256;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	c[2] = 1.0f;
	c[0] = 0.5f;
	dst.m_top = 450;
	dst.m_left = 200;
	dst.m_right = dst.m_left + 400;
	dst.m_bottom = dst.m_top + 72;

	Draw::Draw(0, &src, &dst, c, 0.0f);
	*/
	//カーソル描画

	MenuBlockDraw(0, 0, 64, 64,1,1,1,1);

	c[0] = 1.0f;
	c[1] = 0.8f;
	c[2] = 0.0f;

	dst.m_top = cursor_y;
	dst.m_left = cursor_x;
	dst.m_right = dst.m_left + 320;
	dst.m_bottom = dst.m_top + 256;
	
	Draw::Draw(0, &src, &dst, c, 0.0f);

	c[0] = 1.0f;
	c[1] = 1.0f;
	c[2] = 1.0f;
	Font::StrDraw(L"GAME ModeSelect", 2, 2, 32, c);

	Font::StrDraw(L"ステージセレクト", 72, 200, 32, c);

	Font::StrDraw(L"エンドレスモード", 472, 200, 32, c);
}

//MenuBlockDraw関数
