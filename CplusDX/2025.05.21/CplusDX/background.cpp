//==============================================================
//
// [background.h]
// Author: Irisawa Kazan
//
//==============================================================
#include"background.h"
#include"manager.h"
#include"renderer.h"

// 静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CBackground::m_pTexture = {};

//----------------------------------------
// バックグラウンドのコンストラクタ
//----------------------------------------
CBackground::CBackground()
{

}

//----------------------------------------
// バックグラウンドのデストラクタ
//----------------------------------------
CBackground::~CBackground()
{

}

//----------------------------------------
// テクスチャの生成(読み込み)
//----------------------------------------
HRESULT CBackground::Load(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\background100.jpg",
		&m_pTexture);

	return S_OK;
}

//----------------------------------------
// テクスチャの生成(読み込み)
//----------------------------------------
void CBackground::Unload(void)
{
	// テクスチャの破棄
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//----------------------------------------
// 生成処理
//----------------------------------------
CBackground* CBackground::Create(D3DXVECTOR3 pos)
{
	CBackground* pBackground;

	// オブジェクト2Dの生成
	pBackground = new CBackground;

	// 初期化処理
	pBackground->Init(pos);

	pBackground->SetPosition(pos);

	// テクスチャの割り当て
	pBackground->BindTexture(m_pTexture);

	return pBackground;
}

//----------------------------------------
// バックグラウンドの初期化処理
//----------------------------------------
HRESULT CBackground::Init(D3DXVECTOR3 pos)
{
	CObject2D::Init(pos);

	return S_OK;
}

//----------------------------------------
// バックグラウンドの終了処理
//----------------------------------------
void CBackground::Uninit(void)
{
	CObject2D::Uninit();
}

//----------------------------------------
// バックグラウンドの更新処理
//----------------------------------------
void CBackground::Update(void)
{
	CObject2D::Update();
}

//----------------------------------------
// バックグラウンドの描画処理
//----------------------------------------
void CBackground::Draw(void)
{
	CObject2D::Draw();
}