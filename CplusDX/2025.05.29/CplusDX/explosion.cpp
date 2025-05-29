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
LPDIRECT3DTEXTURE9 CExplosion::m_pTexture[MAX_PLOTEX] = {};

//----------------------------------------
// エクスプロージョンのコンストラクタ
//----------------------------------------
CExplosion::CExplosion(int nPriority) : CObject2D(nPriority)
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
		&m_pTexture[EXPLOTYPE_000]);

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\explosion001.png",
		&m_pTexture[EXPLOTYPE_001]);

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\explosion002.png",
		&m_pTexture[EXPLOTYPE_002]);

	return S_OK;
}

//----------------------------------------
// テクスチャの生成(読み込み)
//----------------------------------------
void CExplosion::Unload(void)
{
	for (int nCount = 0; nCount < MAX_PLOTEX; nCount++)
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
// エクスプロージョンの生成処理
//----------------------------------------
CExplosion* CExplosion::Create(D3DXVECTOR3 pos, float xsize, float ysize, EXPLOTYPE type)
{
	CExplosion* pExplosion;

	int nNumAll = CObject::GetNumAll();

	if (nNumAll <= MAX_OBJ)
	{
		// オブジェクト2Dの生成
		pExplosion = new CExplosion;

		// 初期化処理
		pExplosion->Init(pos);

		// テクスチャの割り当て
		pExplosion->BindTexture(m_pTexture[type]);

		// サイズの設定
		pExplosion->SetSize(xsize, ysize);

		// テクスチャの設定
		pExplosion->SetUV(0.125f, 1.0f);

		return pExplosion;
	}

	return NULL;
}

//----------------------------------------
// エクスプロージョンの初期化処理
//----------------------------------------
HRESULT CExplosion::Init(D3DXVECTOR3 pos)
{
	CObject2D::Init(pos);

	SetPosition(pos);

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
	CObject2D::Update();

	// 位置の取得
	D3DXVECTOR3 pos = GetPos();

	CObject2D::SetPosition(pos);

	// テクスチャの設定
	CObject2D::SetUV(0.125f, 1.0f);

	CObject2D::TextureAnimation(8, 1, 12);

	int nCntAnim = CObject2D::GetCntAnim();
	int nPtAnim = CObject2D::GetPtAnim();

	if (nCntAnim == 0 && nPtAnim == 0)
	{
		Uninit();
	}
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

//----------------------------------------
// プレイヤーのサイズの設定処理
//----------------------------------------
void CExplosion::SetSize(float xsize, float ysize)
{
	CObject2D::SetSize(xsize, ysize);
}