//==============================================================
//
// [score.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"score.h"
#include"number.h"
#include"renderer.h"
#include"manager.h"
#include"object.h"

// 静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CScore::m_pTexture = 0;
CNumber* CScore::m_apNumber[MAX_SCORE] = {};
int CScore::m_nScore = 0;

//----------------------------------------
// コンストラクタ
//----------------------------------------
CScore::CScore(int nPriority) : CObject(nPriority)
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_fxSize = 0.0f;
	m_fySize = 0.0f;
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CScore::~CScore()
{

}

//----------------------------------------
// テクスチャの生成(読み込み)
//----------------------------------------
HRESULT CScore::Load(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\number000.png",
		&m_pTexture);

	return S_OK;
}

//----------------------------------------
// テクスチャの破棄
//----------------------------------------
void CScore::Unload(void)
{
	// テクスチャの破棄
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//----------------------------------------
// スコアの生成処理
//----------------------------------------
CScore* CScore::Create(D3DXVECTOR3 pos, D3DXCOLOR col, float xsize, float ysize)
{
	CScore* pScore = NULL;

	// スコアの生成
	pScore = new CScore;

	pScore->m_pos = pos;
	pScore->m_fxSize = xsize;
	pScore->m_fySize = ysize;

	// 初期化処理
	pScore->Init(pos);

	return pScore;
}

//----------------------------------------
// スコアの初期化処理
//----------------------------------------
HRESULT CScore::Init(D3DXVECTOR3 pos)
{
	// 桁分割計算
	float fTexPos = m_fySize / MAX_SCORE;

	for (int nCnt = 0; nCnt < MAX_SCORE; nCnt++)
	{
		m_apNumber[nCnt] = new CNumber;
		m_apNumber[nCnt]->SetSize(fTexPos, m_fxSize);
		m_apNumber[nCnt]->SetPosition(pos);
		m_apNumber[nCnt]->Init(D3DXVECTOR3(pos.x + (fTexPos * 2.0f * nCnt), pos.y, 0.0f), fTexPos, m_fxSize);

		m_apNumber[nCnt]->BindTexture(m_pTexture);
	}

	// タイプの設定
	SetType(TYPE_SCORE);

	return S_OK;
}

//----------------------------------------
// スコアの終了処理
//----------------------------------------
void CScore::Uninit(void)
{
	for (int nCnt = 0; nCnt < MAX_SCORE; nCnt++)
	{
		if (m_apNumber[nCnt] != NULL)
		{
			m_apNumber[nCnt]->Uninit();

			delete m_apNumber[nCnt];
			m_apNumber[nCnt] = nullptr;
		}
	}

	CObject::Release();
}

//----------------------------------------
// スコアの更新処理
//----------------------------------------
void CScore::Update(void)
{
	//for (int nCnt = 0; nCnt < MAX_SCORE; nCnt++)
	//{
	//	if (m_apNumber[nCnt] != NULL)
	//	{
	//		m_apNumber[nCnt]->SetDigit(nCnt);
	//	}
	//}
}

//----------------------------------------
// スコアの描画処理
//----------------------------------------
void CScore::Draw(void)
{
	for (int nCnt = 0; nCnt < MAX_SCORE; nCnt++)
	{
		if (m_apNumber[nCnt] != NULL)
		{
			m_apNumber[nCnt]->Draw();
		}
	}
}

//----------------------------------------
// スコアの位置の設定処理
//----------------------------------------
void CScore::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//----------------------------------------
// スコアの位置の取得処理
//----------------------------------------
D3DXVECTOR3 CScore::GetPos(void)
{
	return m_pos;
}

//----------------------------------------
// スコアの加算処理
//----------------------------------------
void CScore::AddScore(int nScore)
{
	int aPosTex[MAX_SCORE];
	int nData = 100000000;
	int nData2 = 10000000;

	m_nScore += nScore;

	for (int nCnt = 0; nCnt < MAX_SCORE; nCnt++)
	{
		aPosTex[nCnt] = m_nScore % nData / nData2;
		nData = nData / 10;
		nData2 = nData2 / 10;

		m_apNumber[nCnt]->Score(aPosTex[nCnt]);
	}
}