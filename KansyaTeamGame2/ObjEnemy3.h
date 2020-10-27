#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵３
class CObjEnemy3 :public CObj
{
public :
	CObjEnemy3(float x,float y);
	~CObjEnemy3() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_ex;		//X座標
	float m_ey;		//Y座標
	float m_vx;		//移動ベクトル
	float m_vy;		
	float m_posture;

	bool isjump;//ジャンプ
};
