//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjMenu.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMenu::Init()
{
	m_key_flag = false;//�L�[�t���O
}

//�A�N�V����
void CObjMenu::Action()
{
	
}

//�h���[
void CObjMenu::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	

	//�`��J���[���


	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 16.0f;

	for (int i = 0; i < 5; i++)
	{
		//�\���ʒu�̐ݒ�
		dst.m_top = i * 64.0f;
		dst.m_left =0.0f;
		dst.m_right = dst.m_left + 256.0f;
		dst.m_bottom = dst.m_top + 64.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}

	//�`��
	
	Font::StrDraw(L"GAME Menu", 2, 2, 32, c);
}