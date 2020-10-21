//使用するヘッダーファイル
#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeHP.h"


//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjGaugeHP::Init()
{

}

//アクション
void CObjGaugeHP::Action()
{
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)
	{


		float HP = obj->GetHP();
		float MAXHP = obj->GetMAXHP();

		//MAXHPが100%とする

		GaugePercent = (HP / MAXHP) * 250;

	}
}
//ドロー
void CObjGaugeHP::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置


	//切り取り位置の設定
	src.m_top = 50.4f;
	//0%位置
	src.m_left = 46.0f;
	//100%位置
	src.m_right = GaugePercent+46.0f;
	src.m_bottom = 75.2f;
	//表示位置の設定
	dst.m_top = 0.0f;
	//0%位置
	dst.m_left = 46.0f;
	//100%位置
	dst.m_right = GaugePercent+46.0f;
	dst.m_bottom = 25.2f;


	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);

}