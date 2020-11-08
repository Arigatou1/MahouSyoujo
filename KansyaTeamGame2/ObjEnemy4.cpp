#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include"ObjEnemy4.h"

CObjEnemy4::CObjEnemy4(float x, float y)
{
	m_ex = x;
	m_ey = y;
}

//イニシャライズ
void CObjEnemy4::Init()
{

}

//アクション
void CObjEnemy4::Action()
{
	m_vx = -1.0f;
	m_vy = sin(3.14 / 180 * m_r);

	//角度計算
	m_r += 2.0f;

	//360゜で初期値に戻す
	if (m_r > 360.0f)
		m_r = 0.0f;
	//移動方向
	m_vx = -1.0f;
	m_vy = sin(3.14 / 180 * m_r);//sinθを求めてm_vyに入れる
}

//ドロー
void CObjEnemy4::Draw()
{
	//描画カラー情報
	float c[4] = { 2.0f,2.0f,2.0f,2.0f };

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