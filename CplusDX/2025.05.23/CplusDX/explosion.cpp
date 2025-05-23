//==============================================================
//
// [explosion.h]
// Author: Irisawa Kazan
//
//==============================================================
#include"explosion.h"
#include"manager.h"
#include"renderer.h"

// 静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CExplosion::m_pTexture = 0;

//----------------------------------------
// エクスプロージョンのコンストラクタ
//----------------------------------------
CExplosion::CExplosion()
{

}

//----------------------------------------
// エクスプロージョンのデストラクタ
//----------------------------------------
CExplosion::~CExplosion()
{

}

//----------------------------------------
// テクスチャの生成(読み込み)
//----------------------------------------
HRESULT CExplosion::Load(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\explosion000.png",
		&m_pTexture);

	return S_OK;
}

//----------------------------------------
// テクスチャの生成(読み込み)
//----------------------------------------
void CExplosion::Unload(void)
{
	// テクスチャの破棄
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//----------------------------------------
// エクスプロージョンの生成処理
//----------------------------------------
CExplosion* CExplosion::Create(D3DXVECTOR3 pos)
{
	CExplosion* pExplosion;

	// テクスチャの設定
	CObject2D::SetUV(0.125f, 1.0f);

	// サイズの設定
	//CObject2D::SetSize(0.0f, 0.0f);

	// オブジェクト2Dの生成
	pExplosion = new CExplosion;

	// 初期化処理
	pExplosion->Init(pos);

	pExplosion->SetPosition(pos);

	// テクスチャの割り当て
	pExplosion->BindTexture(m_pTexture);

	return pExplosion;
}

//----------------------------------------
// エクスプロージョンの初期化処理
//----------------------------------------
HRESULT CExplosion::Init(D3DXVECTOR3 pos)
{
	CObject2D::Init(pos);

	return S_OK;
}

//----------------------------------------
// エクスプロージョンの終了処理
//----------------------------------------
void CExplosion::Uninit(void)
{
	CObject2D::Uninit();
}

//----------------------------------------
// エクスプロージョンの更新処理
//----------------------------------------
void CExplosion::Update(void)
{
	// 位置の取得
	D3DXVECTOR3 pos = CExplosion::GetPos();

	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	VERTEX_2D* pVtx = NULL; // 頂点情報へのポインタ

	CObject2D::TextureAnimation(8, 1, 5);

	CExplosion::SetPosition(pos);

	CObject2D::Update();

	//CExplosion::Release();
}

//----------------------------------------
// エクスプロージョンの描画処理
//----------------------------------------
void CExplosion::Draw(void)
{
	CObject2D::Draw();
}

//----------------------------------------
// エクスプロージョンの位置の設定処理
//----------------------------------------
void CExplosion::SetPosition(D3DXVECTOR3 pos)
{
	CObject2D::SetPosition(pos);
}