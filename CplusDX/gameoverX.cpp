//==============================================================
//
// [gameoverX.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"gameoverX.h"
#include"manager.h"
#include"renderer.h"
#include"game.h"
#include"input.h"
#include"objectX.h"
#include"sound.h"

//----------------------------------------
// コンストラクタ
//----------------------------------------
CGameoverX::CGameoverX(int nPriority) : CObject(nPriority)
{
	m_pTexture = nullptr;
	m_pMesh = nullptr;
	m_pBuffMat = nullptr;
	m_dwNumMat = NULL;
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_mtxWorld = D3DXMATRIX();

	m_nCounter = NULL;
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CGameoverX::~CGameoverX()
{

}

//----------------------------------------
// 生成処理
//----------------------------------------
CGameoverX* CGameoverX::Create(D3DXVECTOR3 pos)
{
	CGameoverX* pGameoverX;

	// オブジェクトXの生成
	pGameoverX = new CGameoverX;

	// 初期化処理
	pGameoverX->Init();

	// 位置の設定
	pGameoverX->SetPosition(pos);

	return pGameoverX;
}

//----------------------------------------
// 初期化処理
//----------------------------------------
HRESULT CGameoverX::Init(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	//m_rot = D3DXVECTOR3(D3DX_PI / -7.5f, 0.0f, 0.0f);

	// Xファイルの読み込み
	D3DXLoadMeshFromX("data\\MODEL\\gameover.x",
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
void CGameoverX::Uninit(void)
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
void CGameoverX::Update(void)
{
	CInputKeyboard* pInputKeyboard;

	// キーボードの取得
	pInputKeyboard = CManager::GetInputKeyboard();

	CInputMouse* pInputMouse;

	// マウスの取得
	pInputMouse = CManager::GetInputMouse();

	CInputJoypad* pInputJoypad;

	// パッドの取得
	pInputJoypad = CManager::GetInputJoypad();

	// サウンドの取得
	//CSound* pSound = CManager::GetSound();

	CObjectX* pObjectX = CGame::GetObjectX();

	if (pObjectX->GetEnable() == false)
	{
		if (m_nCounter <= 60)
		{
			if (pInputKeyboard->GetPress(DIK_SPACE) == true)
			{
				m_pos.y += 3.0f;

				m_nCounter++;
			}
		}
		if (m_nCounter >= 60 && m_pos.z <= 75.0f && m_pos.z >= -75.0f)
		{
			if (pInputKeyboard->GetPress(DIK_W) == true)
			{
				m_pos.z -= 1.0f;
			}
			if (pInputKeyboard->GetPress(DIK_S) == true)
			{
				m_pos.z += 1.0f;
			}
		}
		if (pInputKeyboard->GetPress(DIK_R) == true)
		{
			m_pos.y = 70.0f;

			m_pos.z = 0.0f;

			m_nCounter = 0;
		}
	}
}

//----------------------------------------
// 描画処理
//----------------------------------------
void CGameoverX::Draw(void)
{
	CObjectX* pObjectX = CGame::GetObjectX();

	if (pObjectX->GetEnable() == false)
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
void CGameoverX::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//----------------------------------------
// 位置の取得処理
//----------------------------------------
D3DXVECTOR3 CGameoverX::GetPos(void)
{
	return m_pos;
}