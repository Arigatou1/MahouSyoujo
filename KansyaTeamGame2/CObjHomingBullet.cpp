//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
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

	//�����蔻��p��HITBOX���쐬
	Hits::SetHitBox(this, m_bx, m_by, 40, 40, ELEMENT_PLAYER, OBJ_HOMINGBULLET, 10);
}

//�A�N�V����
void CObjHomingBullet::Action()
{
	if (m_bpostrue == 1.0f)
	{
		//�ړ�����
		m_vx = +3.0f;
		m_vy = 0.0f;
		m_bx += m_vx;
		m_by += m_vy;
		//HitBOx�̓��e��ύX
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_bx, m_by + 10.0f);

		if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
	     }
	}
	else if(m_bpostrue == 0.0f)
	{
		m_vx = -3.0f;
		m_vy = 0.0f;
		m_bx += m_vx;
		m_by += m_vy;
		//HitBOx�̓��e��ύX
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_bx+10.0f, m_by+10.0f);

		if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}

		if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}

	//�̈�O�ɏo����e�ۂ�j������
	if (m_bx > 775.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (m_bx < -25.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (m_by > 575.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (m_by < -25.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
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
	dst.m_top    =0.0f  + m_by;
	dst.m_left   =0.0f  + (m_bx + 50.0f * m_bpostrue);
	dst.m_right  =50.0f + (m_bx - 50.0f * m_bpostrue);
	dst.m_bottom =50.0f + m_by;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}