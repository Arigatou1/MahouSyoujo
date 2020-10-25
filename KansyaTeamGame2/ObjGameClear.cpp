//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjGameClear.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameClear::Init()
{
	Score = 0;
}

//�A�N�V����
void CObjGameClear::Action()
{
	CObjGaugeHP* obj = (CObjGaugeHP*)Objs::GetObj(OBJ_GAUGEHP);

	Score = obj->GetPercent();
}

//�h���[
void CObjGameClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"GAME CLEAR", 200, 200, 96, c);

	wchar_t str[128];
	swprintf_s(str, L"�X�R�A:%d", Score);//�����𕶎���
	Font::StrDraw(str, 300, 2, 24, c);

}