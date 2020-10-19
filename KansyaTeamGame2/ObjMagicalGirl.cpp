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
	m_gx = 0.0f;//�ʒu�i��l���̈ʒu�������H�j
	m_gy = 0.0f;

	m_vx = 0.0f;//�ړ��x�N�g��
	m_vy = 0.0f;

	m_postrue = 1.0f;//�E����0.0f ������1.0f
}

//�A�N�V����
void CObjMagicalGirl::Action()
{
	//�ړ��x�N�g���̔j��
	m_vx = 0.0f;
	m_vy = 0.0f;

	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_postrue = 1.0f;
	}

	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_postrue = 0.0f;
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
	src.m_right  = 64.0f;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top	 = 0.0f + m_gy;
	dst.m_left   = (        64.0f * m_postrue);
	dst.m_right  = (64.0f - 64.0f * m_postrue);
	dst.m_bottom = 64.0f + m_gy;

	//�`��
	Draw::Draw(0,&src,&dst,c,0.0f);
}