//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjHero.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHero::Init()
{
	m_px = 0;
	m_py = 0;
	m_vx = 0;
	m_vy = 0;
	m_posture = 0;
}

//アクション
void CObjHero::Action()
{
	//キーを押すと移動
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 0.1;
		m_posture = 0;
	}
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 0.1;
		m_posture = 1;
	}
	//どちらも押していない場合は減速させる。
	else
	{
		if (m_vx > 0)//左方向に動いているとき
		{
			m_vx -= 0.2;
			if (m_vx <= 0)
				m_vx = 0;
		}
		if (m_vx < 0)//右方向に動いているとき
		{
			m_vx += 0.2;
			if (m_vx >= 0)
				m_vx = 0;
		}
	}
	

	//最高速度決定
	if (m_vx >= 6)
		m_vx = 6;
	if (m_vx <= -6)
		m_vx = -6;
	m_px += m_vx;
}
//ドロー
void CObjHero::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;
	//表示位置の設定
	dst.m_top = 128.0f;
	dst.m_left = (64.0*m_posture)+m_px;
	dst.m_right = (64-64.0 * m_posture) + m_px;
	dst.m_bottom = 192.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}