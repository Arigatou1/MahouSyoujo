//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjModeSelect.h"
#include "GameL\WinInputs.h"
#include "ObjMenuBlock.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjModeSelect::Init()
{
	m_key_flag = false;//�L�[�t���O
	cursor_x = 40;
	cursor_y = 96;
	nowSelect = 0;
}

//�A�N�V����
void CObjModeSelect::Action()
{
	//���[�h�I�����
	//������J�[�\���̏ꏊ����ʒu���擾���A
	//���[�h�ݒ肷��

	nowSelect = ((cursor_x - 40) / 400) ;

	//cursor_x = 40,440
	//�J�[�\���̏����ʒu��40�Ȃ̂ŁA
	//440����40�������A400���o���A400�Ŋ��邱�Ƃ�1���o�Ă���B
	

	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			if (nowSelect == 0)
			{
				this->SetStatus(false);
				//���j���[�I�u�W�F�N�g�쐬
				CObjStageSelect* obj = new CObjStageSelect();
				Objs::InsertObj(obj, OBJ_STAGESELECT, 0);
			}
			
			m_key_flag = false;
		}
	}
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		if (m_key_flag == true)
		{
			cursor_x += 400;
			m_key_flag = false;
		}
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		if (m_key_flag == true)
		{
			cursor_x -= 400;
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}

	//�J�[�\������ʔ����s���Ȃ�����
	if (cursor_x > 440)
	{
		cursor_x = 440;
	}
	else if (cursor_x < 40)
	{
		cursor_x = 40;
	}
}

//�h���[
void CObjModeSelect::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	//�`��J���[���

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

/*	for (int i = 0; i < 2; i++)
	{
		c[1] = 0.0f;
		c[2] = 0.0f;
		dst.m_top = 96;
		dst.m_left=40 + (i * 400);
		dst.m_right =dst.m_left+320;
		dst.m_bottom = dst.m_top + 256;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	c[2] = 1.0f;
	c[0] = 0.5f;
	dst.m_top = 450;
	dst.m_left = 200;
	dst.m_right = dst.m_left + 400;
	dst.m_bottom = dst.m_top + 72;

	Draw::Draw(0, &src, &dst, c, 0.0f);
	*/
	//�J�[�\���`��

	MenuBlockDraw(0, 0, 64, 64,1,1,1,1);

	c[0] = 1.0f;
	c[1] = 0.8f;
	c[2] = 0.0f;

	dst.m_top = cursor_y;
	dst.m_left = cursor_x;
	dst.m_right = dst.m_left + 320;
	dst.m_bottom = dst.m_top + 256;
	
	Draw::Draw(0, &src, &dst, c, 0.0f);

	c[0] = 1.0f;
	c[1] = 1.0f;
	c[2] = 1.0f;
	Font::StrDraw(L"GAME ModeSelect", 2, 2, 32, c);

	Font::StrDraw(L"�X�e�[�W�Z���N�g", 72, 200, 32, c);

	Font::StrDraw(L"�G���h���X���[�h", 472, 200, 32, c);
}

//MenuBlockDraw�֐�
