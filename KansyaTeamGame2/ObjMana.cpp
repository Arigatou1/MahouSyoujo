//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjMana.h"
#include "GameHead.h"
//#include "ObjGaugeBaseMana.h"

//�e�X�g�p
#include "GameL\WinInputs.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjMana::CObjMana(float x, float y)
{
	Mana_x = x;
	Mana_y = y;
}
float CObjMana::GetX()
{
	return Mana_x;
}

//�ʒu���Y�擾�p
float CObjMana::GetY()
{
	return Mana_y;
}

//�C�j�V�����C�Y
void CObjMana::Init()
{
	
	Mana_HP = 100;


	//MANA�Q�[�W�x�[�X�I�u�W�F�N�g�쐬
	CObjGaugeMANABase* obj_managb = new CObjGaugeMANABase(Mana_x,Mana_y);
	Objs::InsertObj(obj_managb, OBJ_MANABASE, 50);

	//MANA�Q�[�W�I�u�W�F�N�g�쐬
	CObjGaugeMANAHP* obj_manahp = new CObjGaugeMANAHP(Mana_x, Mana_y);
	Objs::InsertObj(obj_manahp, OBJ_MANA_HP, 51);

	//�����蔻��pHitbox���쐬
	Hits::SetHitBox(this, Mana_x+4 , Mana_y-604, 56, 600, ELEMENT_FIELD, OBJ_MANA, 1);
}

//�A�N�V����
void CObjMana::Action()
{
	

	if (Mana_HP <= 0)
	{
		Mana_HP = 0;
	}


	//HitBox�̓��e
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(Mana_x,Mana_y-304);

	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		Mana_HP-=0.5;

	}

	//�G2�ɓ������1����
	if (hit->CheckObjNameHit(OBJ_ENEMY2) != nullptr)
	{
		Mana_HP -= 1.0;

	}
	
	//�}�i��HP�������Ȃ������A���ł�����
	if (Mana_HP <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		Scene::SetScene(new CSceneGameOver());
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

