//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjMagicalGirl.h"
//#include "主人公のヘッダー？"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMagicalGirl::Init()
{
	m_gx = 0.0f;//位置（主人公の位置を収得？）
	m_gy = 0.0f;

	m_vx = 0.0f;//移動ベクトル
	m_vy = 0.0f;

	m_postrue = 1.0f;//右向き0.0f 左向き1.0f
}

//アクション
void CObjMagicalGirl::Action()
{
	//移動ベクトルの破棄
	m_vx = 0.0f;
	m_vy = 0.0f;

	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_postrue = 1.0f;
	}

	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_postrue = 0.0f;
	}
}

//ドロー
void CObjMagicalGirl::Draw()
{
	//描画カラー
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 64.0f;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top	 = 0.0f + m_gy;
	dst.m_left   = (        64.0f * m_postrue);
	dst.m_right  = (64.0f - 64.0f * m_postrue);
	dst.m_bottom = 64.0f + m_gy;

	//描画
	Draw::Draw(0,&src,&dst,c,0.0f);
}