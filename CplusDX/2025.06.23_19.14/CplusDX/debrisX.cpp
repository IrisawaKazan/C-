//==============================================================
//
// [debrisX.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"debrisX.h"
#include"manager.h"
#include"renderer.h"
#include"input.h"

//----------------------------------------
// コンストラクタ
//----------------------------------------
CDebrisX::CDebrisX(int nPriority) : CObject(nPriority)
{
	m_pTexture = nullptr;
	m_pMesh = nullptr;
	m_pBuffMat = nullptr;
	m_dwNumMat = NULL;

	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_mtxWorld = D3DXMATRIX();

	m_fRotation = 0.0f;
	m_type = DEBRIS_NONE;
	m_vtxMin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_vtxMax = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CDebrisX::~CDebrisX()
{

}

//----------------------------------------
// 生成処理
//----------------------------------------
CDebrisX* CDebrisX::Create(D3DXVECTOR3 pos, DEBRIS type)
{
	CDebrisX* pDebrisX;

	// オブジェクトXの生成
	pDebrisX = new CDebrisX;

	// 初期化処理
	pDebrisX->Init(pos);

	// タイプの設定
	pDebrisX->SetType(type);

	// 位置の設定
	pDebrisX->SetPosition(pos);

	return pDebrisX;
}

//----------------------------------------
// 初期化処理
//----------------------------------------
HRESULT CDebrisX::Init(D3DXVECTOR3 pos)
{
	// 種類の設定処理
	CObject::SetType(TYPE_DEBRIS);

	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// Xファイルの読み込み
	D3DXLoadMeshFromX("data\\MODEL\\debris000.x",
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
void CDebrisX::Uninit(void)
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
void CDebrisX::Update(void)
{
	switch (m_type)
	{
	case DEBRIS_000_A:
		m_pos.x += 1.0f;
		break;

	case DEBRIS_000_B:
		m_pos.x -= 1.0f;
		break;

	default:
		break;
	}

	// ローテーション
	m_fRotation += 1.0f;

	m_rot = D3DXVECTOR3(m_fRotation / 150.0f/* 回る速度 */, 0.0f, 0.0f);

	// 外に出ると消す
	if (m_pos.x < -350.0f || m_pos.x > 350.0f)
	{
		Uninit();

		return;
	}
}

//----------------------------------------
// 描画処理
//----------------------------------------
void CDebrisX::Draw(void)
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

//----------------------------------------
// 位置の設定処理
//----------------------------------------
void CDebrisX::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//----------------------------------------
// 向きの設定処理
//----------------------------------------
void CDebrisX::SetRotation(D3DXVECTOR3 rot)
{
	m_rot = rot;
}

//----------------------------------------
// 位置の取得処理
//----------------------------------------
D3DXVECTOR3 CDebrisX::GetPos(void)
{
	return m_pos;
}

//----------------------------------------
// 向きの取得処理
//----------------------------------------
D3DXVECTOR3 CDebrisX::GetRot(void)
{
	return m_rot;
}

//----------------------------------------
// タイプの設定処理
//----------------------------------------
void CDebrisX::SetType(DEBRIS type)
{
	m_type = type;
}

//----------------------------------------
// タイプの取得処理
//----------------------------------------
CDebrisX::DEBRIS CDebrisX::GetType(void)
{
	return m_type;
}

//----------------------------------------
// モデルの最小値の設定処理
//----------------------------------------
void CDebrisX::SetVtxMin(D3DXVECTOR3 vtxMin)
{
	m_vtxMin = vtxMin;
}

//----------------------------------------
// モデルの最大値の設定処理
//----------------------------------------
void CDebrisX::SetVtxMax(D3DXVECTOR3 vtxMax)
{
	m_vtxMax = vtxMax;
}

//----------------------------------------
// モデルの最小値の取得処理
//----------------------------------------
D3DXVECTOR3 CDebrisX::GetVtxMin(void)
{
	return m_vtxMin;
}

//----------------------------------------
// モデルの最大値の取得処理
//----------------------------------------
D3DXVECTOR3 CDebrisX::GetVtxMax(void)
{
	return m_vtxMax;
}

//----------------------------------------
// 当たり判定の処理
//----------------------------------------
void CDebrisX::Collision(void)
{
	CObjectX* pObjectX = nullptr;

	// プレイヤーの位置の取得
	D3DXVECTOR3 pos = pObjectX->GetPos();

	// プレイヤーの前回の位置の取得
	D3DXVECTOR3 posOld = pObjectX->GetPosOld();

	// プレイヤーのサイズの取得
	D3DXVECTOR3 size = pObjectX->GetSize();

	CDebrisX* pDebrisX = nullptr;

	// 位置の取得
	D3DXVECTOR3 posDebris = pDebrisX->GetPos();

	// モデルの取得
	D3DXVECTOR3 vtxMin = pDebrisX->GetVtxMin();
	D3DXVECTOR3 vtxMax = pDebrisX->GetVtxMax();

	// 左右のめり込み判定
	if (pos.z + size.z / 2.0f > posDebris.z + vtxMax.z &&
		pos.z + size.z / 2.0f < posDebris.z - vtxMin.z * 2.0f)
	{
		// 左から右へ
		if (posOld.x + size.x / 2.0f > posDebris.x + vtxMin.x &&
			pos.x + size.x / 2.0f < posDebris.x - vtxMin.x)
		{
			pObjectX->Uninit();
		}
		// 右から左へ
		if (posOld.x - size.x / 2.0f < posDebris.x - vtxMax.x &&
			pos.x - size.x / 2.0f > posDebris.x + vtxMax.x)
		{
			pObjectX->Uninit();
		}
	}
}