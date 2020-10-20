//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"

#include "CObjHomingBullet.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjHomingBullet::CObjHomingBullet(float x, float y,float m)
{
	m_bx = x;
	m_by = y;
	m_bpostrue = m;
}

//イニシャライズ
void CObjHomingBullet::Init()
{
	m_vx = 0.0f;
}

//アクション
void CObjHomingBullet::Action()
{
	m_vx += 1.0f;
	m_bx += m_vx;

	//領域外に出たら弾丸を破棄する
	if (m_bx > 800.0f)
	{
		this->SetStatus(false);
	}

	if (m_bx < 0.0f)
	{
		this->SetStatus(false);
	}

	if (m_by > 600.0f)
	{
		this->SetStatus(false);
	}

	if (m_by < 0.0f)
	{
		this->SetStatus(false);
	}
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
	dst.m_top    = m_by - 50.0f;
	dst.m_left   = (m_bx - 50.f + 50.0f * m_bpostrue);
	dst.m_right  = (m_bx - 50.0f * m_bpostrue);
	dst.m_bottom = m_by;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}