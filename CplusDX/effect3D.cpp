//==============================================================
//
// [effect3D.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"effect3D.h"
#include"manager.h"
#include"renderer.h"

// 静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CEffect3D::m_pTexture = nullptr;

//----------------------------------------
// コンストラクタ
//----------------------------------------
CEffect3D::CEffect3D(int nPriority) : CObjectBillboard(nPriority)
{
	m_pTexture = nullptr;
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_fRedius = 0.0f;
	m_nLife = NULL;
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CEffect3D::~CEffect3D()
{

}

//----------------------------------------
// テクスチャの生成(読み込み)
//----------------------------------------
HRESULT CEffect3D::Load(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\effect000.jpg",
		&m_pTexture);

	return S_OK;
}

//----------------------------------------
// テクスチャの破棄
//----------------------------------------
void CEffect3D::Unload(void)
{
	// テクスチャの破棄
	if (m_pTexture != nullptr)
	{
		m_pTexture->Release();
		m_pTexture = nullptr;
	}
}

//----------------------------------------
// 生成処理
//----------------------------------------
CEffect3D* CEffect3D::Create(D3DXVECTOR3 pos, D3DXCOLOR col, float fRedius, int nLife, float sizeX, float sizeY)
{
	CEffect3D* pEffect;

	int nNumAll = CObject::GetNumAll();

	if (nNumAll <= MAX_OBJ)
	{
		// オブジェクト3Dの生成
		pEffect = new CEffect3D;

		// 初期化処理
		pEffect->Init(pos, col, fRedius, nLife);

		// サイズの設定
		pEffect->SetSize(sizeX, sizeY);

		// テクスチャの割り当て
		pEffect->BindTexture(m_pTexture);

		return pEffect;
	}

	return NULL;
}

//----------------------------------------
// 初期化処理
//----------------------------------------
HRESULT CEffect3D::Init(D3DXVECTOR3 pos, D3DXCOLOR col, float fRedius, int nLife)
{
	// テクスチャの設定
	CObjectBillboard::SetUV(1.0f, 1.0f);

	SetPosition(pos);

	CObjectBillboard::Init();

	m_pos = pos;

	m_col = col;

	m_fRedius = fRedius;

	m_nLife = nLife;

	// 種類の設定処理
	CObject::SetType(TYPE_EFFECT3D);

	return S_OK;
}

//----------------------------------------
// 終了処理
//----------------------------------------
void CEffect3D::Uninit(void)
{
	CObjectBillboard::Uninit();
}

//----------------------------------------
// 更新処理
//----------------------------------------
void CEffect3D::Update(void)
{
	CObjectBillboard::Update();

	CObjectBillboard::SetEffect(m_pos, m_col, m_fRedius);

	m_nLife--;

	m_fRedius -= 1.5f;

	if (m_nLife == 0)
	{
		Uninit();
	}
}

//----------------------------------------
// 描画処理
//----------------------------------------
void CEffect3D::Draw(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// αブレンディングを加算合成に設定
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 5);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	CObjectBillboard::Draw();

	// αブレンディングを元に戻す
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}

//----------------------------------------
// エフェクトの位置の設定処理
//----------------------------------------
void CEffect3D::SetPosition(D3DXVECTOR3 pos)
{
	CObjectBillboard::SetPosition(pos);
}

//----------------------------------------
// エフェクトのサイズの設定処理
//----------------------------------------
void CEffect3D::SetSize(float sizeX, float sizeY)
{
	CObjectBillboard::SetSize(sizeX, sizeY);
}