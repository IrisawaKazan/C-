//==============================================================
//
// [objectX.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"objectX.h"
#include"manager.h"
#include"renderer.h"
#include"input.h"

//----------------------------------------
// コンストラクタ
//----------------------------------------
CObjectX::CObjectX(int nPriority) : CObject(nPriority)
{
	m_pTexture = nullptr;
	m_pMesh = nullptr;
	m_pBuffMat = nullptr;
	m_dwNumMat = NULL;
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_mtxWorld = D3DXMATRIX();
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CObjectX::~CObjectX()
{

}

//----------------------------------------
// 生成処理
//----------------------------------------
CObjectX* CObjectX::Create(D3DXVECTOR3 pos)
{
	CObjectX* pObjectX;

	// オブジェクトXの生成
	pObjectX = new CObjectX;

	// 初期化処理
	pObjectX->Init(pos);

	// 位置の設定
	pObjectX->SetPosition(pos);

	return pObjectX;
}

//----------------------------------------
// 初期化処理
//----------------------------------------
HRESULT CObjectX::Init(D3DXVECTOR3 pos)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// Xファイルの読み込み
	D3DXLoadMeshFromX("data\\MODEL\\BOX.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&m_pBuffMat,
		NULL,
		&m_dwNumMat,
		&m_pMesh);

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
void CObjectX::Uninit(void)
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

	CObject::Release();
}

//----------------------------------------
// 更新処理
//----------------------------------------
void CObjectX::Update(void)
{
	CInputKeyboard* pInputKeyboard;

	// キーボードの取得
	pInputKeyboard = CManager::GetInputKeyboard();

	// プレイヤー移動
	if (pInputKeyboard->GetPress(DIK_A) == true)
	{// 左
		if (pInputKeyboard->GetPress(DIK_W) == true)
		{// 左奥に移動
			// 左
			m_pos.x -= MAX_PMOVE / sqrtf(4.0f);
			m_rot.y = m_rot.y;

			// 奥
			m_pos.z += MAX_PMOVE / sqrtf(4.0f);
			m_rot.y = m_rot.y;
		}
		else if (pInputKeyboard->GetPress(DIK_S) == true)
		{// 左手前に移動
			// 左
			m_pos.x -= MAX_PMOVE / sqrtf(4.0f);
			m_rot.y = m_rot.y;

			// 手前
			m_pos.z -= MAX_PMOVE / sqrtf(4.0f);
			m_rot.y = m_rot.y;
		}
		else
		{// 左に移動
			m_pos.x -= MAX_PMOVE;
			m_rot.y = m_rot.y;
		}
	}
	if (pInputKeyboard->GetPress(DIK_D) == true)
	{// 右
		if (pInputKeyboard->GetPress(DIK_W) == true)
		{// 右に移動
			// 右
			m_pos.x += MAX_PMOVE / sqrtf(4.0f);
			m_rot.y = m_rot.y;

			// 奥
			m_pos.z += MAX_PMOVE / sqrtf(4.0f);
			m_rot.y = m_rot.y;
		}
		else if (pInputKeyboard->GetPress(DIK_S) == true)
		{// 右手前に移動
			// 右
			m_pos.x += MAX_PMOVE / sqrtf(4.0f);
			m_rot.y = m_rot.y;

			// 手前
			m_pos.z -= MAX_PMOVE / sqrtf(4.0f);
			m_rot.y = m_rot.y;
		}
		else
		{// 右に移動
			m_pos.x += MAX_PMOVE;
			m_rot.y = m_rot.y;
		}
	}
	if (pInputKeyboard->GetPress(DIK_W) == true)
	{// 奥
		m_pos.z += MAX_PMOVE;
		m_rot.y = m_rot.y;
	}
	if (pInputKeyboard->GetPress(DIK_S) == true)
	{// 手前
		m_pos.z -= MAX_PMOVE;
		m_rot.y = m_rot.y;
	}

	// 常に後退する
	//m_pos.z -= 0.5f;
}

//----------------------------------------
// 描画処理
//----------------------------------------
void CObjectX::Draw(void)
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
void CObjectX::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//----------------------------------------
// 位置の取得処理
//----------------------------------------
D3DXVECTOR3 CObjectX::GetPos(void)
{
	return m_pos;
}