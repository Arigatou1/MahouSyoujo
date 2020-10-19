#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjMagicalGirl : public CObj
{
	public:
		CObjMagicalGirl() {};
		~CObjMagicalGirl() {};
		void Init();   //イニシャライズ
		void Action(); //アクション
		void Draw();   //ドロー
	private:
		float m_gx;//位置
		float m_gy;
		float m_vx;//移動ベクトル
		float m_vy;
		float m_postrue;//姿勢
};