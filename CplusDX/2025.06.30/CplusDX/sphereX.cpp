////==============================================================
////
//// [sphereX.cpp]
//// Author: Irisawa Kazan
////
////==============================================================
//#include"sphereX.h"
//#include"manager.h"
//
//// 静的メンバ変数宣言
//LPDIRECT3DTEXTURE9 CSphereX::m_pTexture = nullptr;
//LPD3DXMESH CSphereX::m_pMesh = nullptr;
//LPD3DXBUFFER CSphereX::m_pBuffMat = nullptr;
//DWORD CSphereX::m_dwNumMat = 0.0f;
//
////----------------------------------------
//// コンストラクタ
////----------------------------------------
//CSphereX::CSphereX(int nPriority)
//{
//	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//	m_fRotation = 0.0f;
//}
//
////----------------------------------------
//// デストラクタ
////----------------------------------------
//CSphereX::~CSphereX()
//{
//
//}
//
////----------------------------------------
//// Xファイルの生成(読み込み)
////----------------------------------------
//HRESULT CSphereX::Load(void)
//{
//	// デバイスの取得
//	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
//
//	// Xファイルの読み込み
//	D3DXLoadMeshFromX("data\\MODEL\\sphere.x",
//		D3DXMESH_SYSTEMMEM,
//		pDevice,
//		NULL,
//		&m_pBuffMat,
//		NULL,
//		&m_dwNumMat,
//		&m_pMesh);
//
//	D3DXMATERIAL* pMat = nullptr; // マテリアルへのポインタ
//
//	// マテリアルのデータへのポインタを取得
//	pMat = (D3DXMATERIAL*)m_pBuffMat->GetBufferPointer();
//
//	for (int nCntMat = 0; nCntMat < (int)m_dwNumMat; nCntMat++)
//	{
//		if (pMat[nCntMat].pTextureFilename != nullptr)
//		{
//			// このファイル名を使用してテクスチャを読み込む
//
//
//			// テクスチャの読み込み
//
//
//			D3DXCreateTextureFromFile(pDevice, pMat[nCntMat].pTextureFilename, &m_pTexture);
//		}
//	}
//
//	return S_OK;
//}
//
////----------------------------------------
//// Xファイルの破棄
////----------------------------------------
//void CSphereX::Unload(void)
//{
//	// テクスチャの破棄
//	if (m_pTexture != nullptr)
//	{
//		m_pTexture->Release();
//		m_pTexture = nullptr;
//	}
//
//	// メッシュ(頂点座標)へのポインタの破棄
//	if (m_pMesh != nullptr)
//	{
//		m_pMesh->Release();
//		m_pMesh = nullptr;
//	}
//
//	// マテリアルへのポインタの破棄
//	if (m_pBuffMat != nullptr)
//	{
//		m_pBuffMat->Release();
//		m_pBuffMat = nullptr;
//	}
//
//	// マテリアルの数破棄
//	if (m_dwNumMat != NULL)
//	{
//		m_dwNumMat = NULL;
//	}
//}
//
////----------------------------------------
//// 生成処理
////----------------------------------------
//CSphereX* CSphereX::Create(D3DXVECTOR3 pos)
//{
//	CSphereX* pSphere;
//
//	int nNumAll = CObject::GetNumAll();
//
//	if (nNumAll <= MAX_OBJ)
//	{
//		// オブジェクト2Dの生成
//		pSphere = new CSphereX;
//
//		// 初期化処理
//		pSphere->Init(pos);
//
//		pSphere->SetPosition(pos);
//
//		return pSphere;
//	}
//
//	return nullptr;
//}
//
////----------------------------------------
//// 初期化処理
////----------------------------------------
//HRESULT CSphereX::Init(D3DXVECTOR3 pos)
//{
//	CObjectX::Init(pos);
//
//	// 種類の設定処理
//	CObject::SetType(TYPE_SPHEREX);
//
//	return S_OK;
//}
//
////----------------------------------------
//// 更新処理
////----------------------------------------
//void CSphereX::Uninit(void)
//{
//	CObjectX::Uninit();
//}
//
////----------------------------------------
//// 更新処理
////----------------------------------------
//void CSphereX::Update(void)
//{
//	CInputKeyboard* pInputKeyboard;
//
//	// キーボードの取得
//	pInputKeyboard = CManager::GetInputKeyboard();
//
//	// 位置の取得
//	D3DXVECTOR3 pos = GetPos();
//
//	// 向きの取得
//	D3DXVECTOR3 rot = GetRot();
//
//	// 上に進む
//	if (pInputKeyboard->GetPress(DIK_SPACE) == true)
//	{// 奥
//		pos.z += MAX_PMOVE * 3.5f;
//	}
//
//	if (pos.z >= -132.5f)
//	{// 下への移動制限
//		// 常に後退する
//		pos.z -= MAX_PMOVE;
//	}
//
//	// ローテーション
//	m_fRotation += 1.0f;
//
//	rot = D3DXVECTOR3(0.0f, m_fRotation / 200.0f/* 回る速度 */, 0.0f);
//
//	CSphereX::SetPosition(pos);
//
//	CSphereX::SetRotation(rot);
//
//	CObjectX::Update();
//}
//
////----------------------------------------
//// 描画処理
////----------------------------------------
//void CSphereX::Draw(void)
//{
//	CObjectX::Draw();
//}
//
////----------------------------------------
//// 位置の設定処理
////----------------------------------------
//void CSphereX::SetPosition(D3DXVECTOR3 pos)
//{
//	CObjectX::SetPosition(pos);
//}
//
////----------------------------------------
//// 位置の設定処理
////----------------------------------------
//void CSphereX::SetRotation(D3DXVECTOR3 rot)
//{
//	CObjectX::SetRotation(rot);
//}