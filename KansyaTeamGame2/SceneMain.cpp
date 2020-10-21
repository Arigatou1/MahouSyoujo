//STLデバッグ機能をOFFにする
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"

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
	//HP用Font作成
	Font::SetStrTex(L"1234567890/.+-");


	//グラフィックの読み込み
	Draw::LoadImageW(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"Gauge.png", 1, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//敵1オブジェクト作成
	CObjEnemy* obj_enemy = new CObjEnemy();
	Objs::InsertObj(obj_enemy, OBJ_ENEMY, 10);
	
	//ゲージオブジェクト作成
	CObjGaugeBase* obj_gb = new CObjGaugeBase();
	Objs::InsertObj(obj_gb, OBJ_GAUGEBASE, 50);

	//HPゲージオブジェクト作成
	CObjGaugeHP* obj_ghp = new CObjGaugeHP();
	Objs::InsertObj(obj_ghp, OBJ_GAUGEHP, 51);

	//魔法少女オブジェクト作成
	CObjMagicalGirl* obj_magicalgirl = new CObjMagicalGirl();
	Objs::InsertObj(obj_magicalgirl, OBJ_MAGICALGIRL, 10);
	
	//stageオブジェクト作成
	CObjstage* obj_stage = new CObjstage();
	Objs::InsertObj(obj_stage, OBJ_STAGE, 9);
}

//実行中メソッド
void CSceneMain::Scene()
{

}

