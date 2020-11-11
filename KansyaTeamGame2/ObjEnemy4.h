#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵３
class CObjEnemy4 :public CObj
{
public:
	CObjEnemy4() {};
	~CObjEnemy4() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_ex;//X座標
	float m_ey;//Y座標
	float m_vx;//移動ベクトル	
	float m_vy;

	float m_mx;//マナのX位置
	float m_my;//マナのY位置
	//int Amount;
};