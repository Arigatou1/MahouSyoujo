//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "ObjMenuBlock.h"
#include "GameHead.h"
#include "ObjStageSelect.h"
#include "GameL\WinInputs.h"
#include "GameL\UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjStageSelect::Init()
{
	m_key_flag = false;//�L�[�t���O
	cursor_x = 140;
	cursor_y = 32;
	StageID = 0;
	PageID = ((UserData*)Save::GetData())->Stage / 4;
	MaxPage = 4;
}

//�A�N�V����
void CObjStageSelect::Action()
{
	//�X�e�[�W�I�����
	//������J�[�\���̏ꏊ����ʒu���擾���A
	//�X�e�[�WID���v�Z���ݒ肷��ɂ́H�H

	((UserData*)Save::GetData())->Stage = ((cursor_y - 32) / 144)+1 +(PageID*4);

	//cursor_y = 16,96,176,256,336,416,496
	//�J�[�\���̏����ʒu��16�Ȃ̂ŁA
	//96����16�������A80���o���A80�Ŋ��邱�Ƃ�1���o�Ă���B
	//�����1�𑫂��B

	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else if (Input::GetVKey(VK_UP) == true)
	{
		if (m_key_flag == true)
		{
			cursor_y -= 144;
			m_key_flag = false;
		}
	}
	else if (Input::GetVKey(VK_DOWN) == true )
	{
		if (m_key_flag == true)
		{
			cursor_y += 144;
			m_key_flag = false;
		}
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		if (m_key_flag == true)
		{
			if (PageID > 0)
				PageID -= 1;
			m_key_flag = false;
		}
	}

	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		if (m_key_flag == true)
		{
			if (PageID < MaxPage )
				PageID += 1;

			m_key_flag = false;
		}
	}

	else
	{
		m_key_flag = true;
	}

	//�J�[�\������ʊO�����Ȃ�����
	if (cursor_y < 32)
		cursor_y = 32;

	if (cursor_y > 464)
		cursor_y = 464;

	

}

//�h���[
void CObjStageSelect::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };



	
	
	//�X�e�[�W�Z���N�g
	for (int i = 0; i < 4; i++)
	{
		MenuBlockDraw(140, i * 144.0f + 32.0f, 512, 128, 1, 0, 0, 1);
		
	}


	MenuBlockDraw(cursor_x, cursor_y, 512, 128, 1, 0.8f, 0, 1);


	for (int i = 0; i < 2; i++)
		MenuBlockDraw(16 + i * 674, 200, 96, 200, 0, 0, 1, 1);
	
	
	for (int i = 0; i < 4; i++)
	{
		wchar_t str[128];
		swprintf_s(str,L"�X�e�[�W%d",i+1+ (PageID * 4));
		
		Font::StrDraw(str, 176, 48+(i*144), 96, c);
	}

	Font::StrDraw(L"��", 40, 284, 48, c);

	Font::StrDraw(L"��", 712, 284, 48, c);

	wchar_t Score[128];
	swprintf_s(Score, L"�X�R�A:%d", ((UserData*)Save::GetData())->ScoreData[((UserData*)Save::GetData())->Stage]);
	Font::StrDraw(Score, 2,2, 48, c);
}

