//使用するヘッダーファイル
#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeMana.h"
#include "GameL\DrawFont.h"


//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjGaugeMANAHP::Init()
{
	CObjMana* obj_mana = (CObjMana*)Objs::GetObj(OBJ_MANA);
}

//アクション
void CObjGaugeMANAHP::Action()
{

	

	CObjMana* obj_mana = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if (obj_mana != nullptr)
	{


		MANAHP = obj_mana->GetHP();


		//MAXHPが100%とする

		GaugePercent = (MANAHP / 100) * 292;

	}
}
//ドロー
void CObjGaugeMANAHP::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	wchar_t str[128];
	swprintf_s(str, L"%.0lf", MANAHP);//整数を文字列か
	Font::StrDraw(str, 300, 572, 24, c);

	//切り取り位置の設定
	src.m_top = 144.0f;
	//0%位置
	src.m_left = 4.0f;
	//100%位置
	src.m_right = GaugePercent+4.0f;
	src.m_bottom = 168.0f;
	//表示位置の設定
	dst.m_top = 572.0f;
	//0%位置
	dst.m_left = 4.0f;
	//100%位置
	dst.m_right = GaugePercent + 4.0f;
	dst.m_bottom = 596.0f;


	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);

}