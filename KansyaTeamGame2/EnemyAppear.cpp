//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "GameL/SceneObjManager.h"
#include "EnemyAppear.h"
#include "GameL/UserData.h"

//�g�p����l�[���x�[�X
using namespace GameL;


//�C�j�V�����C�Y
void EnemyAppear::Init()
{
	
	
}

//�A�N�V����
void EnemyAppear::Action()
{

}

//�h���[
void EnemyAppear::Draw()
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
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 0.0f + 250.0f;
	dst.m_bottom = 0.00f + 250.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

