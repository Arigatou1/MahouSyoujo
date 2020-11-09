//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "ObjAllBullet.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjAllBullet::CObjAllBullet(float x, float y)
{
	m_ax = x;
	m_ay = y;
}

//イニシャライズ
void CObjAllBullet::Init()
{
	m_avy = 2.0f;
	//攻撃力
	z_atk = 10;

	//当たり判定用のHITBOXを作成
	Hits::SetHitBox(this, m_ax, m_ay, 64, 64, ELEMENT_PLAYER, OBJ_ALLBULLET, 10);
}

//アクション
void CObjAllBullet::Action()
{

	//当たり判定を行うオブジェクト情報部
	int database[4] =
	{
		OBJ_ENEMY,
		OBJ_ENEMY2,
		OBJ_ENEMY3,
		OBJ_ENEMY4,
	};

	//HitBOxの内容を変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ax, m_ay);

	//下に落ちる
	m_ay += m_avy;

	for (int i = 0; i < 4; i++)
	{
		if (hit->CheckObjNameHit(database[i]) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}




	//領域外に出たら弾丸を破棄する
	if (m_ax > 775.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (m_ax < -25.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (m_ay > 575.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (m_ay < -25.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//ドロー
void CObjAllBullet::Draw()
{
	//描画カラー
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 192.0f;
	src.m_left = 64.0f;
	src.m_right = 128.0f;
	src.m_bottom = 256.0f;

	//表示位置の設定
	dst.m_top    = 0.0f + m_ay;
	dst.m_left   = 0.0f + m_ax;
	dst.m_right  = 64.0f + m_ax;
	dst.m_bottom = 64.0f + m_ay;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

int CObjAllBullet::GetZ_ATK()
{
	return z_atk;
}