#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーンメイン
class CSceneMain :public CScene
{
public:
	CSceneMain();
	~CSceneMain();
	void InitScene();//初期化メソッド
	void Scene();//実行中メソッド
private:
	int m_time;//シーンタイム(敵の出現時間)
};