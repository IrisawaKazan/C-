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
#include"debrisX.h"

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
	m_posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_mtxWorld = D3DXMATRIX();

	m_fRotation = 0.0f;
	m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_vtxMin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_vtxMax = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	m_bUse = true;

	m_bRetention = false;

	m_nCounter = NULL;
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
	// 種類の設定処理
	CObject::SetType(TYPE_MODEL);

	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// Xファイルの読み込み
	D3DXLoadMeshFromX("data\\MODEL\\sphere.x",
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

		if (vtx.x >= m_vtxMax.x)
		{
			m_vtxMax.x = vtx.x;
		}

		if (vtx.y >= m_vtxMax.y)
		{
			m_vtxMax.y = vtx.y;
		}

		if (vtx.z >= m_vtxMax.z)
		{
			m_vtxMax.z = vtx.z;
		}

		// 頂点フォーマットのサイズ分ポインタを進める
		pVtxBuff += sizeFVF;
	}

	m_size = D3DXVECTOR3(m_vtxMax.x - m_vtxMin.x, m_vtxMax.y - m_vtxMin.y, m_vtxMax.z - m_vtxMin.z);

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
void CObjectX::Uninit(void)
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

	CObject::Release();
	//this->Release();
}

//----------------------------------------
// 更新処理
//----------------------------------------
void CObjectX::Update(void)
{
	if (m_bUse == true)
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

		// タイマー式のスコアカウンター
		m_nCounter++;

		// 1秒ごとにスコア加算(+1)
		if (m_nCounter >= 60)
		{
			// スコア加算
			CScore::AddScore(1);

			m_nCounter = 0;
		}

		// 前回の位置を保存
		m_posOld = m_pos;

		// プレイヤー移動
		// 上に進む + 動くとポイントがたまりやすいシステム
		if (pInputKeyboard->GetPress(DIK_SPACE) || pInputJoypad->GetJoypadPress(pInputJoypad->JOYKEY_A) || pInputMouse->Press(pInputMouse->MOUSE_LEFTBUTTON) == true)
		{// 奥
			m_pos.z += MAX_PMOVE * 3.5f;

			// 1/6秒ごとにスコア加算(+1)
			if (m_nCounter >= 10)
			{
				// スコア加算
				CScore::AddScore(1);

				m_nCounter = 0;
			}
		}

		// 上部のエリアにいるとスコアが伸びやすくなるシステム
		if (m_pos.z >= 32.5f && m_pos.z <= 132.5f)
		{
			// 1/10秒ごとにスコア加算(+1)
			if (m_nCounter >= 6)
			{
				// スコア加算
				CScore::AddScore(1);

				m_nCounter = 0;
			}
		}

		if (m_pos.z >= -132.5f)
		{// 下への移動制限
			// 常に後退する
			m_pos.z -= MAX_PMOVE;
		}

		// ローテーション
		m_fRotation += 1.0f;

		m_rot = D3DXVECTOR3(0.0f, m_fRotation / 200.0f/* 回る速度 */, 0.0f);

		// アイテム保持時の処理
		if (m_bRetention == true)
		{
			/* 見た目でわかる何か */

			// アイテム使用
			if (pInputKeyboard->GetTrigger(DIK_B) == true)
			{
				m_bRetention = false; // TODO: ↓の関数に呼び出したほうがいいかも

				/* 敵に当たったら倒せる処理(10秒間) or 画面内の敵一掃(敵がbUse = falseになったら一つにつき10～50, 100スコア) (関数呼び出し) */
			}
		}
	}
}

//----------------------------------------
// 描画処理
//----------------------------------------
void CObjectX::Draw(void)
{
	if (m_bUse == true)
	{
		//LPDIRECT3DSURFACE9 pRenderDef, pZBuffDef;
		//D3DVIEWPORT9 viewportDef;
		//D3DXMATRIX mtxViewDef, mtxProjectionDef;

		// デバイスの取得
		LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

		//// 現在のレンダリングターゲットを取得(保存)
		//pDevice->GetRenderTarget(0, &pRenderDef);

		//// 現在のZバッファを取得(保存)
		//pDevice->GetDepthStencilSurface(&pZBuffDef);

		//// 現在のビューポートを取得(保存)
		//pDevice->GetViewport(&viewportDef);

		//// 現在のビューマトリックスを取得(保存)
		//pDevice->GetTransform(D3DTS_VIEW, &mtxViewDef);

		//// 現在のプロジェクションマトリックスを取得(保存)
		//pDevice->GetTransform(D3DTS_PROJECTION, &mtxProjectionDef);

		//// レンダリングターゲットの変更
		//CManager::GetRenderer()->ChangeTarget(D3DXVECTOR3(0.0f, 375.0f, -1.0f), D3DXVECTOR3(0.0f, -120.0f, 0.0f), D3DXVECTOR3(0.0f, 1.0f, 0.0f));

		//// レンダリングターゲット用テクスチャのクリア
		//pDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER), D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);

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

		//// レンダリングターゲットを元に戻す
		//pDevice->SetRenderTarget(0, pRenderDef);

		//// Zバッファを元に戻す
		//pDevice->SetDepthStencilSurface(pZBuffDef);
	}
}

//----------------------------------------
// 位置の設定処理
//----------------------------------------
void CObjectX::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//----------------------------------------
// 前回の位置の設定処理
//----------------------------------------
void CObjectX::SetPositionOld(D3DXVECTOR3 posOld)
{
	m_posOld = posOld;
}

//----------------------------------------
// 向きの設定処理
//----------------------------------------
void CObjectX::SetRotation(D3DXVECTOR3 rot)
{
	m_rot = rot;
}

//----------------------------------------
// サイズの設定処理
//----------------------------------------
void CObjectX::SetSize(D3DXVECTOR3 size)
{
	m_size = size;
}

//----------------------------------------
// 使用有無の設定処理
//----------------------------------------
void CObjectX::SetEnable(bool enable)
{
	m_bUse = enable;
}

//----------------------------------------
// アイテム保持有無の設定処理
//----------------------------------------
void CObjectX::SetSigns(bool signs)
{
	m_bRetention = signs;
}

//----------------------------------------
// 位置の取得処理
//----------------------------------------
D3DXVECTOR3 CObjectX::GetPos(void)
{
	return m_pos;
}

//----------------------------------------
// 前回の位置の取得処理
//----------------------------------------
D3DXVECTOR3 CObjectX::GetPosOld(void)
{
	return m_posOld;
}

//----------------------------------------
// 向きの取得処理
//----------------------------------------
D3DXVECTOR3 CObjectX::GetRot(void)
{
	return m_rot;
}

//----------------------------------------
// サイズの取得処理
//----------------------------------------
D3DXVECTOR3 CObjectX::GetSize(void)
{
	return m_size;
}

//----------------------------------------
// 使用有無の取得処理
//----------------------------------------
bool CObjectX::GetEnable(void)
{
	return m_bUse;
}

//----------------------------------------
// アイテム保持有無の取得処理
//----------------------------------------
bool CObjectX::GetSigns(void)
{
	return m_bRetention;
}