//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

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

	m_vx = 0;
	m_vy = 0;

	hit_up = false;
	hit_down = false;
	hit_left = false;
	hit_right = false;
	//�����蔻��p��HITBOX���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_ENEMY3, 1);
}

//�A�N�V����
void CObjEnemy3::Action()
{
	//���C
	//m_vx += -(m_vx * 0.098);
	//���R�����^��
	m_vy += 9.8 / (16.0f);


	m_ey += m_vy;
	//����̈ʒu�Œ�~�i�}�i�̏����������Ă�肽���jm_ex=480�����傤��
	if (m_ey == 410)
	{
		m_vy = 0.0f;

	}

	//�W�����v
	/*if (hit_down==true&&jump==true)
	{
		m_vy += 10;
		jump == false;
	}
	else
	{
		jump == true;
	}*/

	//HitBOx�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex + 10.0f, m_ey+10.0f);

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
void CObjEnemy3::Draw()
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
	dst.m_top =m_ey;
	dst.m_left = m_ex;
	dst.m_right =  m_ex+64.0f;
	dst.m_bottom =  m_ey+64.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}