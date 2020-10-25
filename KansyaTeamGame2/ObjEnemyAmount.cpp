//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjEnemyAmount.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjEnemyAmount::Init()
{
	EnemyAmount = 2;
}

//アクション
void CObjEnemyAmount::Action()
{
	
}

//ドロー
void CObjEnemyAmount::Draw()
{
	float c[4] = { 0.0f,0.0f,0.0f,1.0f };
	wchar_t str[128];
	swprintf_s(str, L"残り敵の数:%d", EnemyAmount);//整数を文字列か
	Font::StrDraw(str, 2, 96, 24, c);

}