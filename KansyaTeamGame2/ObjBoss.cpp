//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include "ObjEnemy.h"
#include "GameL/UserData.h"

//使用するネームベース
using namespace GameL;

//コンストラクタ
CObjBoss::CObjBoss(float x, float y)
{
	m_ex = x;
	m_ey = y;
}
//イニシャライズ
void  CObjBoss::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	e1_damege = 0;
	e1_atk = 0.04;
	e1_time = 0;
	e_hp = 5;

	//blockとの衝突状態確認用
	e1_hit_up = false;
	e1_hit_down = false;
	e1_hit_left = false;
	e1_hit_right = false;

	e1_xsize = 50;
	e1_ysize = 50;

	//当たり判定用のHITBOXを作成
	Hits::SetHitBox(this, m_ex, m_ey, 50, 50, ELEMENT_ENEMY, OBJ_BOSS_ENEMY, 10);
}

//アクション
void  CObjBoss::Action()
{
	e1_time++;

	if (e1_time % 96 == 32)
	{
		e1_atk = 0;
	}
	else if (e1_time % 96 == 0)
	{
		e1_atk = 0.04;
	}

	//HitBOxの内容を変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey);

	//重力
	m_vy += 9.8 / (16.0f);

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

	//バリア出てる時だけ止まる
	CObjBarrier* obj_barrier = (CObjBarrier*)Objs::GetObj(OBJ_BARRIER);
	if (obj_barrier != nullptr)
	{
		b_mx = obj_barrier->GetBX();

		if (m_ex == b_mx - 48.0f)
		{
			m_vx = 0;
		}
		else if (m_ex == b_mx + 160.0f)
		{
			m_vx = 0;
		}

	}

	//m_vxの速度で移動
	m_ex += m_vx;
	m_ey += m_vy;


	CObjBlock* obj_block1 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	obj_block1->BlockHit(&m_ex, &m_ey,
		&e1_hit_up, &e1_hit_down, &e1_hit_left, &e1_hit_right,
		&m_vx, &m_vy, &e1_xsize, &e1_ysize);

	if (hit->CheckObjNameHit(OBJ_MANA) != nullptr)
	{
		e1_time = 0;
	}

	if (hit->CheckObjNameHit(OBJ_HOMINGBULLET) != nullptr)
	{

		CObjHomingBullet* obj_homing = (CObjHomingBullet*)Objs::GetObj(OBJ_HOMINGBULLET);
		e1_damege = obj_homing->GetM_ATK();

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr)
	{

		CObjAllBullet* obj_all = (CObjAllBullet*)Objs::GetObj(OBJ_ALLBULLET);
		e1_damege = obj_all->GetZ_ATK();

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (hit->CheckObjNameHit(OBJ_SWORD) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		((UserData*)Save::GetData())->Score += 100;
	}
}

//ドロー
void  CObjBoss::Draw()
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
	dst.m_top = m_ey;
	dst.m_left = m_ex;
	dst.m_right = m_ex + 50.0f;
	dst.m_bottom = m_ey + 50.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

float  CObjBoss::GetE1_ATK()
{
	return e1_atk;
}