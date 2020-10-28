//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjMana.h"
#include "GameHead.h"
//#include "ObjGaugeBaseMana.h"

//テスト用
#include "GameL\WinInputs.h"

//使用するネームスペース
using namespace GameL;

CObjMana::CObjMana(float x, float y)
{
	Mana_x = x;
	Mana_y = y;
}
float CObjMana::GetX()
{
	return Mana_x;
}

//位置情報Y取得用
float CObjMana::GetY()
{
	return Mana_y;
}

//イニシャライズ
void CObjMana::Init()
{
	
	Mana_HP = 100;


	//MANAゲージベースオブジェクト作成
	CObjGaugeMANABase* obj_managb = new CObjGaugeMANABase(Mana_x,Mana_y);
	Objs::InsertObj(obj_managb, OBJ_MANABASE, 50);

	//MANAゲージオブジェクト作成
	CObjGaugeMANAHP* obj_manahp = new CObjGaugeMANAHP(Mana_x, Mana_y);
	Objs::InsertObj(obj_manahp, OBJ_MANA_HP, 51);

	//あたり判定用Hitboxを作成
	Hits::SetHitBox(this, Mana_x+4 , Mana_y-604, 56, 600, ELEMENT_FIELD, OBJ_MANA, 1);
}

//アクション
void CObjMana::Action()
{
	

	if (Mana_HP <= 0)
	{
		Mana_HP = 0;
	}


	//HitBoxの内容
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(Mana_x,Mana_y-304);

	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		Mana_HP-=0.5;

	}

	//敵2に当たると1減る
	if (hit->CheckObjNameHit(OBJ_ENEMY2) != nullptr)
	{
		Mana_HP -= 1.0;

	}
	
	//マナのHPが無くなった時、消滅させる
	if (Mana_HP <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		Scene::SetScene(new CSceneGameOver());
	}
}
//ドロー
void CObjMana::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,Mana_HP/100,Mana_HP/100,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 192.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 256.0f;
	//表示位置の設定
	dst.m_top = Mana_y;
	dst.m_left = Mana_x;
	dst.m_right = Mana_x+64;
	dst.m_bottom = Mana_y+64;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}


int CObjMana::GetHP()
{
	return Mana_HP;
}

