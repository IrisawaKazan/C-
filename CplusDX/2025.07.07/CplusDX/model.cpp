//==============================================================
//
// [model.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"model.h"
#include"manager.h"
#include"renderer.h"

//----------------------------------------
// コンストラクタ
//----------------------------------------
CModel::CModel()
{
	m_pTexture = nullptr;
	m_pMesh = nullptr;
	m_pBuffMat = nullptr;
	m_dwNumMat = NULL;
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_mtxWorld = D3DXMATRIX();
	m_pParent = nullptr;
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CModel::~CModel()
{

}

//----------------------------------------
// 生成処理
//----------------------------------------
CModel* CModel::Create(D3DXVECTOR3 pos)
{
	CModel* pModel;

	// オブジェクト2Dの生成
	pModel = new CModel;

	// 初期化処理
	pModel->Init(pos);

	return pModel;
}

//----------------------------------------
// 初期化処理
//----------------------------------------
HRESULT CModel::Init(D3DXVECTOR3 pos)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// Xファイルの読み込み
	D3DXLoadMeshFromX("data\\MODEL\\00_body000.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&m_pBuffMat,
		NULL,
		&m_dwNumMat,
		&m_pMesh);

	// Xファイルの読み込み
	D3DXLoadMeshFromX("data\\MODEL\\01_head000.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&m_pBuffMat,
		NULL,
		&m_dwNumMat,
		&m_pMesh);

	// マテリアルへのポインタ
	D3DXMATERIAL* pMat = nullptr;

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
void CModel::Uninit(void)
{
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
}

//----------------------------------------
// 更新処理
//----------------------------------------
void CModel::Update(void)
{

}

//----------------------------------------
// 描画処理
//----------------------------------------
void CModel::Draw(void)
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

	// 親モデルのマトリックス
	D3DXMATRIX mtxParent;

	if (m_pParent != nullptr)
	{// 親が存在する
		// 親モデルのマトリックスを取得する
		mtxParent = m_pParent->GetMtxWorld();
	}
	else
	{// 親が存在しない
		// 現在(最新)のマトリックスを取得する[ = プレイヤーのマトリックス]
		pDevice->GetTransform(D3DTS_WORLD, &mtxParent);
	}

	// 親のマトリックスと掛け合わせる
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxParent);

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
// 親モデルの設定処理
//----------------------------------------
void CModel::SetParent(CModel* pModel)
{
	m_pParent = pModel;
}

//----------------------------------------
// マトリックスの取得処理
//----------------------------------------
D3DXMATRIX CModel::GetMtxWorld(void)
{
	return m_mtxWorld;
}