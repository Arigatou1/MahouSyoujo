#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"

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

}

//�h���[
void CObjstage::Draw()
{
	//
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	RECT_F src;
	RECT_F dst;

	//�؂���ʒu
	src.m_top =280.0f;
	src.m_left = .0f;
	src.m_right = src.m_left + 100.0f;
	src.m_bottom = 190.0f;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (m_b[i][j] > 0)
			{	
				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 50.0f;
				dst.m_right = dst.m_left + 50.0;
				dst.m_bottom = dst.m_top + 60.0;

				//�`��
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
		}
	}
}