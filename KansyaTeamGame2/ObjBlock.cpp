#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/SceneObjManager.h"

#include"GameHead.h"
#include"ObjBlock.h"

using namespace GameL;

//�C�j�V�����C�Y
void CObjBlock::Init()
{
	//�}�b�v���
	int block_data[10][10] =
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,0,0,0},
		{0,0,1,1,0,0,0,0,0,0},
		{0,0,1,1,1,0,0,0,0,0},
		{1,0,1,1,1,1,0,0,0,0},
		{0,0,1,1,1,1,1,0,0,0},
		{0,0,1,1,1,1,1,1,0,0},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
	};
	//
	memcpy(m_b, block_data, sizeof(int) * (10 * 10));
}

void CObjBlock::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero-> GetX();
	float hy = hero-> GetY();

	//��l���̏Փˏ�Ԋm�F�p�t���O�̏�����
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (m_b[i][j] > 0)
			{
				//�v�f�ԍ������W�ɕύX
				float x = j * 64.0f;
				float y = i * 64.0f;

				//��l���̃u���b�N�̓����蔻��
				if ((hx+64.0f>x)&&(hx<x+64.0f)&&(hy+64.0f>y)&&(hy<y*64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = hx - x;
					float vy = hy - y;

					//���������߂�
					float len = sqrt(vx * vx + vy * vy);

					//�p�x�����߂�
					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else 
						r = 360.0f - abs(r);

					//�p�x�ŏ㉺���E����
					if ((r < 45 && r>0) || r > 315)
					{
						//��
						hero->SetX(x + 64.0f);//�u���b�N�̈ʒu-��l���̕�
						//hero->SetVY(0.0f);
					}if (r>45 && r<135)
					{
						//��
						hero->SetDown(true);//��l�����猩�āA���̕������Փ˂��Ă���
						hero->SetY(y - 64.0f);//�u���b�N�̈ʒu-��l���̕�
						hero->SetVY(0.0f);
					}
					if (r>135 && r<225)
					{
						//��
						hero->SetX(x - 64.0f);//�u���b�N�̈ʒu-��l���̕�
					}
					if (r>225 && r<315)
					{
						//��
						hero->SetY(y + 64.0f);//�u���b�N�̈ʒu-��l���̕�
						hero->SetVY(0.0f);
					}

					
				}
			}
		}
	}
}

//�h���[
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	RECT_F src;
	RECT_F dst;
		
	//�؂���ʒu�̐ݒ�(�u���b�N)
	src.m_top = 256.0f;
	src.m_left = 320.0f;
	src.m_right = src.m_left+64.0;
	src.m_bottom = 320.0f;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (m_b[i][j] > 0)
			{	
				//�\���ʒu�̐ݒ�
				dst.m_top =i*64.0f;
				dst.m_left =j*64.0f;
				dst.m_right = dst.m_left+64.0f ;
				dst.m_bottom =dst.m_top+64.0f  ;

				//�`��
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
		}
	}
}
