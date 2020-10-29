//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "ObjBullet.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBullet::CObjBullet(float x, float y, int posture, bool m_f)
{
	px = x;
	py = y;

	b_posture = posture;
	b_f = m_f;
}

//イニシャライズ
void CObjBullet::Init()
{
	Hits::SetHitBox(this, px, py, 56, 56, ELEMENT_PLAYER, OBJ_BULLET, 1);
	
	vx = 0;
	vy = 0;
}

//アクション
void CObjBullet::Action()
{

	//HitBOxの内容を変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(px, py);

	if (b_posture == 1)
		vx += 0.5f;
	else
		vx -= 0.5f;
	//位置を更新
	px += vx;
	
}

//ドロー
void CObjBullet::Draw()
{
	//描画カラー
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 192.0f;
	src.m_left = 64.0f;
	src.m_right = 128.0f;
	src.m_bottom = 256.0f;

	//表示位置の設定
	dst.m_top =py+0.0f;
	dst.m_left = (b_posture*64)+px+64.0f;
	dst.m_right = (b_posture * 64)+px+64.0f;
	dst.m_bottom = py+64.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}