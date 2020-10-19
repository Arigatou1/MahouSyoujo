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
	m_anime = 0;
	m_anitime = 0;
	atk_anime = 0;
	atk_anitime = 0;

}

//�A�N�V����
void CObjHero::Action()
{


	//�L�[�������ƈړ�
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 0.1;
		m_posture = 0;

		m_anitime += 1;

	}
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 0.1;
		m_posture = 1;

		m_anitime += 1;

	
	}
	//�ǂ���������Ă��Ȃ��ꍇ�͌���������B
	else
	{

		m_anime = 0;
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
	if (m_anitime >= 10)
	{
		m_anime++;

		m_anitime = 0;
	}

	if (m_anime > 1)
		m_anime = 0;
	//�ō����x����
	if (m_vx >= 6)
		m_vx = 6;
	if (m_vx <= -6)
		m_vx = -6;
	m_px += m_vx;

	//�L�[�������ƈړ�
	if (Input::GetVKey('X') == true)
	{
		atk_anime = 1;
	}
	else
		atk_anime = 0;
}
//�h���[
void CObjHero::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top =(atk_anime*50)+0.0f;
	src.m_left =(m_anime*50)+0.0f;
	src.m_right =(m_anime*50)+50.0f;
	src.m_bottom = (atk_anime * 50) + 50.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left =(50.0f*m_posture)+m_px;
	dst.m_right = (50.0f - 50*m_posture )+ m_px;
	dst.m_bottom = 50.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}