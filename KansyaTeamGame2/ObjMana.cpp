//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjMana.h"
#include "GameHead.h"
#include "ObjGaugeBaseMana.h"

//�e�X�g�p
#include "GameL\WinInputs.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;



//�C�j�V�����C�Y
void CObjMana::Init()
{
	Mana_x = 300;
	Mana_y = 440;
	Mana_HP = 100;


}

//�A�N�V����
void CObjMana::Action()
{
	//�����͖{���Am_mtk��false�ɂȂ��Ă��āA�G�ɓ����������ɍs���悤�ɂ���B
	if (Input::GetVKey('D') == true)
	{

		Mana_HP -= 1;//�G�̍U����

	}
	else
		;

	if (Mana_HP <= 0)
	{
		Mana_HP = 0;
	}

	
}
//�h���[
void CObjMana::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,Mana_HP/100,Mana_HP/100,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 192.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 256.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = Mana_y;
	dst.m_left = Mana_x;
	dst.m_right = Mana_x+64;
	dst.m_bottom = Mana_y+64;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}


int CObjMana::GetHP()
{
	return Mana_HP;
}