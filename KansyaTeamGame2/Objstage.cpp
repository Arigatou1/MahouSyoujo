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
	int block_data[10][10]=
	{
		{0,0,0,0,0,0,0,0,0,0}
		{0,0,0,0,0,0,0,0,0,0}
		{0,0,0,0,0,0,0,0,0,0}
		{0,0,0,0,0,0,0,0,0,0}
		{0,0,0,0,0,0,0,0,0,0}
		{0,0,0,0,0,0,0,0,0,0}
		{0,0,0,0,0,0,0,0,0,0}
		{0,0,0,0,0,0,0,0,0,0}
		{0,0,0,0,0,0,0,0,0,0}
		{1,1,1,1,1,1,1,1,1,1}
	}:
	//
	memcpy(m_b, block_data, sizeof(int) * (10 * 10));
}

void CObjstage::Action()
{

}

//�h���[
void CObjstage::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
}