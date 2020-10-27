#pragma once
//
#include"GameL/SceneObjManager.h"
//
using namespace GameL;

//
class CObjBlock :public CObj
{
public :
	CObjBlock() {};
	~CObjBlock() {};
	void Init() ;
	void Action();
	void Draw();
private:
	int m_b[10][10];//É}ÉbÉvèÓïÒ
};