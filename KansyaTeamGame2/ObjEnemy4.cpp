#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include"ObjEnemy4.h"

//�C�j�V�����C�Y
void CObjEnemy4::Init()
{

}

//�A�N�V����
void CObjEnemy4::Action()
{

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
	dst.m_right = m_ex + 50.0f;
	dst.m_bottom = m_ey + 50.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}