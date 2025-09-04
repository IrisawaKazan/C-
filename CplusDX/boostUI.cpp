//==============================================================
//
// [boostUI.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"boostUI.h"
#include"renderer.h"
#include"manager.h"

// 静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CBoost::m_pTexture[BOOST_MAX] = {};

//----------------------------------------
// ブーストUIのコンストラクタ
//----------------------------------------
CBoost::CBoost(int nPriority) : CObject2D(nPriority)
{
	m_type = BOOST_NONE;
}

//----------------------------------------
// ブーストUIのデストラクタ
//----------------------------------------
CBoost::~CBoost()
{

}

//----------------------------------------
// テクスチャの生成(読み込み)
//----------------------------------------
HRESULT CBoost::Load(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\boost.png",
		&m_pTexture[BOOST_NORMAL]);

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\boostboost.png",
		&m_pTexture[BOOST_SUPER]);

	return S_OK;
}

//----------------------------------------
// テクスチャの破棄
//----------------------------------------
void CBoost::Unload(void)
{
	for (int nCount = 0; nCount < BOOST_MAX; nCount++)
	{
		// テクスチャの破棄
		if (m_pTexture[nCount] != NULL)
		{
			m_pTexture[nCount]->Release();
			m_pTexture[nCount] = NULL;
		}
	}
}

//----------------------------------------
// ブーストUIの生成処理
//----------------------------------------
CBoost* CBoost::Create(D3DXVECTOR3 pos, float xsize, float ysize, BOOST type)
{
	CBoost* pBoost;

	int nNumAll = CObject::GetNumAll();

	if (nNumAll <= MAX_OBJ)
	{
		// オブジェクト2Dの生成
		pBoost = new CBoost;

		pBoost->m_type = type;

		// 初期化処理
		pBoost->Init(pos);

		// サイズの設定
		pBoost->SetSize(xsize, ysize);

		// テクスチャの割り当て
		pBoost->BindTexture(m_pTexture[type]);

		return pBoost;
	}

	return NULL;
}

//----------------------------------------
// ブーストUIの初期化処理
//----------------------------------------
HRESULT CBoost::Init(D3DXVECTOR3 pos)
{
	// テクスチャの設定
	CObject2D::SetUV(1.0f, 1.0f);

	SetPosition(pos);

	CObject2D::Init();

	// 種類の設定処理
	CObject::SetType(TYPE_BOOST);

	return S_OK;
}

//----------------------------------------
// ブーストUIの終了処理
//----------------------------------------
void CBoost::Uninit(void)
{
	CObject2D::Uninit();
}

//----------------------------------------
// ブーストUIの更新処理
//----------------------------------------
void CBoost::Update(void)
{
	CObject2D::Update();
}

//----------------------------------------
// ブーストUIの描画処理
//----------------------------------------
void CBoost::Draw(void)
{
	CObject2D::Draw();
}

//----------------------------------------
// ブーストUIのタイプの設定処理
//----------------------------------------
void CBoost::SetType(BOOST type)
{
	m_type = type;
}

//----------------------------------------
// ブーストUIのタイプの取得処理
//----------------------------------------
CBoost::BOOST CBoost::GetType(void)
{
	return m_type;
}