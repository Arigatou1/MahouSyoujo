//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjGameClear.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameClear::Init()
{
	m_key_flag = false;//�L�[�t���O
}

//�A�N�V����
void CObjGameClear::Action()
{
	//�G���^�[�L�[�������ăV�[��:�Q�[��Title�Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		
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

	Font::StrDraw(L"GAME CLEAR", 200, 200, 96, c);

}