//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"

#include "CObjHomingBullet.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHomingBullet::Init()
{

}

//アクション
void CObjHomingBullet::Action()
{

}

//ドロー
void CObjHomingBullet::Draw()
{
	//描画カラー
	float c[4] = { 1.0f,5.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 50.0f;
	src.m_bottom = 50.0f;

	//表示位置の設定
	dst.m_top    = 0.0f;
	dst.m_left   = 0.0f;
	dst.m_right  = 50.0f;
	dst.m_bottom = 50.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}