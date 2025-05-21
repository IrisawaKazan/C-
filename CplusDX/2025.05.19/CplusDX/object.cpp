//==============================================================
//
// [object.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"object.h"
#include"renderer.h"
#include"object2D.h"

// 静的メンバ変数宣言
int CObject::m_nNumAll = 0;
CObject* CObject::m_apObject[MAX_OBJ] = {}; // オブジェクトへのポインタ

//----------------------------------------
// コンストラクタ
//----------------------------------------
CObject::CObject()
{
	m_nID = 0;

	for (int nCntObj = 0; nCntObj < MAX_OBJ; nCntObj++)
	{
		if (m_apObject[nCntObj] == NULL)
		{
			m_apObject[nCntObj] = this; // 自分自身を代入
			m_nID = nCntObj;            // 自分自身のIDを保存
			m_nNumAll++;                // 総数をカウントアップ
			break;
		}
	}
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CObject::~CObject()
{

}

//----------------------------------------
// 全てのオブジェクトの破棄
//----------------------------------------
void CObject::ReleaseAll(void)
{
	for (int nCntObj = 0; nCntObj < MAX_OBJ; nCntObj++)
	{
		if (m_apObject[nCntObj] != NULL)
		{
			// 終了処理
			m_apObject[nCntObj]->Uninit();
		}
	}
}

//----------------------------------------
// 全てのオブジェクトの更新処理
//----------------------------------------
void CObject::UpdateAll(void)
{
	for (int nCntObj = 0; nCntObj < MAX_OBJ; nCntObj++)
	{
		if (m_apObject[nCntObj] != NULL)
		{
			// 更新処理
			m_apObject[nCntObj]->Update();
		}
	}
}

//----------------------------------------
// 全てのオブジェクトの描画処理
//----------------------------------------
void CObject::DrawAll(void)
{
	for (int nCntObj = 0; nCntObj < MAX_OBJ; nCntObj++)
	{
		if (m_apObject[nCntObj] != NULL)
		{
			// 描画処理
			m_apObject[nCntObj]->Draw();
		}
	}
}

//----------------------------------------
// オブジェクトの破棄
//----------------------------------------
void CObject::Release(void)
{
	for (int nCntObj = 0; nCntObj < MAX_OBJ; nCntObj++)
	{
		if (m_apObject[nCntObj] != NULL)
		{
			delete m_apObject[nCntObj];
			m_apObject[nCntObj] = NULL;
			
			m_nNumAll--; // 総数をカウントダウン
		}
	}
}