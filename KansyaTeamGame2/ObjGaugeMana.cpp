//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeMana.h"
#include "GameL\DrawFont.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjGaugeMANAHP::Init()
{
	CObjMana* obj_mana = (CObjMana*)Objs::GetObj(OBJ_MANA);
}

//�A�N�V����
void CObjGaugeMANAHP::Action()
{

	

	CObjMana* obj_mana = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if (obj_mana != nullptr)
	{


		MANAHP = obj_mana->GetHP();


		//MAXHP��100%�Ƃ���

		GaugePercent = (MANAHP / 100) * 292;

	}
}
//�h���[
void CObjGaugeMANAHP::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 144.0f;
	//0%�ʒu
	src.m_left = 4.0f;
	//100%�ʒu
	src.m_right = GaugePercent+4.0f;
	src.m_bottom = 208.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 4.0f;
	//0%�ʒu
	dst.m_left = 4.0f;
	//100%�ʒu
	dst.m_right = GaugePercent + 98.0f;
	dst.m_bottom = 28.0f;


	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

}