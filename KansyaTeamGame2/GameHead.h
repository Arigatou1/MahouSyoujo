#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_HERO,
	OBJ_MAGICALGIRL,
	OBJ_HOMINGBULLET,
	OBJ_SWORD,
	OBJ_ENEMY,
	OBJ_ENEMY2,
	OBJ_ENEMY3,
	OBJ_GAUGEBASE,
	OBJ_GAUGEHP,
	OBJ_GAUGEMP,
	OBJ_BLOCK,
	OBJ_MANA,
	OBJ_MANABASE,
	OBJ_MANA_HP,
	OBJ_TITLE,
	OBJ_GAME_OVER,
	OBJ_BG,
	OBJ_GAME_CLEAR,
	OBJ_ENEMYAMOUNT,
	OBJ_MENU,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "ObjHero.h"
#include "ObjMagicalGirl.h"
#include "CObjHomingBullet.h"
#include "ObjEnemy.h"
#include "ObjEnemy2.h"
#include "ObjEnemy3.h"
#include "ObjGaugeBase.h"
#include "ObjBlock.h"
#include "ObjGaugeHP.h"
#include "ObjGaugeMP.h"
#include "ObjGaugeMana.h"
#include "ObjMana.h"
#include "ObjGaugeBaseMana.h"
#include "ObjTitle.h"
#include "ObjGameOver.h"
#include "ObjBackGround.h"
#include "ObjGameClear.h"
#include "ObjEnemyAmount.h"
#include "ObjMenu.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneGameOver.h"
#include "SceneGameClear.h"
#include "SceneMenu.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneMenu
//-----------------------------------------------