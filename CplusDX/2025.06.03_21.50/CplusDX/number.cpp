//==============================================================
//
// [number.h]
// Author: Irisawa Kazan
//
//==============================================================
#include"number.h"
#include"manager.h"
#include"renderer.h"

//----------------------------------------
// コンストラクタ
//----------------------------------------
CNumber::CNumber()
{
	m_pTexture = NULL;
	m_pVtxBuff = NULL;
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_fLength = 0.0f;
	m_fAngle = 0.0f;
	m_faUV = 0.0f;
	m_fzUV = 0.0f;
	m_fxSize = 0.0f;
	m_fySize = 0.0f;
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CNumber::~CNumber()
{

}

//----------------------------------------
// 生成処理
//----------------------------------------
CNumber* CNumber::Create(D3DXVECTOR3 pos)
{
	CNumber* pNumber;

	// オブジェクト2Dの生成
	pNumber = new CNumber;

	// 初期化処理
	pNumber->Init(pos);

	return pNumber;
}

//----------------------------------------
// 初期化処理
//----------------------------------------
HRESULT CNumber::Init(D3DXVECTOR3 pos)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

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
	pVtx[0].pos.x = m_pos.x + sinf(D3DX_PI - m_fAngle) * m_fLength;
	pVtx[0].pos.y = m_pos.y + cosf(D3DX_PI - m_fAngle) * m_fLength;
	pVtx[0].pos.z = 0.0f;
	pVtx[1].pos.x = m_pos.x + sinf(D3DX_PI - m_fAngle) * m_fLength;
	pVtx[1].pos.y = m_pos.y + cosf(D3DX_PI - m_fAngle) * m_fLength;
	pVtx[1].pos.z = 0.0f;
	pVtx[2].pos.x = m_pos.x + sinf(0.0f - m_fAngle) * m_fLength;
	pVtx[2].pos.y = m_pos.y + cosf(0.0f - m_fAngle) * m_fLength;
	pVtx[2].pos.z = 0.0f;
	pVtx[3].pos.x = m_pos.x + sinf(0.0f + m_fAngle) * m_fLength;
	pVtx[3].pos.y = m_pos.y + cosf(0.0f + m_fAngle) * m_fLength;
	pVtx[3].pos.z = 0.0f;

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
	pVtx[1].tex = D3DXVECTOR2(m_faUV, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, m_fzUV);
	pVtx[3].tex = D3DXVECTOR2(m_faUV, m_fzUV);

	// 頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

	return S_OK;
}

//----------------------------------------
// 終了処理
//----------------------------------------
void CNumber::Uninit(void)
{
	// テクスチャの破棄
	if (m_pTexture != NULL)
	{
		m_pTexture = NULL;
	}

	// 頂点バッファの破棄
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
}

//----------------------------------------
// 更新処理
//----------------------------------------
void CNumber::Update(void)
{
	VERTEX_2D* pVtx; // 頂点情報へのポインタ

	// 頂点バッファをロックし,頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// 対角線の長さを算出する
	m_fLength = sqrtf(m_fxSize * m_fxSize + m_fySize * m_fySize) / 2.0f;

	// 対角線の角度を算出する
	m_fAngle = atan2f(m_fxSize, m_fySize);

	// 頂点座標の設定
	pVtx[0].pos.x = m_pos.x + sinf(D3DX_PI - m_fAngle) * m_fLength;
	pVtx[0].pos.y = m_pos.y + cosf(D3DX_PI - m_fAngle) * m_fLength;
	pVtx[0].pos.z = 0.0f;
	pVtx[1].pos.x = m_pos.x + sinf(D3DX_PI - m_fAngle) * m_fLength;
	pVtx[1].pos.y = m_pos.y + cosf(D3DX_PI - m_fAngle) * m_fLength;
	pVtx[1].pos.z = 0.0f;
	pVtx[2].pos.x = m_pos.x + sinf(0.0f - m_fAngle) * m_fLength;
	pVtx[2].pos.y = m_pos.y + cosf(0.0f - m_fAngle) * m_fLength;
	pVtx[2].pos.z = 0.0f;
	pVtx[3].pos.x = m_pos.x + sinf(0.0f + m_fAngle) * m_fLength;
	pVtx[3].pos.y = m_pos.y + cosf(0.0f + m_fAngle) * m_fLength;
	pVtx[3].pos.z = 0.0f;

	// 頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

//----------------------------------------
// 描画処理
//----------------------------------------
void CNumber::Draw(void)
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