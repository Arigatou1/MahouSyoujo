//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjMenu.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMenu::Init()
{
	m_key_flag = false;//キーフラグ
}

//アクション
void CObjMenu::Action()
{
	//エンターキーを押してシーン:ゲームTitleに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{

	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjMenu::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"GAME Menu", 200, 200, 96, c);

}