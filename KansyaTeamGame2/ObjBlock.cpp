#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/SceneObjManager.h"

#include"GameHead.h"
#include"ObjBlock.h"

using namespace GameL;

CObjBlock::CObjBlock(int map[10][13])
{
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, map, sizeof(int) * (10 * 13));
}
//�C�j�V�����C�Y
void CObjBlock::Init()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			//��̒�����6��T��
			if (m_map[i][j]==6)
			{
				CObjMana* obj_mana = new CObjMana(j * 64.0f, i * 64.0f);
				Objs::InsertObj(obj_mana, OBJ_MANA, 55);
			}

		}

	}
}

void CObjBlock::Action()
{
	/*
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero-> GetX();
	float hy = hero-> GetY();

	//��l���̏Փˏ�Ԋm�F�p�t���O�̏�����
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

	//�G�R�̈ʒu�擾
	CObjEnemy3* enemy3 = (CObjEnemy3*)Objs::GetObj(OBJ_ENEMY3);
	if (enemy3 != nullptr) 
	{
		ex = enemy3->GetX();
		ey = enemy3->GetY();
	}

	//�G3�̏Փˏ�Ԋm�F�p�t���O�̏�����
	enemy3->SetUp(false);
	enemy3->SetDown(false);
	enemy3->SetLeft(false);
	enemy3->SetRight(false);

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j]!=6)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j * 64.0f;
				float by = i * 64.0f;

				//��l���̃u���b�N�̓����蔻��
				if ((hx+64.0f>bx)&&(hx<bx+64.0f)&&(hy+64.0f>by)&&(hy<by+64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = hx - bx;
					float vy = hy -by;

					//���������߂�
					float len = sqrt(vx * vx + vy * vy);

					//�p�x�����߂�
					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else 
						r = 360.0f - abs(r);

					if (len < 88.0f)
					{
						//�p�x�ŏ㉺���E����
						if ((r < 40 && r>0) || r > 320)
						{
							//�E
							hero->SetX(bx + 64.0f);//�u���b�N�̈ʒu-��l���̕�
							hero->SetRight(true);//��l���̍������Փ�
							hero->SetVX(-hero->GetVX() * 0.1f);//-VX*�����W��


						}
						if (r > 45 && r < 135)
						{
							//��
							hero->SetDown(true);//��l�����猩�āA���̕������Փ˂��Ă���
							hero->SetY(by - 64.0f);//�u���b�N�̈ʒu-��l���̕�
							hero->SetVY(0.0f);
						}
						if (r > 140 && r < 220)
						{
							//��
							hero->SetX(bx - 64.0f);//�u���b�N�̈ʒu-��l���̕�
							hero->SetLeft(true);//��l���̍������Փ�
							hero->SetVX(-hero->GetVX() * 0.1f);//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							hero->SetUp(true);
							hero->SetY(by + 64.0f);//�u���b�N�̈ʒu-��l���̕�

							if (hero->GetVY() < 0)
							{
								hero->SetVY(0.0f);
							}
						}


					}
					
				}

				//�G3�̃u���b�N�̓����蔻��
				if ((ex + 64.0f > bx) && (ex < bx + 64.0f) && (ey + 64.0f > by) && (ey < by + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = ex - bx;
					float vy = ey - by;

					//���������߂�
					float len = sqrt(vx * vx + vy * vy);

					//�p�x�����߂�
					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					if (len < 88.0f)
					{
						if (r > 45 && r < 135)
						{
							if (enemy3 != nullptr)
							{
								//��
								enemy3->SetDown(true);//��l�����猩�āA���̕������Փ˂��Ă���
								enemy3->SetY(by - 64.0f);//�u���b�N�̈ʒu-��l���̕�
								enemy3->SetVY(0.0f);
							}
						}
					}
				}
				
			}
		}
	}*/
}
//�h���[
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	RECT_F src;
	RECT_F dst;
		
	

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;

				//�u���b�N2
				if (m_map[i][j] == 2)
				{
					BlockDraw(64.0f, 256.0f, &dst, c);
				}
				//�u���b�N3
				else if (m_map[i][j] == 3)
				{
					BlockDraw(128.0f, 256.0f, &dst, c);
				}
				//�u���b�N4
				else if (m_map[i][j] == 4)
				{
					BlockDraw(192.0f, 256.0f, &dst, c);
				}
				//�u���b�N5
				else if (m_map[i][j] == 5)
				{
					BlockDraw(256.0f, 256.0f, &dst, c);
				}
				//�u���b�N6
				else if (m_map[i][j] == 6)
				{
					;//�}�i�z�u�p�ԍ�
				}
				//�u���b�N1
				else
				{
					BlockDraw(0.0f, 256.0f, &dst, c);
				}
			}
		}
	}
}

//BlockDrawMethod�֐�
//����1 float x :���\�[�X�؂���ʒuX
//����2 float y :���\�[�X�؂���ʒuY
//����3 RECT_F* dst �`��ʒu
//����4 float c[]�J���[���
//�u���b�N��64*64����`��p�@���\�[�X�؂���ʒu�̂�xy�Őݒ肷��
void CObjBlock::BlockDraw(float x, float y, RECT_F* dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//�`��
	Draw::Draw(0, &src, dst, c, 0.0f);
}

//BlockHit�֐�
//����1 float* x     :������s��object��x�ʒu�@�@�@�@�@�@�@�@�@�@�@
//����2 float* y     :������s��object��y�ʒu�@�@
//����3 bool* up     :�㉺���E����̏㕔���ɓ������Ă��邩�ǂ�����Ԃ�
//����4 boll* down   :�㉺���E����̉������ɓ������Ă��邩�ǂ�����Ԃ�
//����5 bool* left   :�㉺���E����̍������ɓ������Ă��邩�ǂ�����Ԃ�
//����6 bool* right  :�㉺���E����̉E�����ɓ������Ă��邩�ǂ�����Ԃ�
//����7 float* vx    :���E���莞�̔����ɂ��ړ������E�͂̒l��ς��ĕԂ�
//����8 float* vy    :�㉺���񎦂ɂ�鎩�R�����^���̈ړ������E�͂̒l�ς��ĕԂ�
//����9 int* bt      :���������莞�A����ȃu���b�N�̃^�C�v��Ԃ�
//������s��object�ƃu���b�N64�~64����ŁA�����蔻��Ə㉺������s��
//���̌��ʂ͈���4�`10�ɕԂ�

void CObjBlock::BlockHit(float* x, float* y,
	bool* up, bool* down, bool* left, bool* right,
	float* vx, float* vy,float* x_size,float* y_size )
{
	//�G�Փˏ�Ԋm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 6)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j * 64.0f;
				float by = i * 64.0f;

				//��l���̃u���b�N�̓����蔻��
				if ((*x + 64 > bx) && (*x < bx + 64) && (*y + *y_size > by) && (*y < by + *y_size))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = *x - bx;
					float rvy = *y - by;

					//���������߂�
					float len = sqrt(rvx * rvx + rvy * rvy);

					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					if (len < 88.0f)
					{
						//�p�x�ŏ㉺���E����
						if ((r < 35 && r>5) || r > 320)
						{
							//�E
							*right = true;//��l���̍������Փ�
							*x     = bx + *x_size+(64-*x_size);//�u���b�N�̈ʒu-��l���̕�
							*vx    = -(*vx) * 0.1f;//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							*down = true;//�I�u�W�F�N�g���猩�āA���̕������Փ˂��Ă���
							*y    = by - *y_size;//�u���b�N�̈ʒu-��l���̕�
							*vy   = 0.0f;
						}
						if (r > 145 && r < 215)
						{
							//��
							*left = true;//�I�u�W�F�N�g�̍������Փ�
							*x    = bx - *x_size - (64 - *x_size);//�u���b�N�̈ʒu-��l���̕�
							*vx   = -(*vx) * 0.1f;//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							*up = true;//�I�u�W�F�N�g�̉������Փ�
							*y = by + *y_size;//�u���b�N�̈ʒu-��l���̕�

							if (*vy < 0)
							{
								*vy = 0.0f;
							}
						}
					}
				}
			}
		}
	}
}