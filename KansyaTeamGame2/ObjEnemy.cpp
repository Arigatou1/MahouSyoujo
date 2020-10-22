//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "ObjEnemy.h"

//使用するネームベース
using namespace GameL;

//イニシャライズ
void CObjEnemy::Init()
{

}

//アクション
void CObjEnemy::Action()
{

}

//ドロー
void CObjEnemy::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 320.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 384.0f;
	//表示位置の設定
	dst.m_top = 320.0f;
	dst.m_left = 320.0f;
	dst.m_right = 384.0f;
	dst.m_bottom = 384.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
