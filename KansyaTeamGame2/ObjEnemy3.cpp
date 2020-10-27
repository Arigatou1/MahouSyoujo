//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
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
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_posture = 1.0f; //みぎむき0.0f　左向き1.0f
}

//アクション
void CObjEnemy3::Action()
{
	m_ex += m_vx;
}

//ドロー
void CObjEnemy3::Draw()
{
	
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 370.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 434.0f;
	//表示位置の設定
	dst.m_top =m_ex;
	dst.m_left = m_ey;
	dst.m_right =  m_ey+50.0f;
	dst.m_bottom =  m_ex+50.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}