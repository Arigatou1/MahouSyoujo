//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include "ObjSmallSlim.h"


//�g�p����l�[���x�[�X
using namespace GameL;

//�R���X�g���N�^
CObjSmallSlim::CObjSmallSlim(float x, float y)
{
	m_ex = x;
	m_ey = y;
}
//�C�j�V�����C�Y
void CObjSmallSlim::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	
	e5_hp = 5;

	e_jkn = 100;
	e_time = e_jkn;
	e_mtk = false;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	e1_hit_up = false;
	e1_hit_down = false;
	e1_hit_left = false;
	e1_hit_right = false;

	e1_xsize = 32;
	//����ȏ㉺����ƃu���b�N�Ɉ���������..?

	e1_ysize = 32+12;

	e_damege = 0;
	//�����蔻��p��HITBOX���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 32, 32, ELEMENT_ENEMY, OBJ_SMALLSLIM, 10);

}

//�A�N�V����
void CObjSmallSlim::Action()
{
	//m_vx�̑��x�ňړ�
	m_ex += m_vx;
	m_ey += m_vy;


	CObjBlock* obj_block1 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	obj_block1->BlockHit(&m_ex, &m_ey,
		&e1_hit_up, &e1_hit_down, &e1_hit_left, &e1_hit_right,
		&m_vx, &m_vy);

	//�d��
	m_vy += 9.8 / (16.0f);


	//HitBOx�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey);


	CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if (obj != nullptr)
	{
		float m_mx = obj->GetX();

		if (m_mx <= m_ex)
			m_vx = -2.0f;
		else if (m_mx >= m_ex)
			m_vx = 2.0f;
		else
			m_vx = 0;
	}

	//�o���A�o�Ă鎞�����~�܂�
	CObjBarrier* obj_barrier = (CObjBarrier*)Objs::GetObj(OBJ_BARRIER);
	if (obj_barrier != nullptr)
	{
		b_mx = obj_barrier->GetBX();

		if (m_ex == b_mx - 48.0f)
		{
			m_vx = 0;
		}
		else if (m_ex == b_mx + 160.0f)
		{
			m_vx = 0;
		}

	}

	//�e��������Ώ���
	if (hit->CheckObjNameHit(OBJ_HOMINGBULLET) != nullptr)
	{
		e5_hp = 3;
		CObjHomingBullet* obj_homing = (CObjHomingBullet*)Objs::GetObj(OBJ_HOMINGBULLET);
		e_damege = obj_homing->GetM_ATK();

		this->SetStatus(false);
		Hits::DeleteHitBox(this);


		//Amount++;
	}

	if (hit->CheckObjNameHit(OBJ_SWORD) != nullptr)
	{
		CObjSword* obj_sword = (CObjSword*)Objs::GetObj(OBJ_SWORD);
		e5_hp -= obj_sword->GetAttackPower();
	}
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		e5_hp = 2;
		CObjBullet* obj_bullet = (CObjBullet*)Objs::GetObj(OBJ_BULLET);
		e5_hp -= obj_bullet->GetAttackPower();
	}

	//�S�̍U���̖��@�ɓ�����Ώ���
	if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr)
	{
		e5_hp -= 10;
		CObjAllBullet* obj_allb = (CObjAllBullet*)Objs::GetObj(OBJ_ALLBULLET);
		e_damege = obj_allb->GetZ_ATK();
		//Amount++;
	}
	
	if (e5_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�h���[
void CObjSmallSlim::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

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
	dst.m_right = m_ex + 32.0f;
	dst.m_bottom = m_ey + 32.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
