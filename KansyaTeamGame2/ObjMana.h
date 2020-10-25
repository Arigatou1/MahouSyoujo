#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクトマナ
class CObjMana :public CObj
{
public:
	CObjMana() {};
	~CObjMana() {};
	void Init();
	void Action();
	void Draw();
	int GetHP();
	
private:
	float Mana_HP;
	float Mana_x;
	float Mana_y;

};

