//STLデバッグ機能をOFFにする
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"

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
	CObjMenu* sid = (CObjMenu*)Objs::GetObj(OBJ_MENU);
	//外部データの読み込み
	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size;
	int Stage = sid->GetStageID();

	wchar_t s[128];
	swprintf_s(s, L"Stage/Stage%d.csv", Stage);
	p = Save::ExternalDataOpen(s, &size);//外部データ読み込み
	
	int map[10][13];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}

	//HP用Font作成
	Font::SetStrTex(L"1234567890/.+-残り敵の数:");


	//グラフィックの読み込み
	Draw::LoadImageW(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"Gauge.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"BackGround.png", 2, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 60);
	

	//ゲージオブジェクト作成
	CObjGaugeBase* obj_gb = new CObjGaugeBase();
	Objs::InsertObj(obj_gb, OBJ_GAUGEBASE, 50);

	//HPゲージオブジェクト作成
	CObjGaugeHP* obj_ghp = new CObjGaugeHP();
	Objs::InsertObj(obj_ghp, OBJ_GAUGEHP, 51);

	//魔法少女オブジェクト作成
	CObjMagicalGirl* obj_magicalgirl = new CObjMagicalGirl();
	Objs::InsertObj(obj_magicalgirl, OBJ_MAGICALGIRL, 61);
	
	//Blockオブジェクト
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 11);

	//MPゲージオブジェクト作成
	CObjGaugeMP* obj_gmp = new CObjGaugeMP();
	Objs::InsertObj(obj_gmp, OBJ_GAUGEMP, 51);
	
	//背景オブジェクト作成
	CObjBackGround* obj_bg = new CObjBackGround();
	Objs::InsertObj(obj_bg, OBJ_BG, 10);

	//背景オブジェクト作成
	CObjEnemyAmount* obj_eneamo = new CObjEnemyAmount();
	Objs::InsertObj(obj_eneamo, OBJ_ENEMYAMOUNT, 51);


	

	//タイム初期化
	m_time = 0;

	EnemyAmount = 0;
}

//実行中メソッド
void CSceneMain::Scene()
{
	m_time++;
	

	if (m_time == 30)
	{
		//CObjEnemy3* obj_Enemy = new CObjEnemy3(0, 440);
		CObjEnemy3*obj_Enemy = new CObjEnemy3(300,600);
		Objs::InsertObj(obj_Enemy, OBJ_ENEMY3, 49);
	}
		/*CObjEnemy2* obj = new CObjEnemy2(800, 400);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);
		obj = new CObjEnemy2(0, 350);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);
		EnemyAmount+=2;

	}
	else if (m_time == 60)
	{
		CObjEnemy2* obj_enemy = new CObjEnemy2(700, 440);
		Objs::InsertObj(obj_enemy, OBJ_ENEMY2, 49);
		EnemyAmount++;
	}
	else if (m_time == 160)
	{
		CObjEnemy* obj = new CObjEnemy(0, 400);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);
		EnemyAmount++;
	}
	else if (m_time == 220)
	{
		CObjEnemy2* obj;
		obj = new CObjEnemy2(800, 450);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);
		obj = new CObjEnemy2(800, 350);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);
		obj = new CObjEnemy2(200, 350);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		EnemyAmount+=2;
	}

	else if (m_time == 280)
	{
		CObjEnemy* obj = new CObjEnemy(0, 390);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);
		CObjEnemy2* obj_enemy = new CObjEnemy2(800, 450);
		Objs::InsertObj(obj_enemy, OBJ_ENEMY2, 49);
		EnemyAmount+=2;
	}
	else if (m_time == 300)
	{
		CObjEnemy* obj = new CObjEnemy(0, 390);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);
		EnemyAmount++;
	}
	else if (m_time == 350)
	{
		CObjEnemy* obj = new CObjEnemy(0, 450);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);
		EnemyAmount++;
	}
	else if (m_time == 400)
	{
		CObjEnemy* obj = new CObjEnemy(0, 340);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);
		EnemyAmount++;
	}
	else if (m_time == 450)
	{
		CObjEnemy* obj = new CObjEnemy(0, 500);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);
		CObjEnemy2* obj_enemy = new CObjEnemy2(800, 450);
		Objs::InsertObj(obj_enemy, OBJ_ENEMY2, 49);
		EnemyAmount++;
	}
	else if (m_time == 500)
	{
		CObjEnemy* obj = new CObjEnemy(0, 450);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);
		CObjEnemy2* obj_enemy = new CObjEnemy2(800, 400);
		Objs::InsertObj(obj_enemy, OBJ_ENEMY2, 49);
		EnemyAmount+=2;
	}
	else if (m_time == 550)
	{
		CObjEnemy* obj = new CObjEnemy(0, 475);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);
		CObjEnemy2* obj_enemy = new CObjEnemy2(800, 425);
		Objs::InsertObj(obj_enemy, OBJ_ENEMY2, 49);
		EnemyAmount++;
	}
	else if (m_time == 600)
	{
		CObjEnemy* obj = new CObjEnemy(0, 475);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);
		CObjEnemy2* obj_enemy = new CObjEnemy2(800, 425);
		Objs::InsertObj(obj_enemy, OBJ_ENEMY2, 49);
		EnemyAmount++;
	}

	if (m_time==1300)
	{

		Scene::SetScene(new CSceneGameClear());
	}*/
	
}

