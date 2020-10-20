//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjMagicalGirl.h"
//#include "��l���̃w�b�_�[�H"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMagicalGirl::Init()
{
	m_mp = 10;//MP����100

	m_postrue = 1.0f;//�E����0.0f ������1.0f

	m_mtime = 0;
}

//�A�N�V����
void CObjMagicalGirl::Action()
{
	m_mtime++;

	if (m_mp < 100)
	{
		if (m_mtime % 60 == 0)
		{
			m_mtime = 0;
			m_mp++;
		}
	}

	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_postrue = 0.0f;
	}

	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_postrue = 1.0f;
	}
}

//�h���[
void CObjMagicalGirl::Draw()
{
	//�`��J���[
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 50.0f;
	src.m_bottom = 50.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top	 = 0.0f;
	dst.m_left   = ( 50.0f + 50.0f * m_postrue);
	dst.m_right  = (100.0f - 50.0f * m_postrue);
	dst.m_bottom = 50.0f;

	//�`��
	Draw::Draw(0,&src,&dst,c,0.0f);
}