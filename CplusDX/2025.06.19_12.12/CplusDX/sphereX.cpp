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
//LPDIRECT3DTEXTURE9 CSpereX::m_pTexture = nullptr;
//LPD3DXMESH CSpereX::m_pMesh = nullptr;
//LPD3DXBUFFER CSpereX::m_pBuffMat = nullptr;
//
////----------------------------------------
//// コンストラクタ
////----------------------------------------
//CSpereX::CSpereX(int nPriority)
//{
//	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//}
//
////----------------------------------------
//// デストラクタ
////----------------------------------------
//CSpereX::~CSpereX()
//{
//
//}
//
////----------------------------------------
//// Xファイルの生成(読み込み)
////----------------------------------------
//HRESULT CSpereX::Load(void)
//{
//	// デバイスの取得
//	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
//
//	// Xファイルの読み込み
//	D3DXLoadMeshFromX("data\\MODEL\\BOX.x",
//		D3DXMESH_SYSTEMMEM,
//		pDevice,
//		NULL,
//		&m_pBuffMat,
//		NULL,
//		&m_dwNumMat,
//		&m_pMesh);
//
//	return S_OK;
//}
//
////----------------------------------------
//// Xファイルの破棄
////----------------------------------------
//void CSpereX::Unload(void)
//{
//
//}
//
////----------------------------------------
//// 生成処理
////----------------------------------------
//CSpereX* CSpereX::Create(D3DXVECTOR3 pos, float xsize, float ysize)
//{
//	return nullptr;
//}
//
////----------------------------------------
//// 初期化処理
////----------------------------------------
//HRESULT CSpereX::Init(D3DXVECTOR3 pos)
//{
//	return S_OK;
//}
//
////----------------------------------------
//// 更新処理
////----------------------------------------
//void CSpereX::Uninit(void)
//{
//	CObjectX::Uninit();
//}
//
////----------------------------------------
//// 更新処理
////----------------------------------------
//void CSpereX::Update(void)
//{
//
//}
//
////----------------------------------------
//// 描画処理
////----------------------------------------
//void CSpereX::Draw(void)
//{
//	CObjectX::Draw();
//}
//
////----------------------------------------
//// 位置の設定処理
////----------------------------------------
//void CSpereX::SetPosition(D3DXVECTOR3 pos)
//{
//	CObjectX::SetPosition(pos);
//}