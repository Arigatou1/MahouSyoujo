#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include"ObjEnemy4.h"
#include"GameL/UserData.h"

CObjEnemy4::CObjEnemy4(float x, float y)
{
	m_ex = x;
	m_ey = y;
}

//イニシャライズ
void CObjEnemy4::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_r = 0.0f;

	//当たり判定HitBoxを作成
	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_ENEMY4, 10);
}

//アクション
void CObjEnemy4::Action()
{
	m_ex += 2*m_vx;



	//
	CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);
//	CObjHero* obj_h = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)
	{
		float m_mx = obj->GetX();
	//	float m_hx = obj_h->GetX();
	//	float m_hy = obj_h->GetY();

		if (m_mx <= m_ex)
			m_vx = -1.0f;
		else if (m_mx >= m_ex)
			m_vx = 1.0f;
		else
			m_vx = 0;

		/*if (m_hx - m_ex == 5 && m_hx - m_ex == -5 && m_hy - m_ey == 5 && m_hy - m_ey == -5)
		{

		}*/
	}

	

	//
	/*CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)
	{
		float m_px = obj->GetX();

		if (m_px <= m_ex)
			m_vx = -1.0f;
		else if (m_px >= m_ex)
			m_vx = 1.0f;
		else
			m_vx = 0;
	}*/

	//
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex+0.0f, m_ey+0.0f);

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
void CObjEnemy4::Draw()
{
	//描画カラー情報
	float c[4] = { 2.0f,2.0f,2.0f,2.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 448.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 512.0f;
	
	//表示位置の設定
	dst.m_top = m_ey;
	dst.m_left = m_ex;
	dst.m_right = m_ex + 64.0f;
	dst.m_bottom = m_ey + 64.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}