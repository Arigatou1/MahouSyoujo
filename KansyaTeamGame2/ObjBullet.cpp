//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "ObjBullet.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBullet::CObjBullet(float x, float y, int posture, bool m_f)
{
	px = x;
	py = y;

	b_posture = posture;
	b_f = m_f;
}

//�C�j�V�����C�Y
void CObjBullet::Init()
{
	Hits::SetHitBox(this, px, py+24, 64, 16, ELEMENT_PLAYER, OBJ_BULLET, 1);
	
	
}

//�A�N�V����
void CObjBullet::Action()
{

	//HitBOx�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(px, py+24);

	if (b_posture == 1)
		px += 18;
	else
		px -= 18;
	

	//�����蔻����s���I�u�W�F�N�g���
	int database[4] =
	{
		OBJ_ENEMY,
		OBJ_ENEMY2,
		OBJ_ENEMY3,
		OBJ_ENEMY4,
	};

	for(int i=0;i<4;i++)
	{

		if (hit->CheckObjNameHit(database[i])!=nullptr)
		{
			this->SetStatus(false);
				Hits::DeleteHitBox(this);
		}

		//Amount++;
	}

	
}

//�h���[
void CObjBullet::Draw()
{
	//�`��J���[
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳ff���؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 192.0f;
	src.m_left = 128.0f;
	src.m_right = 192.0f;
	src.m_bottom = 256.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top =py+0.0f;
	dst.m_left = (b_posture*32)+px+32.0f;
	dst.m_right = (b_posture*-32)+px+32.0f;
	dst.m_bottom = py+64.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}