//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "GameL/SceneObjManager.h"
#include "EnemyAppear.h"
#include "GameL\UserData.h"
#include "GameL\DrawFont.h"


//使用するネームベース
using namespace GameL;


//イニシャライズ
void EnemyAppear::Init()
{
	m_time = 0;
	//e_num = 0;
}

//アクション
void EnemyAppear::Action()
{
	//時間経過
	//代入し続ける?させない方法はある？
	int StageID = ((UserData*)Save::GetData())->Stage + 1;


	m_time++;
	switch (StageID)
	{


	case 1:
	{
		if (m_time == 100)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

			//e_num++;

		}

		else if (m_time == 200)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);
			//e_num++;
		}
		else if (m_time == 350)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 400)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}

		else if (m_time == 500)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 600)
		{

			CObjEnemy* obj = new CObjEnemy(799, 194);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}

		else if (m_time == 650)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}

		else if (m_time == 750)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);
			obj = new CObjEnemy(799, 190);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 800)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);


		}
		else if (m_time == 850)
		{

			CObjEnemy* obj = new CObjEnemy(799, 190);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 950)
		{

			CObjEnemy* obj = new CObjEnemy(799, 190);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}

		else if (m_time == 1050)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}

		else if (m_time == 1100)
		{

			CObjEnemy2* obj = new CObjEnemy2(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		}

		else if (m_time == 1200)
		{

			CObjEnemy2* obj = new CObjEnemy2(799, 190);
			Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		}
		else if (m_time == 1300)
		{

		CObjEnemy2* obj = new CObjEnemy2(799, 190);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		}

		else if (m_time == 1600)
		{

		CObjEnemy2* obj = new CObjEnemy2(799, 190);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		}
		else if (m_time == 1650)
		{

		CObjEnemy* obj = new CObjEnemy(799, 480);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		}
		else if (m_time == 1700)
		{

		CObjEnemy* obj = new CObjEnemy(799, 190);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		}
		else if (m_time == 1750)
		{

		CObjEnemy* obj = new CObjEnemy(799, 480);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		}
		else if (m_time == 2100)
		{

		CObjEnemy* obj = new CObjEnemy(799, 480);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		}

		break;
	}
	}

}

//ドロー
void EnemyAppear::Draw()
{
	float c[4] = { 0.0f,0.0f,0.0f,1.0f };
	wchar_t str[128];
	
	swprintf_s(str, L"タイム:%d", m_time);//整数を文字列か

	Font::StrDraw(str, 2, 120, 24, c);
}

//int EnemyAppear::GetNUM()
//{
//	return e_num;
//}