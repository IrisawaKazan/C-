//==============================================================
//
// [background.h]
// Author: Irisawa Kazan
//
//==============================================================
#include"background.h"
#include"manager.h"
#include"renderer.h"
#include"object.h"

// 静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CBackground::m_pTexture = nullptr;

//----------------------------------------
// バックグラウンドのコンストラクタ
//----------------------------------------
CBackground::CBackground(int nPriority) : CObject2D(nPriority)
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
		"data\\TEXTURE\\background000.jpg",
		&m_pTexture);

	return S_OK;
}

//----------------------------------------
// テクスチャの破棄
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
CBackground* CBackground::Create(D3DXVECTOR3 pos, float xsize, float ysize)
{
	CBackground* pBackground;

	int nNumAll = CObject::GetNumAll();

	if (nNumAll <= MAX_OBJ)
	{
		// オブジェクト2Dの生成
		pBackground = new CBackground;

		// テクスチャの設定
		pBackground->SetUV(1.0f, 1.0f);

		// 初期化処理
		pBackground->Init(pos);

		pBackground->SetPosition(pos);

		// サイズの設定
		pBackground->SetSize(xsize, ysize);

		// テクスチャの割り当て
		pBackground->BindTexture(m_pTexture);

		return pBackground;
	}

	return NULL;
}

//----------------------------------------
// バックグラウンドの初期化処理
//----------------------------------------
HRESULT CBackground::Init(D3DXVECTOR3 pos)
{
	CObject2D::Init(pos);

	// 種類の設定処理
	CObject::SetType(TYPE_BACKGROUND);

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

//----------------------------------------
// バックグラウンドの位置の設定処理
//----------------------------------------
void CBackground::SetPosition(D3DXVECTOR3 pos)
{
	CObject2D::SetPosition(pos);
}

//----------------------------------------
// バックグラウンドのサイズの設定処理
//----------------------------------------
void CBackground::SetSize(float xsize, float ysize)
{
	CObject2D::SetSize(xsize, ysize);
}