//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjModeSelect.h"
#include "GameL\WinInputs.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjModeSelect::Init()
{
	m_key_flag = false;//�L�[�t���O
	
}

//�A�N�V����
void CObjModeSelect::Action()
{
	
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

	for (int i = 0; i < 2; i++)
	{
		dst.m_top=32+(i*64);
		dst.m_left=32;
		dst.m_right = 256 + (i * 64)+64;
		dst.m_bottom = dst.m_top + 64;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}






	

	Font::StrDraw(L"GAME ModeSelect", 2, 2, 32, c);

	
}

