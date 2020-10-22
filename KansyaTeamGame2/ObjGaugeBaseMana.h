#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクトソード
class CObjGaugeMANABase :public CObj
{
public:
	CObjGaugeMANABase() {};
	~CObjGaugeMANABase() {};
	void Init();
	void Action();
	void Draw();
private:

	

};

