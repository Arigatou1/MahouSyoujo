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
private:
	float m_px;
	float m_py;
	float m_vx;
	float m_vy;
	float m_posture;
};