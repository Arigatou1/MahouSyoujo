//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjGameClear.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameClear::Init()
{
	Score = 0;
}

//アクション
void CObjGameClear::Action()
{
	CObjGaugeHP* obj = (CObjGaugeHP*)Objs::GetObj(OBJ_GAUGEHP);

	Score = obj->GetPercent();
}

//ドロー
void CObjGameClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"GAME CLEAR", 200, 200, 96, c);

	wchar_t str[128];
	swprintf_s(str, L"スコア:%d", Score);//整数を文字列か
	Font::StrDraw(str, 300, 2, 24, c);

}