//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

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
	//�O���t�B�b�N�̓ǂݍ���
	Draw::LoadImageW(L"", 0, TEX_SIZE_512);

	//���@�����I�u�W�F�N�g�쐬
	CObjMagicalGirl* obj = new CObjMagicalGirl();
	Objs::InsertObj(obj, OBJ_MAGICALGIRL, 10);
}

//���s�����\�b�h
void CSceneMain::Scene()
{

}

