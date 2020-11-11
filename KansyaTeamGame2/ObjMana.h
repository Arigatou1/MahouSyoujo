#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクトマナ
class CObjMana :public CObj
{
public:
	CObjMana(float x,float y);
	~CObjMana() ;
	void Init();
	void Action();
	void Draw();
	int GetHP();
	float GetX();
	float GetY();
private:
	float Mana_HP;
	float Mana_x;
	float Mana_y;

	float mana_damege;//敵１からのダメージ
	float mana_damege2;//敵2からのダメージ

};

