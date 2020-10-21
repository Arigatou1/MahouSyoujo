//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeHP.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjGaugeHP::Init()
{

}

//�A�N�V����
void CObjGaugeHP::Action()
{
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)
	{


		float HP = obj->GetHP();
		float MAXHP = obj->GetMAXHP();

		//MAXHP��100%�Ƃ���

		GaugePercent = (HP / MAXHP) * 250;

	}
}
//�h���[
void CObjGaugeHP::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu


	//�؂���ʒu�̐ݒ�
	src.m_top = 50.4f;
	//0%�ʒu
	src.m_left = 46.0f;
	//100%�ʒu
	src.m_right = GaugePercent+46.0f;
	src.m_bottom = 75.2f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	//0%�ʒu
	dst.m_left = 46.0f;
	//100%�ʒu
	dst.m_right = GaugePercent+46.0f;
	dst.m_bottom = 25.2f;


	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

}