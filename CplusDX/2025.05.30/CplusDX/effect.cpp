////==============================================================
////
//// [effect.cpp]
//// Author: Irisawa Kazan
////
////==============================================================
//#include"effect.h"
//#include"manager.h"
//#include"renderer.h"
//
//// 静的メンバ変数宣言
//LPDIRECT3DTEXTURE9 CEffect::m_pTexture = 0;
//
////----------------------------------------
//// エフェクトのコンストラクタ
////----------------------------------------
//CEffect::CEffect(int nPriority) : CObject2D(nPriority)
//{
//
//}
//
////----------------------------------------
//// エフェクトのデストラクタ
////----------------------------------------
//CEffect::~CEffect()
//{
//
//}
//
////----------------------------------------
//// テクスチャの生成(読み込み)
////----------------------------------------
//HRESULT CEffect::Load(void)
//{
//	// デバイスの取得
//	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
//
//	// テクスチャの初期化処理
//	D3DXCreateTextureFromFile(pDevice,
//		"data\\TEXTURE\\effect000.jpg",
//		&m_pTexture);
//
//	return S_OK;
//}
//
////----------------------------------------
//// テクスチャの破棄
////----------------------------------------
//void CEffect::Unload(void)
//{
//	// テクスチャの破棄
//	if (m_pTexture != NULL)
//	{
//		m_pTexture->Release();
//		m_pTexture = NULL;
//	}
//}
//
////----------------------------------------
//// エフェクトの生成処理
////----------------------------------------
//CEffect* CEffect::Create(D3DXVECTOR3 pos, float xsize, float ysize)
//{
//	CEffect* pEffect;
//
//	int nNumAll = CObject::GetNumAll();
//
//	if (nNumAll <= MAX_OBJ)
//	{
//		// オブジェクト2Dの生成
//		pEffect = new CEffect;
//
//		// 初期化処理
//		pEffect->Init(pos);
//
//		// サイズの設定
//		pEffect->SetSize(xsize, ysize);
//
//		// テクスチャの割り当て
//		pEffect->BindTexture(m_pTexture);
//
//		return pEffect;
//	}
//
//	return NULL;
//}
//
////----------------------------------------
//// エフェクトの初期化処理
////----------------------------------------
