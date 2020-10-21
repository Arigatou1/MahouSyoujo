#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクトソード
class CObjGauge :public CObj
{
public:
	CObjGauge() {};
	~CObjGauge() {};
	void Init();
	void Action();
	void Draw();
private:
	
};

