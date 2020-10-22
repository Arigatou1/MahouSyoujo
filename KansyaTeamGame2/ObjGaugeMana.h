#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクトマナ
class CObjGaugeMANAHP :public CObj
{
public:
	CObjGaugeMANAHP() {};
	~CObjGaugeMANAHP() {};
	void Init();
	void Action();
	void Draw();
private:
	float MANAHP;
	
	float GaugePercent;

	float Manag_x;
	float Manag_y;
};

