#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト主人公
class CObjHero :public CObj
{
public :
	CObjHero() {};
	~CObjHero() {};
	void Init();
	void Action();
	void Draw();
	int GetHP();
	int GetMAXHP();
private:
	float m_px;		//プレイヤーの座標X
	float m_py;		//プレイヤーの座標Y
	float m_vx;		//プレイヤーのベクトルX
	float m_vy;		//プレイヤーのベクトルY
	float m_posture;//向いている方向用


	int m_anime;	//歩くアニメーション
	int m_anitime;	//歩くアニメーションの間隔

	int atk_anime;	//剣を出す
	int atk_anitime;//
	int atk_time;	//攻撃の間隔

	int m_hp;//プレイヤーの体力
	int max_hp;
	int mtk_jkn;//無敵時間用変数
	int mtk_max;//無敵時間用変数
	bool m_mtk;//主人公の無敵判定
	float speed_power;

	bool m_f;		//攻撃の間隔
	bool isJump;//ジャンプできるかできないかを判断する

	
    };

