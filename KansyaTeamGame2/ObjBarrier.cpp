//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "Objbarrier.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBarrier::CObjBarrier(float x, float y)
{
	mb_x = x;
	mb_y = y;
}

//イニシャライズ
void CObjBarrier::Init()
{
	b_time = 0;

	//当たり判定用のHITBOXを作成
	Hits::SetHitBox(this, mb_x ,mb_y + 256.0f ,64, -600, ELEMENT_PLAYER, OBJ_BARRIER, 10);
}

//アクション
void CObjBarrier::Action()
{
	b_time++;

	if (Input::GetVKey('B') == true && b_t == true)
	{
		b_time = 0;
		b_t = false;
		if (b_time == 0)
		{
			//HitBOxの内容を変更
			CHitBox* hit = Hits::GetHitBox(this);
			hit->SetPos(mb_x, mb_y + 64.0f);
		}
		
	}
	else if (Input::GetVKey('B') == false && b_time > 200)
	{
		b_t = true;
	}

	if (b_time >= 200)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}
//ドロー
void CObjBarrier::Draw()
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
	dst.m_top    = mb_y - 384.0f;
	dst.m_left   = mb_x + 0.0f;
	dst.m_right  = mb_x + 64.0f;
	dst.m_bottom = mb_y + 224.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
float CObjBarrier::GetBX()
{
	return mb_x;
}