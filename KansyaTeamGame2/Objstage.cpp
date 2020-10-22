#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"

#include"GameHead.h"
#include"Objstage.h"

using namespace GameL;

//イニシャライズ
void CObjstage::Init()
{
	//マップ情報
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

//ドロー
void CObjstage::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
}