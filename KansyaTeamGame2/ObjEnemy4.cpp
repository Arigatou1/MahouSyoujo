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
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_r = 0.0f;

	//�����蔻��HitBox���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_ENEMY4, 10);

	//Hits::SetHitBox(this, m_ex, m_ey, 128, 128, ELEMENT_ENEMY, OBJ_ENEMY4, 10);
}

//�A�N�V����
void CObjEnemy4::Action()
{
	m_ex -= m_vx;
	/*//�p�x���Z
	m_r += 3.0f;


	//360�K�ŏ����l�ɖ߂�
	if (m_r > 360.0f)
		m_r = 0.0f;


	//�ړ�����
	m_vx = -1.0f;
	m_vy = sin(3.14 / 180 * m_r);//sin�Ƃ����߂�m_vy�ɓ����


	//�x�N�g���̒��������߂�
	float r = 0.0f;
	r = m_vx * m_vx + m_vy * m_vy;
	r = sqrt(r);//r�����[�g�����߂�


	//�������ǂ������ׂ�
	if (r == 0.0f)
	{
		;//�O�Ȃ牽�����Ȃ�
	}
	else
	{
		//���K�����s��
		m_vx = 1.0f / r * m_vy;
		m_vy = 1.0f / r * m_vy;
	}
	
	//�ړ��x�N�g�������W�ɉ��Z����
	m_ex *= m_vx;
	m_ey *= m_vy;*/


	//
	/*CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if (obj != nullptr)
	{
		float m_mx = obj->GetX();

		if (m_mx <= m_ex)
			m_vx = -1.0f;
		else if (m_mx >= m_ex)
			m_vx = 1.0f;
		else
			m_vx = 0;
	}*/

	//
	CObjHero*obj=(CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)
	{
		float m_px = obj->GetX();

		if (m_px <= m_ex)
			m_vx = -1.0f;
		else if (m_px >= m_ex)
			m_vx = 1.0f;
		else
			m_vx = 0;
	}

	//
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex+0.0f, m_ey+0.0f);

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
	src.m_top = 448.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 512.0f;
	
	//�\���ʒu�̐ݒ�
	dst.m_top = m_ey;
	dst.m_left = m_ex;
	dst.m_right = m_ex + 64.0f;
	dst.m_bottom = m_ey + 64.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}