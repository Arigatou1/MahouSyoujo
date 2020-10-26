#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/SceneObjManager.h"

#include"GameHead.h"
#include"Objstage.h"

using namespace GameL;

//�C�j�V�����C�Y
void CObjstage::Init()
{
	//�}�b�v���
	int block_data[10][10] =
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1},
	};
	//
	memcpy(m_b, block_data, sizeof(int) * (10 * 10));
}

void CObjstage::Action()
{
	//��l���̈ʒu���擾
	//CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//float hx = hero-> ();
	//float hy = hero-> ();

	/*for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (m_b[i][j])
			{
				//�v�f�ԍ������W�ɕύX
				float x = j * 64.0f;
				float y = i * 64.0f;

				//
				if (1)
				{
					//�������Ă���ꍇ
				}
			}
		}
	}*/
}

//�h���[
void CObjstage::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	RECT_F src;
	RECT_F dst;
		
	//�؂���ʒu�̐ݒ�(�u���b�N)
	src.m_top = 260.0f;
	src.m_left = 321.0f;
	src.m_right = src.m_left+64.0;
	src.m_bottom = 314.0f;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (m_b[i][j] > 0)
			{	
				//�\���ʒu�̐ݒ�
				dst.m_top =i*56.0f;
				dst.m_left =j*80.0f;
				dst.m_right = dst.m_left+81.0f ;
				dst.m_bottom =dst.m_top+92.0f  ;

				//�`��
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
		}
	}
}