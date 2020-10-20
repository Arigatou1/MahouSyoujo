#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//ホーミング弾
class CObjHomingBullet :public CObj
{
public:
	CObjHomingBullet() {};
	~CObjHomingBullet() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_bx;//弾丸のX位置
	float m_by;//弾丸のY位置
};