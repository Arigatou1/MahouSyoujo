#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーンメイン
class EnemyAppear :public CObj
{
public:
	EnemyAppear() {};
	~EnemyAppear() {};
	void Init();
	void Action();
	void Draw();
private:
	int EnemyAmount;
	int StageID;
	int m_time;
};