//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjMagicalGirl.h"
//#include "��l���̃w�b�_�[�H"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMagicalGirl::Init()
{
	m_maxmp = 100;
	m_mp =m_maxmp;//MP����100
	
	m_postrue = 1.0f;//�E����0.0f ������1.0f
	m_atk_animation = 0;//0=�_�����̉摜

	m_mtime = 1;
	m_btime = 0;
}

//�A�N�V����
void CObjMagicalGirl::Action()
{
	m_mtime++;
	m_btime++;

	CObjMana* obj_mana = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if(obj_mana != nullptr)
	{
		m_gx = obj_mana->GetX();
		m_gy = obj_mana->GetY();
	}

	//CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//if (obj != nullptr)
	//{
		//h_hp = obj->GetHP();
		//h_maxhp = obj->GetMAXHP();
	//}

	if (m_mp < 100)//(�����炭1�b��1)MP��
	{

		if (m_mtime % 60 == 0)
		{
			m_mp++;
			m_mtime = 0;
		}
	}

	//�L�[�������ƈړ�
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_postrue = 0.0f;
	}
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_postrue = 1.0f;
	}

	//���@�����̒ʏ�U��
	if (m_mp >= 1)
	{
		if (Input::GetVKey('D') == true && m_t == true)
		{
			m_atk_animation = 3;//�񎝂����p�ɂȂ�

			if (m_postrue == 0.0f)
			{
				m_t = false;
				//���@�������@�ʍ쐬
				CObjHomingBullet* obj_homingbullet = new CObjHomingBullet(m_gx - 25.0f, m_gy, m_postrue);//�z�[�~���O�e�쐬
				Objs::InsertObj(obj_homingbullet, OBJ_HOMINGBULLET, 60);//�I�u�W�F�N�g�}�l�[�ɓo�^

				m_mp -= 1;

				if (m_mp < 0)
				{
					m_mp = 0;
				}
			}
			else if (m_postrue == 1.0f)
			{
				m_t = false;
				//���@�������@�ʍ쐬
				CObjHomingBullet* obj_homingbullet = new CObjHomingBullet(m_gx + 25.0f, m_gy, m_postrue);//�z�[�~���O�e�쐬
				Objs::InsertObj(obj_homingbullet, OBJ_HOMINGBULLET, 60);//�I�u�W�F�N�g�}�l�[�ɓo�^

				m_mp -= 1;

				if (m_mp < 0)
				{
					m_mp = 0;
				}
			}
		}
		else if (Input::GetVKey('D') == false)
		{
			m_atk_animation = 0;//�_�����̎p�ɂȂ�
			m_t = true;
		}
	}

	//���@�����̉񕜖��@
	if (m_mp >= 20)
	{
		if (Input::GetVKey('H') == true && h_t == true)
		{
			h_t = false;
			m_mp -= 20;
			CObjHero* obj_heromp = (CObjHero*)Objs::GetObj(OBJ_HERO);

			if (obj_heromp != nullptr)
			{
				m_mp = obj_heromp->GetMP();
			}
		}
		else if (Input::GetVKey('H') == false)
		{
			h_t = true;
		}
	}
	
	if (m_mp >= 30)
	{
		if (Input::GetVKey('B') == true && b_t == true)
		{
			m_btime = 0;
			b_t = false;
			m_mp -= 30;

			if (m_btime == 0)
			{
				//Barrier�I�u�W�F�N�g
				CObjBarrier* objbarrier;
				objbarrier = new CObjBarrier(m_gx + 64.0f, m_gy);
				Objs::InsertObj(objbarrier, OBJ_BARRIER, 60);
				objbarrier = new CObjBarrier(m_gx - 64.0f, m_gy);
				Objs::InsertObj(objbarrier, OBJ_BARRIER, 60);
			}
		}
		else if (Input::GetVKey('B') == false && m_btime > 200)
		{
			b_t = true;
		}
	}
}

//�h���[
void CObjMagicalGirl::Draw()
{
	//�`��J���[
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 128.0f;
	src.m_left   = (m_atk_animation * 64.0f) + 0.0f;
	src.m_right  = (m_atk_animation * 64.0f) + 64.0f;
	src.m_bottom = 192.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top	 =0.0f  + m_gy;
	dst.m_left   =0.0f  + (m_gx + 64.0f * m_postrue);
	dst.m_right  =64.0f + (m_gx - 64.0f * m_postrue);
	dst.m_bottom =64.0f + m_gy;

	//�`��
	Draw::Draw(0,&src,&dst,c,0.0f);
}

int CObjMagicalGirl::GetMP()
{
	return m_mp;
}

int CObjMagicalGirl::GetMaxMP()
{
	return m_maxmp;
}