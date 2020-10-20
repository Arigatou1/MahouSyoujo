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
	m_gx = 200;
	m_gy = 200;
	m_mp = 100;//MP����100

	m_postrue = 1.0f;//�E����0.0f ������1.0f

	m_mtime = 0;
}

//�A�N�V����
void CObjMagicalGirl::Action()
{
	m_mtime++;

	if (m_mp < 100)
	{
		m_mtime = 0;
		if (m_mtime % 60 == 0)
		{
			m_mp++;
		}
	}
	//���@�����̒ʏ�U��
	if (Input::GetVKey('F') == true)
	{
		//�z�[�~���O�e�쐬
		CObjHomingBullet* obj_homingbullet = new CObjHomingBullet(m_gx,m_gy,m_postrue);//�z�[�~���O�e�쐬
		Objs::InsertObj(obj_homingbullet, OBJ_HOMINGBULLET, 10);//�I�u�W�F�N�g�}�l�[�ɓo�^
	}

	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_postrue = 0.0f;
	}

	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_postrue = 1.0f;
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
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 50.0f;
	src.m_bottom = 50.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top	 = m_gy-50.0f;
	dst.m_left   = (m_gx - 50.f + 50.0f * m_postrue);
	dst.m_right  = (m_gx - 50.0f * m_postrue);
	dst.m_bottom = m_gy;

	//�`��
	Draw::Draw(0,&src,&dst,c,0.0f);
}