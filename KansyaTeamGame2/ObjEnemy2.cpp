//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include "ObjEnemy2.h"

//使用するネームベース
using namespace GameL;


//コンストラクタ
CObjEnemy2::CObjEnemy2(float x, float y)
{
	m_ex = x;
	m_ey = y;
}

//イニシャライズ
void CObjEnemy2::Init()
{
	m_vx = -1.0f;
	m_vy = 0.0f;
	//当たり判定用のHITBOXを作成
	Hits::SetHitBox(this, m_ex, m_ey, 50, 50, ELEMENT_ENEMY, OBJ_ENEMY2, 10);
	//Amount = 0;
}

//アクション
void CObjEnemy2::Action()
{
	

	//m_vxの速度で移動
	m_ex += m_vx;

	//特定の位置で停止（マナの情報を収得してやりたい）m_ex=480がちょうど

	CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);
	float x = obj->GetX() - m_ex;
	float y = obj->GetY() - m_ey;
	float ar = atan2(-y,x) * 180.0f / 3.14f;
	if (ar < 0)
	{
		ar = 360 - abs(ar);
	}

	
	float br = atan2(-m_vx, m_vy) * 180.0f / 3.14f;
	if (br < 0)
	{
		br = 360 - abs(br);
	}
	if (ar - br > 20)
	{
		m_vx = cos(3.14 / 180 * ar);
		m_vy = sin(3.14 / 180 * ar);
	}

	float r = 3.14 / 180.0f;
	if (ar < br)
	{
		m_vx = m_vx * cos(r) - m_vy * sin(r);
		m_vy = m_vy * cos(r) + m_vx * sin(r);
	}
	else
	{
		m_vx = m_vx * cos(-r) - m_vy * sin(-r);
		m_vy = m_vy * cos(-r) + m_vx * sin(-r);
	}
	
	if (m_ex == 475)



	//HitBOxの内容を変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex-50.0f, m_ey );

	if (hit->CheckObjNameHit(OBJ_HOMINGBULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		//Amount++;
	}

	if (hit->CheckObjNameHit(OBJ_SWORD) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		//Amount++;
	}
}

//ドロー
void CObjEnemy2::Draw()
{
	//描画カラー情報
	float c[4] = { 0.3f,1.0f,0.3f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 320.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 384.0f;
	//表示位置の設定
	dst.m_top = m_ey;
	dst.m_left = m_ex;
	dst.m_right = m_ex - 50.0f;
	dst.m_bottom = m_ey + 50.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
