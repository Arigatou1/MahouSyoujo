#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjMagicalGirl : public CObj
{
	public:
		CObjMagicalGirl() {};
		~CObjMagicalGirl() {};
		void Init();   //�C�j�V�����C�Y
		void Action(); //�A�N�V����
		void Draw();   //�h���[
		int GetMP();
		int GetMaxMP();
	private:
		float m_gx;//�ʒu
		float m_gy;
		float m_postrue;//�p��
		float m_mp;//MP
		float m_maxmp;//MAXMP
		
		int m_mtime;//MP�񕜗p����
		int m_btime;//�z�[�~���O�e�p����
		bool m_t;//�U���Ԋu
};