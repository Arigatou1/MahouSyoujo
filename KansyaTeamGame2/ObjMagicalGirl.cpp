//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjMagicalGirl.h"
//#include "主人公のヘッダー？"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMagicalGirl::Init()
{
	m_gx = 200;
	m_gy = 200;
	m_mp = 100;//MP総量100

	m_postrue = 1.0f;//右向き0.0f 左向き1.0f

	m_mtime = 0;
}

//アクション
void CObjMagicalGirl::Action()
{
	m_mtime++;

	if (m_mp < 100)
	{
		m_mtime = 0;
		if (m_mtime % 60 == 0)
		{
			m_mp++;
		}
	}
	//魔法少女の通常攻撃
	if (Input::GetVKey('F') == true)
	{
		//ホーミング弾作成
		CObjHomingBullet* obj_homingbullet = new CObjHomingBullet(m_gx,m_gy,m_postrue);//ホーミング弾作成
		Objs::InsertObj(obj_homingbullet, OBJ_HOMINGBULLET, 10);//オブジェクトマネーに登録
	}

	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_postrue = 0.0f;
	}

	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_postrue = 1.0f;
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
	src.m_right  = 50.0f;
	src.m_bottom = 50.0f;

	//表示位置の設定
	dst.m_top	 = m_gy-50.0f;
	dst.m_left   = (m_gx - 50.f + 50.0f * m_postrue);
	dst.m_right  = (m_gx - 50.0f * m_postrue);
	dst.m_bottom = m_gy;

	//描画
	Draw::Draw(0,&src,&dst,c,0.0f);
}