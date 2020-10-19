//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_px = 0;
	m_py = 0;
	m_vx = 0;
	m_vy = 0;
	m_posture = 0;
}

//�A�N�V����
void CObjHero::Action()
{
	//�L�[�������ƈړ�
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 0.1;
		m_posture = 0;
	}
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 0.1;
		m_posture = 1;
	}
	//�ǂ���������Ă��Ȃ��ꍇ�͌���������B
	else
	{
		if (m_vx > 0)//�������ɓ����Ă���Ƃ�
		{
			m_vx -= 0.2;
			if (m_vx <= 0)
				m_vx = 0;
		}
		if (m_vx < 0)//�E�����ɓ����Ă���Ƃ�
		{
			m_vx += 0.2;
			if (m_vx >= 0)
				m_vx = 0;
		}
	}
	

	//�ō����x����
	if (m_vx >= 6)
		m_vx = 6;
	if (m_vx <= -6)
		m_vx = -6;
	m_px += m_vx;
}
//�h���[
void CObjHero::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 128.0f;
	dst.m_left = (64.0*m_posture)+m_px;
	dst.m_right = (64-64.0 * m_posture) + m_px;
	dst.m_bottom = 192.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}