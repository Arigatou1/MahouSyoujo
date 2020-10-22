//使用するヘッダーファイル
#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeBaseMana.h"


//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjGaugeMANABase::CObjGaugeMANABase(float x, float y)
{
	gb_x = x;
	gb_y = y;

}


//イニシャライズ
void CObjGaugeMANABase::Init()
{

}

//アクション
void CObjGaugeMANABase::Action()
{



}
//ドロー
void CObjGaugeMANABase::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置


	//切り取り位置の設定
	src.m_top = 48.0f;
	src.m_left = 0.0f;
	src.m_right = 300.0f;
	src.m_bottom = 72.0f;
	//表示位置の設定
	dst.m_top = gb_y+56.0f;
	dst.m_left = gb_x-116.0f;
	dst.m_right = gb_x+184.0f;
	dst.m_bottom = gb_y+80.0f;


	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);

}