//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjSword.h"

//使用するネームスペース
using namespace GameL;


//コンストラクタ
CObjSword::CObjSword(float x, float y,int posture)
{
	a_px = x;
	a_py = y;

	a_posture = posture;
}

//イニシャライズ
void CObjSword::Init()
{
	m_f = true;
	Hits::SetHitBox(this,a_px, a_py, 56, 56, ELEMENT_PLAYER, OBJ_SWORD, 1);
	atk_time = 0;

}

//アクション
void CObjSword::Action()
{

	
	//攻撃する用のキー入力とかだったが、バグ発生中。


	//キーを押すと攻撃
	//テスト用Xキー
	
	
	
			//HitBoxの内容を更新
			CHitBox* hit = Hits::GetHitBox(this);
			hit->SetPos(a_px+(a_posture*48), a_py);
		
	

	//m_f = true;
	//this->SetStatus(false);
	//Hits::DeleteHitBox(this);

	

}
//ドロー
void CObjSword::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top =0.0f;
	src.m_left =0.0f;
	src.m_right = 0.0f;
	src.m_bottom = 0.0f;
	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 0.0f;
	dst.m_bottom = 0.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}