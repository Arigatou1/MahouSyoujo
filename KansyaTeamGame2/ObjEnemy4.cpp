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

}

//�A�N�V����
void CObjEnemy4::Action()
{
	m_vx = -1.0f;
	m_vy = sin(3.14 / 180 * m_r);

	//�p�x�v�Z
	m_r += 2.0f;

	//360�K�ŏ����l�ɖ߂�
	if (m_r > 360.0f)
		m_r = 0.0f;
	//�ړ�����
	m_vx = -1.0f;
	m_vy = sin(3.14 / 180 * m_r);//sin�Ƃ����߂�m_vy�ɓ����
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