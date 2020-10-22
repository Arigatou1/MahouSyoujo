//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjMana.h"
#include "GameHead.h"
#include "ObjGaugeBaseMana.h"

//テスト用
#include "GameL\WinInputs.h"

//使用するネームスペース
using namespace GameL;



//イニシャライズ
void CObjMana::Init()
{
	Mana_x = 300;
	Mana_y = 440;
	Mana_HP = 100;


}

//アクション
void CObjMana::Action()
{
	//ここは本来、m_mtkはfalseになっていて、敵に当たった時に行うようにする。
	if (Input::GetVKey('D') == true)
	{

		Mana_HP -= 1;//敵の攻撃力

	}
	else
		;

	if (Mana_HP <= 0)
	{
		Mana_HP = 0;
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