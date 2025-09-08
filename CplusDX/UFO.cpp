//==============================================================
//
// [UFO.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"UFO.h"
#include"manager.h"
#include"renderer.h"
#include"game.h"
#include"input.h"
#include"objectX.h"
#include"title.h"

//----------------------------------------
// コンストラクタ
//----------------------------------------
CUfo::CUfo(int nPriority) : CObject(nPriority)
{
	m_pTexture = nullptr;
	m_pMesh = nullptr;
	m_pBuffMat = nullptr;
	m_dwNumMat = NULL;
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_mtxWorld = D3DXMATRIX();

	m_fRotation = 0.0f;

	m_fDiagonal = 0.0f;

	m_type = UFO_NONE;
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CUfo::~CUfo()
{

}

//----------------------------------------
// 生成処理
//----------------------------------------
CUfo* CUfo::Create(D3DXVECTOR3 pos, UFO type)
{
	CUfo* pUfo;

	int nNumAll = CObject::GetNumAll();

	if (nNumAll <= MAX_OBJ)
	{
		// オブジェクトXの生成
		pUfo = new CUfo;

		// 初期化処理
		pUfo->Init();

		// タイプの設定
		pUfo->SetType(type);

		// 位置の設定
		pUfo->SetPosition(pos);

		return pUfo;
	}

	return NULL;
}

//----------------------------------------
// 初期化処理
//----------------------------------------
HRESULT CUfo::Init(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// Xファイルの読み込み
	D3DXLoadMeshFromX("data\\MODEL\\UFO.x",
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
void CUfo::Uninit(void)
{
	// テクスチャへのポインタの破棄
	if (m_pTexture != nullptr)
	{
		m_pTexture->Release();
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

	CObject::Release();
}

//----------------------------------------
// 更新処理
//----------------------------------------
void CUfo::Update(void)
{
	CObjectX* pObjectX = CGame::GetObjectX();

	CInputKeyboard* pInputKeyboard;

	// キーボードの取得
	pInputKeyboard = CManager::GetInputKeyboard();

	CInputMouse* pInputMouse;

	// マウスの取得
	pInputMouse = CManager::GetInputMouse();

	CInputJoypad* pInputJoypad;

	// パッドの取得
	pInputJoypad = CManager::GetInputJoypad();

	//if (pObjectX->GetEnable() == true)
	{
		// 前回の位置を保存
		m_posOld = m_pos;

		float fDiagonal = (float)(rand() % 5);

		// 斜め移動
		m_fDiagonal += 1.0f + fDiagonal;

		float fSpeedUp = 0.0f;

		// ローテーション
		m_fRotation += 1.0f + fSpeedUp;

		switch (m_type)
		{
		case UFO_000_A:
			m_pos.z += 2.0f;
			m_pos.y += 0.05f;
			m_pos.x += fDiagonal;
			m_rot = D3DXVECTOR3(0.0f, -m_fRotation / 500.0f/* 回る速度 */, 0.0f);
			break;

		case UFO_000_B:
			m_pos.z -= 3.0f;
			m_pos.y -= 0.1f;
			m_pos.x -= fDiagonal;
			m_rot = D3DXVECTOR3(0.0f, m_fRotation / 500.0f/* 回る速度 */, 0.0f);
			break;

		default:
			break;
		}

		// 外に出ると消す
		if (m_pos.x < -UNINIT_POS || m_pos.x > UNINIT_POS || m_pos.z < -UNINIT_POS_Z || m_pos.z > UNINIT_POS_Z)
		{
			Uninit();

			return;
		}
	}
}

//----------------------------------------
// 描画処理
//----------------------------------------
void CUfo::Draw(void)
{
	//CObjectX* pObjectX = CGame::GetObjectX();

	//if (pObjectX->GetEnable() == true)
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
void CUfo::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//----------------------------------------
// 位置の取得処理
//----------------------------------------
D3DXVECTOR3 CUfo::GetPos(void)
{
	return m_pos;
}

//----------------------------------------
// タイプの設定処理
//----------------------------------------
void CUfo::SetType(UFO type)
{
	m_type = type;
}

//----------------------------------------
// タイプの取得処理
//----------------------------------------
CUfo::UFO CUfo::GetType(void)
{
	return m_type;
}