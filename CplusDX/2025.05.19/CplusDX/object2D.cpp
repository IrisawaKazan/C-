//==============================================================
//
// [object2D.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"object2D.h"
#include"renderer.h"
#include"manager.h"
#include"input.h"

//// 静的メンバ変数宣言
//LPDIRECT3DTEXTURE9 m_pTexture = {};
//LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff = {};
//D3DXVECTOR3 m_pos = {};

//----------------------------------------
// コンストラクタ
//----------------------------------------
CObject2D::CObject2D()
{
	m_pTexture = NULL;
	m_pVtxBuff = NULL;
	m_pos = D3DXVECTOR3(NULL, NULL, NULL);
	//m_rot = D3DXVECTOR3(NULL, NULL, NULL);
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CObject2D::~CObject2D()
{

}

//----------------------------------------
// 生成処理
//----------------------------------------
CObject2D* CObject2D::Create(void)
{
	CObject2D* pObject2D;

	// オブジェクト2Dの生成
	pObject2D = new CObject2D;

	// 初期化処理
	pObject2D->Init();

	return pObject2D;
}

//----------------------------------------
// 初期化処理
//----------------------------------------
HRESULT CObject2D::Init(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\sample.png",
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
	pVtx[0].pos.x = m_pos.x - 50.0f;
	pVtx[0].pos.y = m_pos.y;
	pVtx[0].pos.z = 0.0f;
	pVtx[1].pos.x = m_pos.x + 50.0f;
	pVtx[1].pos.y = m_pos.y;
	pVtx[1].pos.z = 0.0f;
	pVtx[2].pos.x = m_pos.x - 50.0f;
	pVtx[2].pos.y = m_pos.y + 80.0f;
	pVtx[2].pos.z = 0.0f;
	pVtx[3].pos.x = m_pos.x + 50.0f;
	pVtx[3].pos.y = m_pos.y + 80.0f;
	pVtx[3].pos.z = 0.0f;
	//pVtx[0].pos = D3DXVECTOR3(450.0f, 150.0f, 0.0f);
	//pVtx[1].pos = D3DXVECTOR3(850.0f, 150.0f, 0.0f);
	//pVtx[2].pos = D3DXVECTOR3(450.0f, 550.0f, 0.0f);
	//pVtx[3].pos = D3DXVECTOR3(850.0f, 550.0f, 0.0f);

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
// 終了処理
//----------------------------------------
void CObject2D::Uninit(void)
{
	// テクスチャの破棄
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}

	// オブジェクト(自分自身)の破棄
	CObject::Release();
}

//----------------------------------------
// 更新処理
//----------------------------------------
void CObject2D::Update(void)
{
	CInputKeyboard* pInputKeyboard;

	// キーボードの取得
	pInputKeyboard = CManager::GetInputKeyboard();

	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	VERTEX_2D* pVtx = NULL; // 頂点情報へのポインタ

	// 頂点バッファをロックし,頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	int nSurprise = NULL;

	// 上へ移動
	if (pInputKeyboard->GetTrigger(DIK_UP) == true)
	{
		m_pos.y -= 50.0f;
	}
	// 左へ移動
	if (pInputKeyboard->GetTrigger(DIK_LEFT) == true)
	{
		m_pos.x -= 50.0f;
	}
	// 下へ移動
	if (pInputKeyboard->GetTrigger(DIK_DOWN) == true)
	{
		m_pos.y += 50.0f;
	}
	// 右へ移動
	if (pInputKeyboard->GetTrigger(DIK_RIGHT) == true)
	{
		m_pos.x += 50.0f;
	}
	if (pInputKeyboard->GetPress(DIK_SPACE) == true)
	{
		nSurprise += 25.0f;
	}

	// 頂点座標の設定
	pVtx[0].pos.x = m_pos.x - 50.0f - nSurprise;
	pVtx[0].pos.y = m_pos.y - nSurprise;
	pVtx[0].pos.z = 0.0f;
	pVtx[1].pos.x = m_pos.x + 50.0f + nSurprise;
	pVtx[1].pos.y = m_pos.y - nSurprise;
	pVtx[1].pos.z = 0.0f;
	pVtx[2].pos.x = m_pos.x - 50.0f - nSurprise;
	pVtx[2].pos.y = m_pos.y + 80.0f + nSurprise;
	pVtx[2].pos.z = 0.0f;
	pVtx[3].pos.x = m_pos.x + 50.0f + nSurprise;
	pVtx[3].pos.y = m_pos.y + 80.0f + nSurprise;
	pVtx[3].pos.z = 0.0f;

	// 頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

//----------------------------------------
// 描画処理
//----------------------------------------
void CObject2D::Draw(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// 頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	// 頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	// テクスチャの設定
	pDevice->SetTexture(0, m_pTexture);

	// プレイヤーの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

//----------------------------------------
// 位置の設定処理
//----------------------------------------
void CObject2D::SetPosition(D3DXVECTOR3 pos)
{
	VERTEX_2D* pVtx; // 頂点情報へのポインタ

	// 頂点バッファをロックし,頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	m_pos = pos;

	pVtx[0].pos.x = m_pos.x - 50.0f;
	pVtx[0].pos.y = m_pos.y;
	pVtx[0].pos.z = 0.0f;
	pVtx[1].pos.x = m_pos.x + 50.0f;
	pVtx[1].pos.y = m_pos.y;
	pVtx[1].pos.z = 0.0f;
	pVtx[2].pos.x = m_pos.x - 50.0f;
	pVtx[2].pos.y = m_pos.y + 80.0f;
	pVtx[2].pos.z = 0.0f;
	pVtx[3].pos.x = m_pos.x + 50.0f;
	pVtx[3].pos.y = m_pos.y + 80.0f;
	pVtx[3].pos.z = 0.0f;

	// 頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}