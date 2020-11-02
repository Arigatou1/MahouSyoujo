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
		int GetHP();
	private:
		float m_gx;//�ʒu
		float m_gy;
		float m_postrue;//�p��
		float m_mp;//MP
		float m_maxmp;//MAXMP
		float m_atk_animation;//�U���̃��[�V����
		//float h_maxhp;//��l���̍ő�HP
		//float h_hp;//��l���̌�HP
		
		int m_mtime;//MP�񕜗p����
		int m_btime;//�z�[�~���O�e�p����
		bool m_t;//�U���Ԋu
		//bool h_t;//�񕜊Ԋu
};