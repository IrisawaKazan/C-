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
	m_type = TYPE_NONE;

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
// オブジェクトのタイプ設定処理
//----------------------------------------
void CObject::SetType(TYPE type)
{
	m_type = type;
}

//----------------------------------------
// オブジェクトのタイプ取得処理
//----------------------------------------
CObject::TYPE CObject::GetType(void)
{
	return m_type;
}

//----------------------------------------
// オブジェクトの取得処理
//----------------------------------------
CObject* CObject::GetObj(int nIdx)
{
	return m_apObject[nIdx];
}

//----------------------------------------
// オブジェクトの破棄
//----------------------------------------
void CObject::Release(void)
{
	int nIdx = this->m_nID;

	if (m_apObject[nIdx] != NULL)
	{
		delete m_apObject[nIdx];
		m_apObject[nIdx] = NULL;

		m_nNumAll--; // 総数をカウントダウン
	}
}