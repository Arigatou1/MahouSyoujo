#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ゲームオーバー
class CObjMenu : public CObj
{
public:
	CObjMenu() {};
	~CObjMenu() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;//キーフラグ
};