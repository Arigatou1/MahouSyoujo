//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include "ObjBoss1.h"
#include "GameL/UserData.h"

//�g�p����l�[���x�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBoss1::CObjBoss1(float x, float y)
{
	m_ex = x;
	m_ey = y;
}
//�C�j�V�����C�Y
void CObjBoss1::Init()
{
	m_vx = 0;
	m_vy = 0;


	//block�Ƃ̏Փˏ�Ԋm�F�p
	e1_hit_up = false;
	e1_hit_down = false;
	e1_hit_left = false;
	e1_hit_right = false;

	e1_xsize = 250.0f;
	e1_ysize = 250.0f;

	a_time = 0;
	
	//�����蔻��p��HITBOX���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 250, 250, ELEMENT_ENEMY, OBJ_BOSS1, 10);
}

//�A�N�V����
void CObjBoss1::Action()
{
	//�d��
	m_vy += 9.8 / (16.0f);


	CObjBlock* obj_block1 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	obj_block1->BlockHit(&m_ex, &m_ey,
		&e1_hit_up, &e1_hit_down, &e1_hit_left, &e1_hit_right,
		&m_vx, &m_vy, &e1_xsize, &e1_ysize);
//
	

	//HitBOx�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey);

	a_time++;	
	if (a_time % 500 == 0)
	{
		CObjEnemy* obj = new CObjEnemy(m_ex,m_ey+50,-5,-10);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);
		obj = new CObjEnemy(m_ex, m_ey + 50, -7,0);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);
		obj = new CObjEnemy(m_ex, m_ey + 50, -5,10);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		
	}

}

//�h���[
void CObjBoss1::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 320.0f;
	src.m_left = 64.0f;
	src.m_right = 0.0f;
	src.m_bottom = 384.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = m_ey;
	dst.m_left = m_ex;
	dst.m_right = m_ex + 250.0f;
	dst.m_bottom = m_ey + 250.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

