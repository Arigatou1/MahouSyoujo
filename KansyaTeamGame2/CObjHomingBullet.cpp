//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
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

	//当たり判定用のHITBOXを作成
	Hits::SetHitBox(this, m_bx-50.0f, m_by-50.0f, 50, 50, ELEMENT_PLAYER, OBJ_HOMINGBULLET, 10);
}

//アクション
void CObjHomingBullet::Action()
{
	if (m_bpostrue == 1.0f)
	{
		m_vx += 0.1f;
		m_bx += m_vx;
	}
	else if(m_bpostrue == 0.0f)
	{
		m_vx -= 0.1f;
		m_bx += m_vx;
	}

	//HitBOxの内容を変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_bx-50.0f, m_by-50.0f);


	//領域外に出たら弾丸を破棄する
	if (m_bx > 850.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (m_bx < 25.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (m_by > 650.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (m_by < 0.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
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