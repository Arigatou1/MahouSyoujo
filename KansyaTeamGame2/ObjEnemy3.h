#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵３
class CObjEnemy3 :public CObj
{
public:
	CObjEnemy3(float x, float y);
	~CObjEnemy3() {};
	void Init();
	void Action();
	void Draw();

	float GetX() { return m_ex; };
	float GetY() { return m_ey; };
	float GetVX() { return m_vx; }
	float GetVY() { return m_vy; }
	

	void SetX(float x) { m_ex = x; }
	void SetY(float y) { m_ey = y; }
	void SetVY(float vy) { m_vy=vy; }
	void SetVX(float vx) { m_vx = vx; }

	void SetUp(bool eb) { hit_up; }
	void SetDown(bool eb) { hit_down; }
	void SetLeft(bool eb) { hit_left; }
	void SetRight(bool eb) { hit_right; }

private:
	float m_ex;		//X座標
	float m_ey;		//Y座標
	float m_vx;		//移動ベクトル
	float m_vy;

	float m_mx; //マナの座標
	float m_my;

	bool jump;
	//blockとの衝突状態確認用
	bool hit_up;
	bool hit_down;
	bool hit_left;
	bool hit_right;
};
