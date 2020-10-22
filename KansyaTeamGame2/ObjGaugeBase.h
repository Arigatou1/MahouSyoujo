#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクトゲージベース
class CObjGaugeBase :public CObj
{
public:
	CObjGaugeBase() {};
	~CObjGaugeBase() {};
	void Init();
	void Action();
	void Draw();
private:
	
};

