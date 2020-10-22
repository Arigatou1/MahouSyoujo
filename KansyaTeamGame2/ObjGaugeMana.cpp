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

	wchar_t str[128];
	swprintf_s(str, L"%.0lf", MANAHP);//�����𕶎���
	Font::StrDraw(str, 300, 572, 24, c);

	//�؂���ʒu�̐ݒ�
	src.m_top = 144.0f;
	//0%�ʒu
	src.m_left = 4.0f;
	//100%�ʒu
	src.m_right = GaugePercent+4.0f;
	src.m_bottom = 168.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 572.0f;
	//0%�ʒu
	dst.m_left = 4.0f;
	//100%�ʒu
	dst.m_right = GaugePercent + 4.0f;
	dst.m_bottom = 596.0f;


	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

}