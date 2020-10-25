//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include "ObjEnemy2.h"

//�g�p����l�[���x�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjEnemy2::Init()
{
	m_ex = 600.0f;
	m_ey = 440.0f;
	m_vx = -0.5f;
	m_vy = 0.0f;
	//�����蔻��p��HITBOX���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 50, 50, ELEMENT_ENEMY, OBJ_ENEMY2, 10);
	Amount = 0;
}

//�A�N�V����
void CObjEnemy2::Action()
{
	//m_vx�̑��x�ňړ�
	m_ex += m_vx;

	//����̈ʒu�Œ�~�i�}�i�̏����������Ă�肽���j
	if (m_ex == 400)
	{
		m_vx = 0.0f;
	}

	//HitBOx�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex-50.0f, m_ey );

	if (hit->CheckObjNameHit(OBJ_HOMINGBULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		Amount++;
	}

	if (hit->CheckObjNameHit(OBJ_SWORD) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		Amount++;
	}
}

//�h���[
void CObjEnemy2::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 384.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 448.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = m_ey;
	dst.m_left = m_ex - 50.0f;
	dst.m_right = m_ex;
	dst.m_bottom = m_ey + 50.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
