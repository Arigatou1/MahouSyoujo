//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//���������\�b�h
void CSceneMain::InitScene()
{
	//HP�pFont�쐬
	Font::SetStrTex(L"1234567890/.+-�c��G�̐�:");


	//�O���t�B�b�N�̓ǂݍ���
	Draw::LoadImageW(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"Gauge.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"BackGround.png", 2, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 12);
	

	//�Q�[�W�I�u�W�F�N�g�쐬
	CObjGaugeBase* obj_gb = new CObjGaugeBase();
	Objs::InsertObj(obj_gb, OBJ_GAUGEBASE, 50);

	//HP�Q�[�W�I�u�W�F�N�g�쐬
	CObjGaugeHP* obj_ghp = new CObjGaugeHP();
	Objs::InsertObj(obj_ghp, OBJ_GAUGEHP, 51);

	//���@�����I�u�W�F�N�g�쐬
	CObjMagicalGirl* obj_magicalgirl = new CObjMagicalGirl();
	Objs::InsertObj(obj_magicalgirl, OBJ_MAGICALGIRL, 11);
	
	

	//mana�쐬
	CObjMana* obj_mana = new CObjMana();
	Objs::InsertObj(obj_mana, OBJ_MANA, 10);

	//MP�Q�[�W�I�u�W�F�N�g�쐬
	CObjGaugeMP* obj_gmp = new CObjGaugeMP();
	Objs::InsertObj(obj_gmp, OBJ_GAUGEMP, 50);
	
	//�w�i�I�u�W�F�N�g�쐬
	CObjBackGround* obj_bg = new CObjBackGround();
	Objs::InsertObj(obj_bg, OBJ_BG, 1);


	//�^�C��������
	m_time = 0;
}

//���s�����\�b�h
void CSceneMain::Scene()
{
	m_time++;

	if (m_time == 30)
	{
		CObjEnemy* obj = new CObjEnemy(800, 400);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

	}
	else if (m_time == 60)
	{
		CObjEnemy* obj = new CObjEnemy(800, 450);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

	}
	else if (m_time == 160)
	{
		CObjEnemy2* obj = new CObjEnemy2(800, 400);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

	}
	else if (m_time == 220)
	{
		CObjEnemy2* obj;
		obj = new CObjEnemy2(800, 450);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);
		obj = new CObjEnemy2(800, 350);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

	}

	else if (m_time == 280)
	{
		CObjEnemy* obj = new CObjEnemy(800, 390);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

	}
	else if (m_time == 300)
	{
		CObjEnemy* obj = new CObjEnemy(0, 390);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

	}
	else if (m_time == 350)
	{
		CObjEnemy* obj = new CObjEnemy(0, 440);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

	}
	else if (m_time == 400)
	{
		CObjEnemy* obj = new CObjEnemy(0, 340);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

	}
	else if (m_time == 450)
	{
		CObjEnemy* obj;
		obj = new CObjEnemy(0, 500);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);
		obj = new CObjEnemy(800, 450);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

	}
	else if (m_time == 500)
	{
		CObjEnemy* obj;
		obj = new CObjEnemy(0, 450);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);
		obj = new CObjEnemy(800, 400);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

	}
	else if (m_time == 550)
	{
		CObjEnemy* obj;
		obj = new CObjEnemy(0, 475);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);
		obj = new CObjEnemy(800, 425);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

	}
}

