//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjEnemyAmount.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjEnemyAmount::Init()
{
	EnemyAmount = 2;
}

//�A�N�V����
void CObjEnemyAmount::Action()
{
	
}

//�h���[
void CObjEnemyAmount::Draw()
{
	float c[4] = { 0.0f,0.0f,0.0f,1.0f };
	wchar_t str[128];
	swprintf_s(str, L"�c��G�̐�:%d", EnemyAmount);//�����𕶎���
	Font::StrDraw(str, 2, 96, 24, c);

}