#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g��l��
class CObjHero :public CObj
{
public :
	CObjHero() {};
	~CObjHero() {};
	void Init();
	void Action();
	void Draw();
	int GetHP();
	int GetMAXHP();
private:
	float m_px;		//�v���C���[�̍��WX
	float m_py;		//�v���C���[�̍��WY
	float m_vx;		//�v���C���[�̃x�N�g��X
	float m_vy;		//�v���C���[�̃x�N�g��Y
	float m_posture;//�����Ă�������p


	int m_anime;	//�����A�j���[�V����
	int m_anitime;	//�����A�j���[�V�����̊Ԋu

	int atk_anime;	//�����o��
	int atk_anitime;//
	int atk_time;	//�U���̊Ԋu

	int m_hp;//�v���C���[�̗̑�
	int max_hp;
	int mtk_jkn;//���G���ԗp�ϐ�
	int mtk_max;//���G���ԗp�ϐ�
	bool m_mtk;//��l���̖��G����
	float speed_power;

	bool m_f;		//�U���̊Ԋu
	bool isJump;//�W�����v�ł��邩�ł��Ȃ����𔻒f����

	
    };

