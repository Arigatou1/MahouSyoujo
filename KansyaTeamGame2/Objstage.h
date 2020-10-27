#pragma once
//
#include"GameL/SceneObjManager.h"
//
using namespace GameL;

//
class CObjstage :public CObj
{
public :
	CObjstage() {};
	~CObjstage() {};
	void Init() ;
	void Action();
	void Draw();
private:
	int m_b[10][10];//ƒ}ƒbƒvî•ñ
};