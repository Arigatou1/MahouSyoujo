#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト敵機
class CObjEnemy2 : public CObj
{
public:
	CObjEnemy2(float x, float y) ;
	~CObjEnemy2() {};
	void Init();
	void Action();
	void Draw();
	float GetE2_ATK();

	
private:
	int e2_time;//敵2の攻撃スピード

	float m_ex;
	float m_ey;
	float m_vx;
	float m_vy;

	float e2_atk;//敵２の攻撃力

	float b_mx;//バリアx位置

	float m_mx;//マナのX位置
	float m_my;//マナのY位置
	//int Amount;

	bool e2_t;//敵2の攻撃間隔
};
