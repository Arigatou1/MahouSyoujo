#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト敵機
class CObjEnemy2 : public CObj
{
public:
	CObjEnemy2() {};
	~CObjEnemy2() {};
	void Init();
	void Action();
	void Draw();
	
private:
	float m_ex;
	float m_ey;
	float m_vx;
	float m_vy;

	float m_mx;//マナのX位置
	float m_my;//マナのY位置
	int Amount;
};
