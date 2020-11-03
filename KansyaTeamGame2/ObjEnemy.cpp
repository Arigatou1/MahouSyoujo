//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include "ObjEnemy.h"

//使用するネームベース
using namespace GameL;

//コンストラクタ
CObjEnemy::CObjEnemy(float x, float y)
{
	m_ex = x;
	m_ey = y;
}
//イニシャライズ
void CObjEnemy::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	//当たり判定用のHITBOXを作成
	Hits::SetHitBox(this, m_ex, m_ey, 50, 50, ELEMENT_ENEMY, OBJ_ENEMY, 10);
}

//アクション
void CObjEnemy::Action()
{
	//m_vxの速度で移動
	m_ex += m_vx;


	CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if (obj != nullptr)
	{
		float m_mx = obj->GetX();

		if (m_mx <= m_ex)
			m_vx = -1.0f;
		else if (m_mx >= m_ex)
			m_vx = 1.0f;
		else
			m_vx = 0;
	}

	//HitBOxの内容を変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey);

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
void CObjEnemy::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top    = 320.0f;
	src.m_left   = 0.0f;
	src.m_right  = 64.0f;
	src.m_bottom = 384.0f;
	//表示位置の設定
	dst.m_top    = m_ey;
	dst.m_left	 = m_ex;
	dst.m_right  = m_ex + 50.0f;
	dst.m_bottom = m_ey + 50.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

//int CObjEnemy::EneAmo()
//{
//	return Amount;
//}