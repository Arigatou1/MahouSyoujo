//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjTitle.h"
#include "GameL\MultiThread.h"
#include "GameL\UserData.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	m_key_flag = false;//キーフラグ

	static bool init_stage = false;
	if (init_stage == false) {
		((UserData*)Save::GetData())->Stage = 1;
		init_stage = true;

		for (int i = 0; i < 20;i++)
		((UserData*)Save::GetData())->ScoreData[i] = 0;
		//ロード
		Save::Open();//同フォルダ[UserDataからデータ取得]
	}

	if (init_stage == true)
	{
		Save::Seve();
	}
}

//アクション
void CObjTitle::Action()
{
	
	//エンターキーを押してシーン:ゲームMenuに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMenu());
			m_key_flag = false;
		}
	}
	//デバッグ用 セーブデータ削除
	else if (Input::GetVKey('3') == true)
	{
		if (m_key_flag == true)
		{
			for (int i = 0; i < 20; i++)
				((UserData*)Save::GetData())->ScoreData[i] = 0;
			Save::Seve();

			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"マジカルウォーズ", 116, 200, 64, c);

	Font::StrDraw(L"Push [Enter] Key", 280, 400, 32, c);

	if (Input::GetVKey('3') == true)
	{
		Font::StrDraw(L"セーブデータを削除しました", 0, 0, 32, c);
	}
}