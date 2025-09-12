//==============================================================
//
// [mfX.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"mfX.h"
#include"manager.h"
#include"renderer.h"
#include"input.h"
#include"effect.h"
#include"sound.h"
#include"game.h"
#include"effect.h"

//----------------------------------------
// コンストラクタ
//----------------------------------------
CMf::CMf(int nPriority) : CObject(nPriority)
{
	m_pTexture = nullptr;
	m_pMesh = nullptr;
	m_pBuffMat = nullptr;
	m_dwNumMat = NULL;
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_mtxWorld = D3DXMATRIX();

	m_fMove = 0.0f;
	m_nMovingCounter = NULL;
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CMf::~CMf()
{

}

//----------------------------------------
// 生成処理
//----------------------------------------
CMf* CMf::Create(D3DXVECTOR3 pos)
{
	CMf* pMf;

	// オブジェクトXの生成
	pMf = new CMf;

	// 初期化処理
	pMf->Init();

	// 位置の設定
	pMf->SetPosition(pos);

	return pMf;
}

//----------------------------------------
// 初期化処理
//----------------------------------------
HRESULT CMf::Init(void)
{
	m_nMovingCounter = 0;

	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// Xファイルの読み込み
	D3DXLoadMeshFromX("data\\MODEL\\mf.x",
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
void CMf::Uninit(void)
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
	//this->Release();
}

//----------------------------------------
// 更新処理
//----------------------------------------
void CMf::Update(void)
{
	// キーボードの取得
	CInputKeyboard* pInputKeyboard;
	pInputKeyboard = CManager::GetInputKeyboard();

	// マウスの取得
	CInputMouse* pInputMouse;
	pInputMouse = CManager::GetInputMouse();

	// パッドの取得
	CInputJoypad* pInputJoypad;
	pInputJoypad = CManager::GetInputJoypad();

	// 位置の取得
	D3DXVECTOR3 pos = GetPos();

	//// サウンドの取得
	//CSound* pSound = CManager::GetSound();

	m_nMovingCounter++;

	if (m_nMovingCounter >= 60 * 0 && m_nMovingCounter < 60 * 9)
	{
		m_pos.x -= 0.05f;
		m_pos.z -= 0.05f;
	}
	if (m_nMovingCounter >= 60 * 9 && m_nMovingCounter < 60 * 10)
	{
		m_pos.x += 0.1f;
		m_pos.z += 0.1f;

		//CEffect::Create(D3DXVECTOR3(1280.0f / 2.0f - 160.0f, 720.0f / 2.0f + 40.0f, 0.0f), D3DXCOLOR(0.0f, 0.3f, 0.6f, 0.1f), 0, 30, 25.0f, 25.0f);
	}
	if (m_nMovingCounter >= 60 * 10 && m_nMovingCounter < 60 * 12)
	{
		m_pos.x -= 40.0f;
		m_pos.z -= 40.0f;
	}
	if (m_nMovingCounter >= 60 * 25 && m_nMovingCounter < 60 * 26)
	{
		m_pos = D3DXVECTOR3(-100.0f + 40.0f * 10.0f, -300.0f, 0.0f + 40.0f * 10.0f);
	}
	if (m_nMovingCounter >= 60 * 26)
	{
		m_pos.x -= 40.0f;
		m_pos.z -= 40.0f;

		if (m_pos.x == -100.0f && m_pos.z == 0.0f)
		{
			m_nMovingCounter = 0;
		}
	}
}

//----------------------------------------
// 描画処理
//----------------------------------------
void CMf::Draw(void)
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
void CMf::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//----------------------------------------
// 位置の取得処理
//----------------------------------------
D3DXVECTOR3 CMf::GetPos(void)
{
	return m_pos;
}