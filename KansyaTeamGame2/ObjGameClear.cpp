//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "GameL\UserData.h"
#include "ObjGameClear.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameClear::Init()
{
	//Score = 0;
	
	//現在のハイスコアよりも高い場合結果を保存
	if (((UserData*)Save::GetData())->HHP >
		((UserData*)Save::GetData())->ScoreData[((UserData*)Save::GetData())->Stage])

	{
		//スコアを保存
		((UserData*)Save::GetData())->ScoreData[((UserData*)Save::GetData())->Stage]
			= ((UserData*)Save::GetData())->HHP;

	}
	Save::Seve();//セーブ
}

//アクション
void CObjGameClear::Action()
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

	else
	{
		m_key_flag = true;
	}

}

//ドロー
void CObjGameClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"GAME CLEAR!", 200, 200, 96, c);


	

	wchar_t str[128];
	swprintf_s(str, L"スコア:%d", ((UserData*)Save::GetData())->HHP);//整数を文字列か
	Font::StrDraw(str, 300, 2, 24, c);

}