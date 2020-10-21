//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "ObjSword.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_px = 0;
	m_py = 0;
	m_vx = 0;
	m_vy = 0;
	m_posture = 1;
	m_anime = 0;
	m_anitime = 0;
	atk_anime = 0;
	atk_anitime = 0;
	atk_time = 0;
	m_f = true;
	isJump = true;
	max_hp = 20;
	m_hp = max_hp;
	

	//�����蔻��pHitbox���쐬
	Hits::SetHitBox(this, m_px, m_py, 56, 56, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	
	//�e�X�g�pZ�L�[�������ƃW�����v���鏈��
	if (Input::GetVKey('Z') == true&&isJump==true)
	{
		m_vy = -15;
		isJump = false;
	}

	//���C
	m_vy += 9.8 / (16.0f);

	//�L�[�������ƈړ�
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 0.1;
		m_posture = -1;

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

		m_anime = 1;
		m_anitime = 0;
		m_vx = m_vx * 0.9;
	}
	
	//�������̃A�j���[�V���� anitime��10�ɂȂ����Ƃ��A�R�}��1�i�߂�
	if (m_anitime >= 8)
	{
		m_anime++;

		m_anitime = 0;
	}

	if (m_anime >= 4)
		m_anime = 0;

	//�ō����x����
	if (m_vx >= 6)
		m_vx = 6;
	if (m_vx <= -6)
		m_vx = -6;

	//�x�N�g��������W�ɕϊ�
	m_px += m_vx;
	m_py += m_vy;
	

	//test�p�@�U���p
	if (Input::GetVKey('X') == true && m_f==true)
	{
		m_f = false;
		atk_anime = 1;

		CObjSword* obj_b = new CObjSword(m_px, m_py, m_posture,m_f);
		Objs::InsertObj(obj_b, OBJ_SWORD, 1);

	}

	if (m_f == false)
		atk_time++;

	//�U�����Ă��炵�΂炭�A�U�����肪���Ȃ��悤�ɂ��Ă���B
	//��莞�Ԃ��ƁA����悤�ɂ��Ă���B
	if (atk_time >= 13)
	{
		m_f = true;
		atk_time = 0;
		atk_anime = 0;
	}
	




	//test�p�@��ʊO�ɍs���Ȃ��悤��
	if (m_px > 744)
	{
		m_px = 744;
		m_vx = 0;
	}
	else if (m_px < 0)
	{
		m_px = 0;
		m_vx = 0;
	}


	//���̍��W��艺�������Ƃ��A�����ŗ������~�߂�B(�u���b�N�ƃX�e�[�W�҂��B)
	//���̎��A�W�����v�ł���悤�ɂ���B
	if (m_py >= 444)
	{
		m_py = 444;
		m_vy = 0;
		isJump = true;
	}

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);
}
//�h���[
void CObjHero::Draw()
{
	int AniData[4] =
	{
		1,0,2,0,
	};
		//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top =(atk_anime*56)+0.0f;
	src.m_left =(AniData[m_anime]*56)+0.0f;
	src.m_right =(AniData[m_anime] *56)+56.0f;
	src.m_bottom = (atk_anime * 56) + 56.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f+m_py;
	dst.m_left =(28.0f*m_posture)+m_px+28.0f;
	dst.m_right = (-28.0f*m_posture )+ m_px+28.0f;
	dst.m_bottom = 56.0f+m_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

