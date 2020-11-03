//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjModeSelect.h"
#include "GameL\WinInputs.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjModeSelect::Init()
{
	m_key_flag = false;//キーフラグ
	
}

//アクション
void CObjModeSelect::Action()
{
	
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

	for (int i = 0; i < 2; i++)
	{
		dst.m_top=32+(i*64);
		dst.m_left=32;
		dst.m_right = 256 + (i * 64)+64;
		dst.m_bottom = dst.m_top + 64;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}






	

	Font::StrDraw(L"GAME ModeSelect", 2, 2, 32, c);

	
}

