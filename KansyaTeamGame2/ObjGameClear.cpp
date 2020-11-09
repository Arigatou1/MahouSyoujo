//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "GameL\UserData.h"
#include "ObjGameClear.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameClear::Init()
{
	//Score = 0;
	
	//���݂̃n�C�X�R�A���������ꍇ���ʂ�ۑ�
	if (((UserData*)Save::GetData())->HHP >
		((UserData*)Save::GetData())->ScoreData[((UserData*)Save::GetData())->Stage])

	{
		//�X�R�A��ۑ�
		((UserData*)Save::GetData())->ScoreData[((UserData*)Save::GetData())->Stage]
			= ((UserData*)Save::GetData())->HHP;

	}
	Save::Seve();//�Z�[�u
}

//�A�N�V����
void CObjGameClear::Action()
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

	else
	{
		m_key_flag = true;
	}

}

//�h���[
void CObjGameClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"GAME CLEAR!", 200, 200, 96, c);


	

	wchar_t str[128];
	swprintf_s(str, L"�X�R�A:%d", ((UserData*)Save::GetData())->HHP);//�����𕶎���
	Font::StrDraw(str, 300, 2, 24, c);

}