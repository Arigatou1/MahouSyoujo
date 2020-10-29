//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include"ObjEnemy3.h"

//使用するネームスペース
using namespace GameL;

CObjEnemy3::CObjEnemy3(float x,float y)
{
	m_ex = x;
	m_ey = y;
	
	
}

//イニシャライズ
void CObjEnemy3::Init()
{

	m_vx = 0;
	m_vy = 0;

	hit_up = false;
	hit_down = false;
	hit_left = false;
	hit_right = false;
	//当たり判定用のHITBOXを作成
	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_ENEMY3, 1);
}

//アクション
void CObjEnemy3::Action()
{
	//摩擦
	//m_vx += -(m_vx * 0.098);
	//自由落下運動
	m_vy += 9.8 / (16.0f);


	m_ey += m_vy;
	//特定の位置で停止（マナの情報を収得してやりたい）m_ex=480がちょうど
	if (m_ey == 410)
	{
		m_vy = 0.0f;

	}

	//ジャンプ
	/*if (hit_down==true&&jump==true)
	{
		m_vy += 10;
		jump == false;
	}
	else
	{
		jump == true;
	}*/

	//HitBOxの内容を変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex + 10.0f, m_ey+10.0f);

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
void CObjEnemy3::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 384.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 448.0f;
	//表示位置の設定
	dst.m_top =m_ey;
	dst.m_left = m_ex;
	dst.m_right =  m_ex+64.0f;
	dst.m_bottom =  m_ey+64.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}