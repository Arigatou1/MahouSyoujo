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
		float m_postrue;//姿勢
		float m_mp;//MP
		
		int m_mtime;//MP回復用時間
};