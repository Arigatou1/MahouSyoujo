//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjMagicalGirl.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMagicalGirl::Init()
{
	m_gx = 372;//x�ʒu
	m_gy = 440;//y�ʒu
	m_maxmp = 100;//MP����100
	m_mp = m_maxmp;
	//m_mp = 50;               //�e�X�g�p

	m_postrue = 1.0f;//�E����0.0f ������1.0f

	m_mtime = 1;
	m_btime = 1;

	//MP�Q�[�W�I�u�W�F�N�g�쐬
	CObjGaugeMP* obj_gmp = new CObjGaugeMP();
	Objs::InsertObj(obj_gmp, OBJ_GAUGEMP, 51);
}

//�A�N�V����
void CObjMagicalGirl::Action()
{
	m_mtime++;
	m_btime++;

	//MP��100������������1���񕜂���
	if (m_mp < m_maxmp)
	{
		if (m_mtime % 60 == 0)
		{
			m_mtime = 0;
			m_mp++;
		}
	}

	//��l�����E�����獶������
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_postrue = 0.0f;
	}
	//��l����������ƉE������
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_postrue = 1.0f;
	}

	//���@�����̒ʏ�U��
	if (m_btime % 200 == 0 )
	{
		if (m_postrue == 0.0f)
		{
			//�z�[�~���O�e�쐬
			CObjHomingBullet* obj_homingbullet = new CObjHomingBullet(m_gx - 25.0f, m_gy, m_postrue);//�z�[�~���O�e�쐬
			Objs::InsertObj(obj_homingbullet, OBJ_HOMINGBULLET, 10);//�I�u�W�F�N�g�}�l�[�ɓo�^
		}
		else if (m_postrue == 1.0f)
		{
			//�z�[�~���O�e�쐬
			CObjHomingBullet* obj_homingbullet = new CObjHomingBullet(m_gx + 25.0f, m_gy, m_postrue);//�z�[�~���O�e�쐬
			Objs::InsertObj(obj_homingbullet, OBJ_HOMINGBULLET, 10);//�I�u�W�F�N�g�}�l�[�ɓo�^
		}
		m_btime = 1;
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
	src.m_left   = 0.0f;
	src.m_right  = 64.0f;
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