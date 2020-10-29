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
	m_vx = 0.0f;
	m_vy = -1.0f;
	//�����蔻��p��HITBOX���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY3, 1);
}

//�A�N�V����
void CObjEnemy3::Action()
{
	m_ey += m_vy;
	//����̈ʒu�Œ�~�i�}�i�̏����������Ă�肽���jm_ex=480�����傤��
	if (m_ey == 420)
	{
		m_vy = 0.0f;

	}


	//HitBOx�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex - 50.0f, m_ey);

	/*if (hit->CheckObjNameHit(OBJ_HOMINGBULLET) != nullptr)
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
	}*/
}

//�h���[
void CObjEnemy3::Draw()
{
	
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 385.0f;
	src.m_left = 4.0f;
	src.m_right = 61.0f;
	src.m_bottom = 447.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top =m_ex;
	dst.m_left = m_ey;
	dst.m_right =  m_ey+60.0f;
	dst.m_bottom =  m_ex+60.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}