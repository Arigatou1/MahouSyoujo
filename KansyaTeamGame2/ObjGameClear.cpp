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
	StageID = ((UserData*)Save::GetData())->Stage;
	((UserData*)Save::GetData())->Clear_Flag[StageID+1] = true;
}

//�A�N�V����
void CObjGameClear::Action()
{
	

	//�X�R�A���v�Z
//	((UserData*)Save::GetData())->Score =
//		(((UserData*)Save::GetData())->HeroHP * 40 + ((UserData*)Save::GetData())->ManaHP * 60);

	//��������ۑ�
//	if (((UserData*)Save::GetData())->Score >
//		((UserData*)Save::GetData())->ScoreData[StageID])
//	{		
//		((UserData*)Save::GetData())->ScoreData[StageID]
//			= ((UserData*)Save::GetData())->Score;
//	}

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
	swprintf_s(str, L"�X�R�A:%d", ((UserData*)Save::GetData())->Score);//�����𕶎���
	Font::StrDraw(str, 300, 2, 24, c);

}