//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "ObjEnemy.h"

//�g�p����l�[���x�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjEnemy::Init()
{

}

//�A�N�V����
void CObjEnemy::Action()
{

}

//�h���[
void CObjEnemy::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 50.0f;
	dst.m_right = 100.0f;
	dst.m_bottom = 50.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
