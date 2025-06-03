//==============================================================
//
// [score.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"score.h"
#include"manager.h"
#include"renderer.h"
#include"number.h"

// 静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CScore::m_pTexture = {};

//----------------------------------------
// コンストラクタ
//----------------------------------------
CScore::CScore(int nPriority) : CObject(nPriority)
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	for (int nCnt = 0; nCnt < MAX_SCORE; nCnt++)
	{
		m_apScore[nCnt] = NULL;
	}
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
CScore* CScore::Create(D3DXVECTOR3 pos, float xsize, float ysize)
{


	return NULL;
}

//----------------------------------------
// スコアの初期化処理
//----------------------------------------
HRESULT CScore::Init(D3DXVECTOR3 pos)
{


	return S_OK;
}

//----------------------------------------
// スコアの終了処理
//----------------------------------------
void CScore::Uninit(void)
{

}

//----------------------------------------
// スコアの更新処理
//----------------------------------------
void CScore::Update(void)
{

}

//----------------------------------------
// スコアの描画処理
//----------------------------------------
void CScore::Draw(void)
{

}

void CScore::SetPosition(D3DXVECTOR3 pos)
{
}

D3DXVECTOR3 CScore::GetPos(void)
{
	return D3DXVECTOR3();
}
