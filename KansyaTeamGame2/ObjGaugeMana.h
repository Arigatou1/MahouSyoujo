#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクトソード
class CObjGaugeMANAHP :public CObj
{
public:
	CObjGaugeMANAHP() {};
	~CObjGaugeMANAHP() {};
	void Init();
	void Action();
	void Draw();
private:
	float HP;
	float GaugePercent;


};

