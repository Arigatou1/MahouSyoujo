#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ゲームオーバー
class CObjGameClear : public CObj
{
public:
	CObjGameClear() {};
	~CObjGameClear() {};
	void Init();
	void Action();
	void Draw();
private:
	int Score;
	bool m_key_flag;//キーフラグ
};