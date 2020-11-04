//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "Objbarrier.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBarrier::CObjBarrier(float x, float y)
{
	mb_x = x;
	mb_y = y;
}

//�C�j�V�����C�Y
void CObjBarrier::Init()
{
	b_time = 0;

	//�����蔻��p��HITBOX���쐬
	Hits::SetHitBox(this, mb_x ,mb_y + 256.0f ,64, -600, ELEMENT_PLAYER, OBJ_BARRIER, 10);
}

//�A�N�V����
void CObjBarrier::Action()
{
	b_time++;

	if (Input::GetVKey('B') == true && b_t == true)
	{
		b_time = 0;
		b_t = false;
		if (b_time == 0)
		{
			//HitBOx�̓��e��ύX
			CHitBox* hit = Hits::GetHitBox(this);
			hit->SetPos(mb_x, mb_y + 64.0f);
		}
		
	}
	else if (Input::GetVKey('B') == false && b_time > 200)
	{
		b_t = true;
	}

	if (b_time >= 200)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}
//�h���[
void CObjBarrier::Draw()
{
	//�`��J���[
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 64.0f;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    = mb_y - 384.0f;
	dst.m_left   = mb_x + 0.0f;
	dst.m_right  = mb_x + 64.0f;
	dst.m_bottom = mb_y + 224.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
float CObjBarrier::GetBX()
{
	return mb_x;
}