//==============================================================
//
// [coin10X.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"coin10X.h"
#include"renderer.h"
#include"input.h"
#include"objectX.h"

//----------------------------------------
// コンストラクタ
//----------------------------------------
CCoin10X::CCoin10X(int nPriority) : CObject(nPriority)
{
	m_pTexture = nullptr;
	m_pMesh = nullptr;
	m_pBuffMat = nullptr;
	m_dwNumMat = NULL;

	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_mtxWorld = D3DXMATRIX();

	m_fRotation = 0.0f;
	m_type = COIN10_NONE;
	m_vtxMin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_vtxMax = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CCoin10X::~CCoin10X()
{

}

//----------------------------------------
// 生成処理
//----------------------------------------
CCoin10X* CCoin10X::Create(D3DXVECTOR3 pos, COIN10 type)
{
	CCoin10X* pCoin10X;

	int nNumAll = CObject::GetNumAll();

	if (nNumAll <= MAX_OBJ)
	{
		// オブジェクトXの生成
		pCoin10X = new CCoin10X;

		// 初期化処理
		pCoin10X->Init(pos);

		// タイプの設定
		pCoin10X->SetType(type);

		// 位置の設定
		pCoin10X->SetPosition(pos);

		return pCoin10X;
	}

	return NULL;
}

//----------------------------------------
// 初期化処理
//----------------------------------------
HRESULT CCoin10X::Init(D3DXVECTOR3 pos)
{
	// 種類の設定処理
	CObject::SetType(TYPE_COIN10);

	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// Xファイルの読み込み
	D3DXLoadMeshFromX("data\\MODEL\\score_coin10.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&m_pBuffMat,
		NULL,
		&m_dwNumMat,
		&m_pMesh);

	int nNumVtx;    // 頂点数
	DWORD sizeFVF;  // 頂点フォーマットのサイズ
	BYTE* pVtxBuff; // 頂点バッファのポインタ

	// 頂点数の取得
	nNumVtx = m_pMesh->GetNumVertices();

	// 頂点フォーマットのサイズを取得
	sizeFVF = D3DXGetFVFVertexSize(m_pMesh->GetFVF());

	// 頂点バッファのロック
	m_pMesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBuff);

	for (int nCntVtx = 0; nCntVtx < nNumVtx; nCntVtx++)
	{
		// 頂点座標の代入
		D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVtxBuff;

		// 頂点座標を比較してモデルの最小値,最大値を取得
		if (vtx.x <= m_vtxMin.x)
		{
			m_vtxMin.x = vtx.x;
		}

		if (vtx.y <= m_vtxMin.y)
		{
			m_vtxMin.y = vtx.y;
		}

		if (vtx.z <= m_vtxMin.z)
		{
			m_vtxMin.z = vtx.z;
		}

		if (vtx.x <= m_vtxMax.x)
		{
			m_vtxMax.x = vtx.x;
		}

		if (vtx.y <= m_vtxMax.y)
		{
			m_vtxMax.y = vtx.y;
		}

		if (vtx.z <= m_vtxMax.z)
		{
			m_vtxMax.z = vtx.z;
		}

		// 頂点フォーマットのサイズ分ポインタを進める
		pVtxBuff += sizeFVF;
	}

	// 頂点バッファのアンロック
	m_pMesh->UnlockVertexBuffer();

	D3DXMATERIAL* pMat = nullptr; // マテリアルへのポインタ

	// マテリアルのデータへのポインタを取得
	pMat = (D3DXMATERIAL*)m_pBuffMat->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)m_dwNumMat; nCntMat++)
	{
		if (pMat[nCntMat].pTextureFilename != nullptr)
		{
			// このファイル名を使用してテクスチャを読み込む


			// テクスチャの読み込み


			D3DXCreateTextureFromFile(pDevice, pMat[nCntMat].pTextureFilename, &m_pTexture);
		}
	}

	return S_OK;
}

//----------------------------------------
// 終了処理
//----------------------------------------
void CCoin10X::Uninit(void)
{
	// テクスチャの破棄
	if (m_pTexture != nullptr)
	{
		m_pTexture = nullptr;
	}

	// メッシュの破棄
	if (m_pMesh != nullptr)
	{
		m_pMesh->Release();
		m_pMesh = nullptr;
	}

	// マテリアルの破棄
	if (m_pBuffMat != nullptr)
	{
		m_pBuffMat->Release();
		m_pBuffMat = nullptr;
	}

	this->Release();
}

//----------------------------------------
// 更新処理
//----------------------------------------
void CCoin10X::Update(void)
{
	CObjectX* pObjectX = CManager::GetObjectX();

	if (pObjectX->GetEnable() == true)
	{
		switch (m_type)
		{
		case COIN10_000_A:
			m_pos.x += 1.5f;
			// ローテーション
			m_fRotation += 1.0f;

			m_rot = D3DXVECTOR3(0.0f, 0.0f, m_fRotation / 17.5f/* 回る速度 */);
			break;

		case COIN10_000_B:
			m_pos.x -= 1.5f;
			// ローテーション
			m_fRotation -= 1.0f;

			m_rot = D3DXVECTOR3(0.0f, 0.0f, m_fRotation / 17.5f/* 回る速度 */);
			break;

		default:
			break;
		}

		// 外に出ると消す
		if (m_pos.x < -COIN10_UNINIT_POS || m_pos.x > COIN10_UNINIT_POS)
		{
			Uninit();

			return;
		}

		// 当たり判定
		Collision();
	}
}

//----------------------------------------
// 描画処理
//----------------------------------------
void CCoin10X::Draw(void)
{
	CObjectX* pObjectX = CManager::GetObjectX();

	if (pObjectX->GetEnable() == true)
	{
		// デバイスの取得
		LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

		// 計算用のマトリックス
		D3DXMATRIX mtxRot, mtxTrans;

		D3DMATERIAL9 matDef; // 現在のマテリアル保存用

		D3DXMATERIAL* pMat; // マテリアルデータへのポインタ

		// ワールドマトリックスの初期化
		D3DXMatrixIdentity(&m_mtxWorld);

		// 向きを反映
		D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

		// 位置を反映
		D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

		// ワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

		// 現在のマテリアルを取得
		pDevice->GetMaterial(&matDef);

		// マテリアルのデータへのポインタを取得
		pMat = (D3DXMATERIAL*)m_pBuffMat->GetBufferPointer();

		for (int nCntMat = 0; nCntMat < (int)m_dwNumMat; nCntMat++)
		{
			// マテリアルの設定
			pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

			// テクスチャの設定
			pDevice->SetTexture(0, m_pTexture); // 今はNULL

			// モデル(パーツ)の描画
			m_pMesh->DrawSubset(nCntMat);
		}

		// 保存していたマテリアルを元に戻す
		pDevice->SetMaterial(&matDef);
	}
}

//----------------------------------------
// 位置の設定処理
//----------------------------------------
void CCoin10X::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//----------------------------------------
// 向きの設定処理
//----------------------------------------
void CCoin10X::SetRotation(D3DXVECTOR3 rot)
{
	m_rot = rot;
}

//----------------------------------------
// 位置の取得処理
//----------------------------------------
D3DXVECTOR3 CCoin10X::GetPos(void)
{
	return m_pos;
}

//----------------------------------------
// 向きの取得処理
//----------------------------------------
D3DXVECTOR3 CCoin10X::GetRot(void)
{
	return m_rot;
}

//----------------------------------------
// タイプの設定処理
//----------------------------------------
void CCoin10X::SetType(COIN10 type)
{
	m_type = type;
}

//----------------------------------------
// タイプの取得処理
//----------------------------------------
CCoin10X::COIN10 CCoin10X::GetType(void)
{
	return m_type;
}

//----------------------------------------
// 当たり判定の処理
//----------------------------------------
void CCoin10X::Collision(void)
{
	CObjectX* pObjectX = CManager::GetObjectX();

	// 左右の判定の広さ
	float fNum = 2.0f;

	if (pObjectX->GetEnable() == true)
	{
		// プレイヤーの位置の取得
		D3DXVECTOR3 pos = pObjectX->GetPos();

		// プレイヤーの前回の位置の取得
		D3DXVECTOR3 posOld = pObjectX->GetPosOld();

		// プレイヤーのサイズの取得
		D3DXVECTOR3 size = pObjectX->GetSize();

		// 左右のめり込み判定
		if (pos.z + size.z / fNum > m_pos.z + m_vtxMax.z &&
			pos.z + size.z / fNum < m_pos.z - m_vtxMin.z * 2.0f)
		{
			// 左から右へ
			if (posOld.x + size.x / fNum > m_pos.x + m_vtxMin.x &&
				pos.x + size.x / fNum < m_pos.x - m_vtxMin.x)
			{
				// スコア加算
				CScore::AddScore(10);

				Uninit();

				return;
			}
			// 右から左へ
			if (posOld.x - size.x / fNum < m_pos.x - m_vtxMax.x &&
				pos.x - size.x / fNum > m_pos.x + m_vtxMax.x)
			{
				// スコア加算
				CScore::AddScore(10);

				Uninit();

				return;
			}
		}
	}
}