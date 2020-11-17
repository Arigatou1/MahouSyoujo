#pragma once
//使用するヘッダーファイル
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ボス
class CObjBoss : public CObj
{
public:
	CObjBoss(float x, float y);
	~CObjBoss() {};
	void Init();
	void Action();
	void Draw();
	float GetE1_ATK();
private:
	float m_ex;
	float m_ey;
	float m_vx;
	float m_vy;
	int e_hp;//敵のHP
	int e1_damege;//ダメージ量
	int e1_time;//敵の攻撃間隔

	float e1_atk;//敵の攻撃力

	float b_mx;//バリアのx位置
	float b_my;//バリアのy位置

	float m_mx;//マナのX位置
	float m_my;//マナのY位置
	

	//blockとの衝突状態確認用
	bool e1_hit_up;
	bool e1_hit_down;
	bool e1_hit_left;
	bool e1_hit_right;

	float e1_xsize;
	float e1_ysize;
};
