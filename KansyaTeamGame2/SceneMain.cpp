//STLデバッグ機能をOFFにする
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//初期化メソッド
void CSceneMain::InitScene()
{
	//グラフィックの読み込み
	Draw::LoadImageW(L"", 0, TEX_SIZE_512);

	//魔法少女オブジェクト作成
	CObjMagicalGirl* obj = new CObjMagicalGirl();
	Objs::InsertObj(obj, OBJ_MAGICALGIRL, 10);
}

//実行中メソッド
void CSceneMain::Scene()
{

}

