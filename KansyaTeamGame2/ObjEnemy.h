#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト敵機
class CObjEnemy : public CObj
{
public:
	CObjEnemy() {};
	~CObjEnemy() {};
	void Init();
	void Action();
	void Draw();
private:
};
