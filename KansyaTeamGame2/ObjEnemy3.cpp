//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjEnemy3.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjEnemy3::CObjEnemy3(float x,float y)
{
	m_ex = x;
	m_ey = y;
	
}

//�C�j�V�����C�Y
void CObjEnemy3::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_posture = 1.0f; //�݂��ނ�0.0f�@������1.0f
}

//�A�N�V����
void CObjEnemy3::Action()
{
	m_ex += m_vx;
}

//�h���[
void CObjEnemy3::Draw()
{
	
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 370.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 434.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top =m_ex;
	dst.m_left = m_ey;
	dst.m_right =  m_ey+50.0f;
	dst.m_bottom =  m_ex+50.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}