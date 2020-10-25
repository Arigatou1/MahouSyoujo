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
	Draw::LoadImageW(L"BackGround.png", 2, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 12);

	//敵1オブジェクト作成
	//CObjEnemy* obj_enemy = new CObjEnemy();
	//Objs::InsertObj(obj_enemy, OBJ_ENEMY, 10);

	//敵2オブジェクト作成
	//CObjEnemy2* obj_enemy2 = new CObjEnemy2();
	//Objs::InsertObj(obj_enemy2, OBJ_ENEMY2, 10);
	
	//ゲージオブジェクト作成
	CObjGaugeBase* obj_gb = new CObjGaugeBase();
	Objs::InsertObj(obj_gb, OBJ_GAUGEBASE, 50);

	//HPゲージオブジェクト作成
	CObjGaugeHP* obj_ghp = new CObjGaugeHP();
	Objs::InsertObj(obj_ghp, OBJ_GAUGEHP, 51);

	//魔法少女オブジェクト作成
	CObjMagicalGirl* obj_magicalgirl = new CObjMagicalGirl();
	Objs::InsertObj(obj_magicalgirl, OBJ_MAGICALGIRL, 11);
	
	//stageオブジェクト作成
	CObjstage* obj_stage = new CObjstage();
	Objs::InsertObj(obj_stage, OBJ_STAGE, 9);


	//mana作成
	CObjMana* obj_mana = new CObjMana();
	Objs::InsertObj(obj_mana, OBJ_MANA, 10);

	//MPゲージオブジェクト作成
	CObjGaugeMP* obj_gmp = new CObjGaugeMP();
	Objs::InsertObj(obj_gmp, OBJ_GAUGEMP, 50);
	
	//背景オブジェクト作成
	CObjBackGround* obj_bg = new CObjBackGround();
	Objs::InsertObj(obj_bg, OBJ_BG, 1);
	
	//タイム初期化
	m_time = 0;
}

//実行中メソッド
void CSceneMain::Scene()
{
	m_time++;

	if (m_time == 300)
	{
		CObjEnemy* obj_enemy = new CObjEnemy(0.0f,440.0f);
		Objs::InsertObj(obj_enemy, OBJ_ENEMY, 10);
	}
	else if (m_time == 600)
	{
		CObjEnemy* obj_enemy = new CObjEnemy(0.0f, 440.0f);
		Objs::InsertObj(obj_enemy, OBJ_ENEMY, 10);
	}
	else if (m_time == 700)
	{
		CObjEnemy2* obj_enemy2 = new CObjEnemy2(850.0f, 440.0f);
		Objs::InsertObj(obj_enemy2, OBJ_ENEMY2, 10);
	}
}

