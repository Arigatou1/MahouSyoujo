//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "ObjEnemy2.h"

//�g�p����l�[���x�[�X
using namespace GameL;


//�R���X�g���N�^
CObjEnemy2::CObjEnemy2(float x, float y)
{
	m_ex = x;
	m_ey = y;
}

//�C�j�V�����C�Y
void CObjEnemy2::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	e1_hit_up = false;
	e1_hit_down = false;
	e1_hit_left = false;
	e1_hit_right = false;


	//block�Ƃ̏Փˏ�Ԋm�F�p
	e2_hit_up = false;
	e2_hit_down = false;
	e2_hit_left = false;
	e2_hit_right = false;

	e2_xsize = 50.0f;
	e2_ysize = 50.0f;

	e2_t = true;
	//�����蔻��p��HITBOX���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 50, 50, ELEMENT_ENEMY, OBJ_ENEMY2, 10);
	//Amount = 0;

	e_hp = 25.0f;
	damage = ((UserData*)Save::GetData())->Diffculty * 0.5;
}

//�A�N�V����
void CObjEnemy2::Action()
{

	e2_time++;

	if (e2_time % 96 == 32)
	{
		e2_atk = 0.00;
	}
	else if (e2_time % 96 == 0)
	{
		e2_atk = 0.04;
	}


	//HitBOx�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey);

	//�d��
	m_vy += 9.8 / (16.0f);


	CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if (obj != nullptr)
	{
		float m_mx = obj->GetX();

		if (m_mx <= m_ex)
			m_vx = -1.0f;
		else if (m_mx >= m_ex)
			m_vx = 1.0f;
		else
			m_vx = 0;
	}
		
		//�o���A�o�Ă鎞�����~�܂�
		CObjBarrier* obj_barrier = (CObjBarrier*)Objs::GetObj(OBJ_BARRIER);
		if (obj_barrier != nullptr)
		{
			b_mx = obj_barrier->GetBX();

			if (m_ex == b_mx - 48.0f || m_ex == b_mx + 160.0f)
			{
				m_vx = 0;
			}
		}

		//m_vx�̑��x�ňړ�
		m_ex += m_vx;
		m_ey += m_vy;

		CObjBlock* obj_block1 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		obj_block1->BlockHit(&m_ex, &m_ey,
			&e2_hit_up, &e2_hit_down, &e2_hit_left, &e2_hit_right,
			&m_vx, &m_vy);

		//�}�i�ɓ�����ƃJ�E���g��0�ɂȂ�
		if (hit->CheckObjNameHit(OBJ_MANA) != nullptr)
		{
			if (e2_t == true)
			{
				e2_time = 0;
				e2_t = false;
			}
		}

		if (hit->CheckObjNameHit(OBJ_HOMINGBULLET) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			//Amount++;
		}

		if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			//Amount++;
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
		if (e_hp <= 0)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);

			//Amount++;
		}

		

	}

//�h���[
void CObjEnemy2::Draw()
{
	//�`��J���[���
	float c[4] = { 0.3f,1.0f,0.3f,1.0f };

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
float CObjEnemy2::GetE2_ATK()
{
	return e2_atk;
}