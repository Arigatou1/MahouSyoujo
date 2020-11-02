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
	m_maxmp = 100;
	m_mp =m_maxmp;//MP総量100
	
	m_postrue = 1.0f;//右向き0.0f 左向き1.0f
	m_atk_animation = 0;//0=棒立ちの画像

	m_mtime = 1;
	//m_btime = 1;
}

//アクション
void CObjMagicalGirl::Action()
{
	m_mtime++;
	//m_btime++;

	CObjMana* obj_mana = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if(obj_mana != nullptr)
	{
		m_gx = obj_mana->GetX();
		m_gy = obj_mana->GetY();
	}

	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)
	{
		h_hp = obj->GetHP();
		h_maxhp = obj->GetMAXHP();
	}

	if (m_mp < 100)//(おそらく1秒に1)MP回復
	{

		if (m_mtime % 60 == 0)
		{
			m_mp++;
			m_mtime = 0;
		}
	}

	//キーを押すと移動
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_postrue = 0.0f;
	}
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_postrue = 1.0f;
	}

	//魔法少女の通常攻撃
	if (m_mp >= 1)
	{
		if (Input::GetVKey('D') == true && m_t == true)
		{
			m_atk_animation = 3;//杖持った姿になる

			if (m_postrue == 0.0f)
			{
				m_t = false;
				//魔法少女魔法玉作成
				CObjHomingBullet* obj_homingbullet = new CObjHomingBullet(m_gx - 25.0f, m_gy, m_postrue);//ホーミング弾作成
				Objs::InsertObj(obj_homingbullet, OBJ_HOMINGBULLET, 60);//オブジェクトマネーに登録

				m_mp -= 1;

				if (m_mp < 0)
				{
					m_mp = 0;
				}
			}
			else if (m_postrue == 1.0f)
			{
				m_t = false;
				//魔法少女魔法玉作成
				CObjHomingBullet* obj_homingbullet = new CObjHomingBullet(m_gx + 25.0f, m_gy, m_postrue);//ホーミング弾作成
				Objs::InsertObj(obj_homingbullet, OBJ_HOMINGBULLET, 60);//オブジェクトマネーに登録

				m_mp -= 1;

				if (m_mp < 0)
				{
					m_mp = 0;
				}
			}
		}
		else if (Input::GetVKey('D') == false)
		{
			m_atk_animation = 0;//棒立ちの姿になる
			m_t = true;
		}
	}

	//魔法少女の回復魔法
	if (m_mp >= 20)
	{
		if (h_hp < h_maxhp)
		{
			if (Input::GetVKey('H') == true && h_t == true)
			{
				h_t = false;
				m_mp -= 20;
			}
			else if (Input::GetVKey('H') == false)
			{
				h_t = true;
			}
		}
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
	src.m_top    = 128.0f;
	src.m_left   = (m_atk_animation * 64.0f) + 0.0f;
	src.m_right  = (m_atk_animation * 64.0f) + 64.0f;
	src.m_bottom = 192.0f;

	//表示位置の設定
	dst.m_top	 =0.0f  + m_gy;
	dst.m_left   =0.0f  + (m_gx + 64.0f * m_postrue);
	dst.m_right  =64.0f + (m_gx - 64.0f * m_postrue);
	dst.m_bottom =64.0f + m_gy;

	//描画
	Draw::Draw(0,&src,&dst,c,0.0f);
}

int CObjMagicalGirl::GetMP()
{
	return m_mp;
}

int CObjMagicalGirl::GetMaxMP()
{
	return m_maxmp;
}