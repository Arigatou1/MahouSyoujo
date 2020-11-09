//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjCustomize.h"
#include "GameL\WinInputs.h"
#include "ObjMenuBlock.h"
#include "GameL\UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjCustomize::Init()
{
	m_key_flag = false;//�L�[�t���O
	
	cursor_x = 32.0f;
	cursor_y = 64.0f;
	nowSelect = 0;
}

//�A�N�V����
void CObjCustomize::Action()
{
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Save::Seve();

			this->SetStatus(false);
			//���j���[�I�u�W�F�N�g�쐬
			CObjStageSelect* obj = new CObjStageSelect();
			Objs::InsertObj(obj, OBJ_STAGESELECT, 0);
		}
	}

	else if (Input::GetVKey(VK_UP) == true)
	{
		if (m_key_flag == true)
		{
			cursor_y -= 112;
			nowSelect += 1;
			m_key_flag = false;
		}
	}

	else if (Input::GetVKey(VK_DOWN) == true)
	{
		if (m_key_flag == true)
		{
			cursor_y += 112;
			nowSelect -= 1;
			m_key_flag = false;
		}
	}

	else if (Input::GetVKey(VK_LEFT) == true)
	{
		if (m_key_flag == true)
		{
			switch (nowSelect)
			{
			case 0:
				if (((UserData*)Save::GetData())->����==1)
				{
					((UserData*)Save::GetData())->���� = 0;
				}
				break;

			default:

				break;
			}







			m_key_flag = false;
		}
	}

	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		if (m_key_flag == true)
		{
			

			switch (nowSelect)
			{
			case 0:
				if (((UserData*)Save::GetData())->���� == 0)
				{
					((UserData*)Save::GetData())->���� = 1;
				}
				break;

			default:

				break;
			}


			m_key_flag = false;
		}
	}
	else
		m_key_flag = true;
}

//�h���[
void CObjCustomize::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };


	Font::StrDraw(L"GAME Customize", 2, 2, 32, c);

	MenuBlockDraw(32, 64.0f, 728.0f, 96.0f, 1.0f, 0.0f, 0.0f, 1.0f);

	MenuBlockDraw(cursor_x, cursor_y, 728.0f, 96.0f, 1.0f, 0.8f, 0.0f, 1.0f);

	wchar_t str1[128];

	swprintf_s(str1, L"��l���̕���:%d", ((UserData*)Save::GetData())->����);
	Font::StrDraw(str1, 32, 64, 32, c);
}

//MenuBlockDraw�֐�
