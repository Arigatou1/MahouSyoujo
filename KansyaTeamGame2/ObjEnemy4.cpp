#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include"ObjEnemy4.h"
#include"GameL/UserData.h"

CObjEnemy4::CObjEnemy4(float x, float y)
{
	m_ex = x;
	m_ey = y;
	e_hp = 2;
}

//�C�j�V�����C�Y
void CObjEnemy4::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_r = 0.0f;

	e_jkn = 80;
	e_time = e_jkn;
	e_mtk = false;

	//�����蔻��HitBox���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_ENEMY4, 10);
}

//�A�N�V����
void CObjEnemy4::Action()
{
	m_ex += 2*m_vx;

	//
	CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);
	//CObjHero* obj_h = (CObjHero*)Objs::GetObj(OBJ_HERO);
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

	//HitBox�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex+0.0f, m_ey+0.0f);

	if (hit->CheckObjNameHit(OBJ_HOMINGBULLET) != nullptr)
	{
		e_mtk = true;
		e_hp -= 1;
	}

	//���ɓ�����Ώ���
	if (hit->CheckObjNameHit(OBJ_SWORD) != nullptr)
	{
		e_mtk = true;
		e_hp -= 2;
	}

	if (e_mtk == true)
	{
		//HitBox�̓��e���X�V
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_ex + 9999, m_ey);
		//���G���Ԃ����炷
		e_jkn -= 1;

		if (e_jkn <= 0)
		{
			e_mtk = false;
			e_jkn = e_time;
		}
	}

	//HP��0�ɂȂ�Ώ���
	if (e_hp <= 0)
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