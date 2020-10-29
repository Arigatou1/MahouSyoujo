#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/SceneObjManager.h"

#include"GameHead.h"
#include"ObjBlock.h"

using namespace GameL;

CObjBlock::CObjBlock(int map[10][13])
{
	//マップデータをコピー
	memcpy(m_map, map, sizeof(int) * (10 * 13));
}
//イニシャライズ
void CObjBlock::Init()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			//列の中から6を探す
			if (m_map[i][j]==6)
			{
				CObjMana* obj_mana = new CObjMana(j * 64.0f, i * 64.0f);
				Objs::InsertObj(obj_mana, OBJ_MANA, 55);
			}

		}

	}
}

void CObjBlock::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero-> GetX();
	float hy = hero-> GetY();

	//主人公の衝突状態確認用フラグの初期化
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

	//m_mapの全要素にアクセス
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j]!=6)
			{
				//要素番号を座標に変更
				float bx = j * 64.0f;
				float by = i * 64.0f;

				//主人公のブロックの当たり判定
				if ((hx+64.0f>bx)&&(hx<bx+64.0f)&&(hy+64.0f>by)&&(hy<by+64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = hx - bx;
					float vy = hy -by;

					//長さを求める
					float len = sqrt(vx * vx + vy * vy);

					//角度を求める
					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else 
						r = 360.0f - abs(r);

					if (len < 88.0f)
					{
						//角度で上下左右判定
						if ((r < 45 && r>0) || r > 315)
						{
							//→
							hero->SetX(bx + 64.0f);//ブロックの位置-主人公の幅
							hero->SetRight(true);//主人公の左側が衝突
							hero->SetVX(-hero->GetVX() * 0.1f);//-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							hero->SetDown(true);//主人公から見て、下の部分が衝突している
							hero->SetY(by - 64.0f);//ブロックの位置-主人公の幅
							hero->SetVY(0.0f);
						}
						if (r > 135 && r < 225)
						{
							//左
							hero->SetX(bx - 64.0f);//ブロックの位置-主人公の幅
							hero->SetLeft(true);//主人公の左側が衝突
							hero->SetVX(-hero->GetVX() * 0.1f);//-VX*反発係数
						}
						if (r > 225 && r < 315)
						{
							//下
							hero->SetUp(true);
							hero->SetY(by + 64.0f);//ブロックの位置-主人公の幅

							if (hero->GetVY() < 0)
							{
								hero->SetVY(0.0f);
							}
						}


					}
					
				}
			}
		}
	}

	
}

//ドロー
void CObjBlock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	RECT_F src;
	RECT_F dst;
		
	

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (m_map[i][j] > 0)
			{
				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;

				//ブロック2
				if (m_map[i][j] == 2)
				{
					BlockDraw(64.0f, 256.0f, &dst, c);
				}
				//ブロック3
				else if (m_map[i][j] == 3)
				{
					BlockDraw(128.0f, 256.0f, &dst, c);
				}
				//ブロック4
				else if (m_map[i][j] == 4)
				{
					BlockDraw(192.0f, 256.0f, &dst, c);
				}
				//ブロック5
				else if (m_map[i][j] == 5)
				{
					BlockDraw(256.0f, 256.0f, &dst, c);
				}
				//ブロック6
				else if (m_map[i][j] == 6)
				{
					;//マナ配置用番号
				}
				//ブロック1
				else
				{
					BlockDraw(0.0f, 256.0f, &dst, c);
				}
			}
		}
	}
}

//BlockDrawMethod関数
//引数1 float x :リソース切り取り位置X
//引数2 float y :リソース切り取り位置Y
//引数3 RECT_F* dst 描画位置
//引数4 float c[]カラー情報
//ブロックを64*64限定描画用　リソース切り取り位置のみxyで設定する
void CObjBlock::BlockDraw(float x, float y, RECT_F* dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//描画
	Draw::Draw(0, &src, dst, c, 0.0f);
}
				