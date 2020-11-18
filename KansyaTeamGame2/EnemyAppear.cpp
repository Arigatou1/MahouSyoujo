//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "GameL/SceneObjManager.h"
#include "EnemyAppear.h"
#include "GameL\UserData.h"


//�g�p����l�[���x�[�X
using namespace GameL;


//�C�j�V�����C�Y
void EnemyAppear::Init()
{
	m_time = 0;
	//e_num = 0;
}

//�A�N�V����
void EnemyAppear::Action()
{
	//���Ԍo��
	//�����������?�����Ȃ����@�͂���H
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


		break;
	}
	}

}

//�h���[
void EnemyAppear::Draw()
{
	
}

//int EnemyAppear::GetNUM()
//{
//	return e_num;
//}