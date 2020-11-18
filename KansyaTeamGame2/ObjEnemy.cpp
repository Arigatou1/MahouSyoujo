//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "ObjEnemy.h"
#include "GameL\UserData.h"

#include "GameL\UserData.h"
#include "GameL/Audio.h"


//�g�p����l�[���x�[�X
using namespace GameL;

//�R���X�g���N�^
CObjEnemy::CObjEnemy(float x, float y,float vx,float vy)
{
	m_ex = x;
	m_ey = y;
	m_vx = vx;
	m_vy = vy;
}
//�C�j�V�����C�Y
void CObjEnemy::Init()
{
	
	e1_damege = 0;
	e1_atk = 0.3;
	e1_time = 0;
	e_hp=5;

	//�ő�HP
	e_hp = 15;
	
	//�G1�̌̖�
	e1_num = 0;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	e1_hit_up = false;
	e1_hit_down = false;
	e1_hit_left = false;
	e1_hit_right = false;

	e1_xsize = 64.0f;
	e1_ysize = 64.0f;

	e1_t = true;

	//�����蔻��p��HITBOX���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 50, 50, ELEMENT_ENEMY, OBJ_ENEMY, 10);

}

//�A�N�V����
void CObjEnemy::Action()
{
	e1_time++;

	//�}�i�̈ʒu�Œ�~
	CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if (obj != nullptr)
	{
		float m_mx = obj->GetX();
		if (e1_hit_down == true)
		{

			if (m_mx + 64.0f <= m_ex)
				m_vx = -1.5f;
			else if (m_mx - 64.0f >= m_ex)
				m_vx = 1.5f;
			else
				m_vx = 0;
		}

		
		//�W�����v
		if (e1_hit_right == true)
		{
			m_ex = m_ex - 5.0f;
			m_ey = m_ey - 60.0f;
		}
		else if (e1_hit_left == true)
		{
			m_ex = m_ex + 5.0f;
			m_ey = m_ey - 60.0f;
		}
	}

	//�o���A�̏��
	CObjBarrier* obj_barrier = (CObjBarrier*)Objs::GetObj(OBJ_BARRIER);
	if (obj_barrier != nullptr)
	{
		b_mx = obj_barrier->GetBX();

		if (m_ex == b_mx - 48.0f || m_ex == b_mx + 128.0f)
		{
			m_vx = 0;
			m_vy = 0;
		}

	}

	//�d��
	m_vy += 9.8 / (16.0f);

	//m_vx�̑��x�ňړ�
	m_ex += m_vx;
	m_ey += m_vy;

	//HitBOx�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey+14);


	CObjBlock* obj_block1 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	obj_block1->BlockHit(&m_ex, &m_ey,
		&e1_hit_up, &e1_hit_down, &e1_hit_left, &e1_hit_right,
		&m_vx, &m_vy);

	//�}�i�ɓ�����ƃJ�E���g��0�ɂȂ�
	if (hit->CheckObjNameHit(OBJ_MANA) != nullptr)
	{
		if (e1_t == true)
		{
			e1_t = false;
		}


	}


//	if (e1_time % 96 == 32)
//	{
//		e1_atk = 0.00;
//	}
//	else if (e1_time % 96 == 0)
//	{
//		e1_atk = 0.04;
//	}


	if (hit->CheckObjNameHit(OBJ_HOMINGBULLET) != nullptr)
	{
		e_hp -= 3;
		CObjHomingBullet* obj_homing = (CObjHomingBullet*)Objs::GetObj(OBJ_HOMINGBULLET);
		e1_damege = obj_homing->GetM_ATK();

		if (e_hp <= 0) 
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			
			//�����X�^�[���|���ꂽ���̌��ʉ�
			Audio::Start(2);
		}
		
		//Amount++;
	}

	if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr)
	{
		e_hp -= 10;
		CObjAllBullet* obj_all = (CObjAllBullet*)Objs::GetObj(OBJ_ALLBULLET);
		e1_damege = obj_all->GetZ_ATK();
	}

	
	if (hit->CheckObjNameHit(OBJ_SWORD) != nullptr)
	{
		CObjSword* obj_sword = (CObjSword*)Objs::GetObj(OBJ_SWORD);
		e_hp -= obj_sword->GetAttackPower();
	}
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		CObjBullet* obj_bullet = (CObjBullet*)Objs::GetObj(OBJ_BULLET);
		e_hp -= obj_bullet->GetAttackPower();
	}

	//hp��0�ɂȂ�Ə���
	if(	e_hp <= 0)
	{
		//�����X�^�[���|���ꂽ���̌��ʉ�
		Audio::Start(2);

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		
		//Amount++;
	}

}

//�h���[
void CObjEnemy::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 320.0f;
	src.m_left   = 0.0f;
	src.m_right  = 64.0f;
	src.m_bottom = 384.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top    = m_ey+14;
	dst.m_left	 = m_ex+50.0f;
	dst.m_right  = m_ex + 0.0f;
	dst.m_bottom = m_ey + 64.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

//int CObjEnemy::EneAmo()
//{
//	return Amount;
//}
float CObjEnemy::GetE1_ATK()
{
	return e1_atk;
}


/*
void CObjEnemy::CObjEnemy_NUM()
{
	e1_time++;

	//HitBOx�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey + 14);


	CObjBlock* obj_block1 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	obj_block1->BlockHit(&m_ex, &m_ey,
		&e1_hit_up, &e1_hit_down, &e1_hit_left, &e1_hit_right,
		&m_vx, &m_vy);

	//�}�i�ɓ�����ƃJ�E���g��0�ɂȂ�
	if (hit->CheckObjNameHit(OBJ_MANA) != nullptr)
	{
		if (e1_t == true)
		{
			e1_t = false;
		}
	}


	if (e1_time % 96 == 32)
	{
		e1_atk = 0.00;
	}
	else if (e1_time % 96 == 0)
	{
		e1_atk = 0.04;
	}


	
	//hp��0�ɂȂ�Ə���
	if (e_hp <= 0)
	{
		//�����X�^�[���|���ꂽ���̌��ʉ�
		Audio::Start(2);

		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//Amount++;
	}
}
*/