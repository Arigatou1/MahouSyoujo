//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeBaseMana.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;




//�C�j�V�����C�Y
void CObjGaugeMANABase::Init()
{

}

//�A�N�V����
void CObjGaugeMANABase::Action()
{



}
//�h���[
void CObjGaugeMANABase::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu


	//�؂���ʒu�̐ݒ�
	src.m_top = 48.0f;
	src.m_left = 0.0f;
	src.m_right = 300.0f;
	src.m_bottom = 72.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 572.0f;
	dst.m_left = 0.0f;
	dst.m_right = 300.0f;
	dst.m_bottom = 596.0f;


	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

}