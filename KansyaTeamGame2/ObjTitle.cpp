//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjTitle.h"
#include "GameL\MultiThread.h"
#include "GameL\UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_key_flag = false;//�L�[�t���O

	static bool init_stage = false;
	if (init_stage == false) {
		((UserData*)Save::GetData())->Stage = 1;
		init_stage = true;

		for (int i = 0; i < 20;i++)
		((UserData*)Save::GetData())->ScoreData[i] = 0;
		//���[�h
		Save::Open();//���t�H���_[UserData����f�[�^�擾]
	}

	if (init_stage == true)
	{
		Save::Seve();
	}
}

//�A�N�V����
void CObjTitle::Action()
{
	
	//�G���^�[�L�[�������ăV�[��:�Q�[��Menu�Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMenu());
			m_key_flag = false;
		}
	}
	//�f�o�b�O�p �Z�[�u�f�[�^�폜
	else if (Input::GetVKey('3') == true)
	{
		if (m_key_flag == true)
		{
			for (int i = 0; i < 20; i++)
				((UserData*)Save::GetData())->ScoreData[i] = 0;
			Save::Seve();

			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"�}�W�J���E�H�[�Y", 116, 200, 64, c);

	Font::StrDraw(L"Push [Enter] Key", 280, 400, 32, c);

	if (Input::GetVKey('3') == true)
	{
		Font::StrDraw(L"�Z�[�u�f�[�^���폜���܂���", 0, 0, 32, c);
	}
}