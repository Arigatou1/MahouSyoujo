//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"

#include "CObjHomingBullet.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjHomingBullet::CObjHomingBullet(float x, float y,float m)
{
	m_bx = x;
	m_by = y;
	m_bpostrue = m;
}

//�C�j�V�����C�Y
void CObjHomingBullet::Init()
{
	m_vx = 0.0f;
}

//�A�N�V����
void CObjHomingBullet::Action()
{
	m_vx += 1.0f;
	m_bx += m_vx;

	//�̈�O�ɏo����e�ۂ�j������
	if (m_bx > 800.0f)
	{
		this->SetStatus(false);
	}

	if (m_bx < 0.0f)
	{
		this->SetStatus(false);
	}

	if (m_by > 600.0f)
	{
		this->SetStatus(false);
	}

	if (m_by < 0.0f)
	{
		this->SetStatus(false);
	}
}

//�h���[
void CObjHomingBullet::Draw()
{
	//�`��J���[
	float c[4] = { 1.0f,5.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 50.0f;
	src.m_bottom = 50.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    = m_by - 50.0f;
	dst.m_left   = (m_bx - 50.f + 50.0f * m_bpostrue);
	dst.m_right  = (m_bx - 50.0f * m_bpostrue);
	dst.m_bottom = m_by;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}