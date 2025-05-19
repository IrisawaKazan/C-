//==============================================================
//
// [background.h]
// Author: Irisawa Kazan
//
//==============================================================
#include"background.h"
#include"manager.h"

//----------------------------------------
// 生成処理
//----------------------------------------
CBackground* CBackground::Create(void)
{
	CBackground* pCBackground;

	// オブジェクト2Dの生成
	pCBackground = new CBackground;

	// 初期化処理
	pCBackground->Init();

	return pCBackground;
}

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
// バックグラウンドの初期化処理
//----------------------------------------
HRESULT CBackground::Init(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\background100.jpg",
		&m_pTexture);

	// 頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_2D* pVtx; // 頂点情報へのポインタ

	// 頂点バッファをロックし,頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDTH, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f);

	// rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	// 頂点カラーの設定
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	// テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	// 頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

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

}

//----------------------------------------
// バックグラウンドの描画処理
//----------------------------------------
void CBackground::Draw(void)
{
	CObject2D::Draw();
}