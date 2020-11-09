#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include"ObjEnemy4.h"

CObjEnemy4::CObjEnemy4(float x, float y)
{
	m_ex = x;
	m_ey = y;
}

//�C�j�V�����C�Y
void CObjEnemy4::Init()
{
	m_vx = 1.0f;
	m_r = 0.0f;
	Hits::SetHitBox(this, m_ex, m_ey, 50, 50, ELEMENT_ENEMY, OBJ_ENEMY4, 10);
}

//�A�N�V����
void CObjEnemy4::Action()
{
	m_ex -= m_vx;
	/*m_vx *= 1.5f;
	m_vy *= 1.5f;

	//�ړ�����
	m_vx = -1.0f;
	m_vy = sin(3.14 / 180 * m_r);//sin�Ƃ����߂�m_vy�ɓ����

	//�p�x���Z
	m_r += 2.0f;

	//360�K�ŏ����l�ɖ߂�
	if (m_r > 360.0f)
		m_r = 0.0f;
	
	//�x�N�g���̒��������߂�
	float r = 0.0f;
	r = m_vx + m_vy * m_vy;
	r = sqrt(r);//r�����[�g�����߂�

	if (r == 0.0f)
	{
		;
	}
	else 
{
		m_vx = 1.0f / r * m_vx;
		m_vy = 1.0f / r * m_vy;
	}

	
	//���K�����s��
	m_vx *= 1.0f / r * m_vx;*/

	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey);

	if (hit->CheckObjNameHit(OBJ_HOMINGBULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		//Amount++;
	}

	if (hit->CheckObjNameHit(OBJ_SWORD) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		//Amount++;
	}
}

//�h���[
void CObjEnemy4::Draw()
{
	//�`��J���[���
	float c[4] = { 2.0f,2.0f,2.0f,2.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 320.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 384.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = m_ey;
	dst.m_left = m_ex;
	dst.m_right = m_ex - 50.0f;
	dst.m_bottom = m_ey + 50.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}