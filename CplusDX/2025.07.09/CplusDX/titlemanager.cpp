////==============================================================
////
//// [titlemanager.cpp]
//// Author: Irisawa Kazan
////
////==============================================================
//#include"titlemanager.h"
//#include"renderer.h"
//
//// 静的メンバ変数宣言
//CRenderer* CTitle::m_pRenderer = nullptr;
//CInputKeyboard* CTitle::m_pInputKeyboard = nullptr;
//CSound* CTitle::m_pSound = nullptr;
//CCamera* CTitle::m_pCamera = nullptr;
//CLight* CTitle::m_pLight = nullptr;
//CDebugProc* CTitle::m_pDebugProc = nullptr;
//
//CPlayer* CTitle::m_pPlayer = nullptr;
//CBackground* CTitle::m_pBackground = nullptr;
//CEnemy* CTitle::m_pEnemy = nullptr;
//CScore* CTitle::m_pScore = nullptr;
//CEffect* CTitle::m_pEffect = nullptr;
//
////----------------------------------------
//// コンストラクタ
////----------------------------------------
//CTitle::CTitle()
//{
//
//}
//
////----------------------------------------
//// デストラクタ
////----------------------------------------
//CTitle::~CTitle()
//{
//
//}
//
////----------------------------------------
//// 初期化処理
////----------------------------------------
//HRESULT CTitle::Init(HINSTANCE nInstance, HWND hWnd)
//{
//	// レンダラーの生成
//	m_pRenderer = new CRenderer;
//
//	// レンダラーの初期化処理
//	if (FAILED(m_pRenderer->Init(hWnd, TRUE)))
//	{// 初期化処理が失敗した場合
//		return -1;
//	}
//
//	// キーボードの生成
//	m_pInputKeyboard = new CInputKeyboard;
//
//	// キーボードの初期化処理
//	if (FAILED(m_pInputKeyboard->Init(nInstance, hWnd)))
//	{// 初期化処理が失敗した場合
//		return -1;
//	}
//
//	// サウンドの生成
//	m_pSound = new CSound;
//
//	// サウンドの初期化処理
//	m_pSound->Init(hWnd);
//
//	// カメラの生成
//	m_pCamera = new CCamera;
//	m_pCamera->Init();
//
//	// ライトの生成
//	m_pLight = new CLight;
//	m_pLight->Init();
//
//	// デバッグの生成
//	m_pDebugProc = new CDebugProc;
//	m_pDebugProc->Init();
//
//	// バックグラウンドのテクスチャの読み込み
//	CBackground::Load();
//
//	// バレットのテクスチャの読み込み
//	CBullet::Load();
//
//	// エクスプロージョンのテクスチャの読み込み
//	CExplosion::Load();
//
//	// プレイヤーのテクスチャの読み込み
//	CPlayer::Load();
//
//	// エネミーのテクスチャの読み込み
//	CEnemy::Load();
//
//	// エフェクトのテクスチャの読み込み
//	CEffect::Load();
//
//	// スコアのテクスチャの読み込み
//	CScore::Load();
//
//	// オブジェクトX(BOX)の生成(初期配置)
//	CObjectX::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
//
//	// スコア
//	CScore::Create(D3DXVECTOR3(50.0f, 50.0f, 0.0f), D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f), 30.0f, 90.0f);
//
//	// BGM
//	m_pSound->PlaySoundA(CSound::SOUND_LABEL_MAINBGM);
//
//	return S_OK;
//}
//
////----------------------------------------
//// 終了処理
////----------------------------------------
//void CTitle::Uninit(void)
//{
//	// 全てのオブジェクトの破棄
//	CObject::ReleaseAll();
//
//	// バックグラウンドのテクスチャの破棄
//	CBackground::Unload();
//
//	// バレットのテクスチャの破棄
//	CBullet::Unload();
//
//	// エクスプロージョンのテクスチャの破棄
//	CExplosion::Unload();
//
//	// プレイヤーのテクスチャの破棄
//	CPlayer::Unload();
//
//	// エネミーのテクスチャの破棄
//	CEnemy::Unload();
//
//	// エフェクトのテクスチャの破棄
//	CEffect::Unload();
//
//	// スコアのテクスチャの破棄
//	CScore::Unload();
//
//	// キーボードの破棄
//	if (m_pInputKeyboard != nullptr)
//	{
//		// 終了処理
//		m_pInputKeyboard->Uninit();
//
//		delete m_pInputKeyboard;
//
//		m_pInputKeyboard = nullptr;
//	}
//
//	// レンダラーの破棄
//	if (m_pRenderer != nullptr)
//	{
//		// 終了処理
//		m_pRenderer->Uninit();
//
//		delete m_pRenderer;
//
//		m_pRenderer = nullptr;
//	}
//
//	// サウンドの破棄
//	if (m_pSound != nullptr)
//	{
//		// 終了処理
//		m_pSound->Uninit();
//
//		delete m_pSound;
//
//		m_pSound = nullptr;
//	}
//
//	// カメラの破棄
//	if (m_pCamera != nullptr)
//	{
//		// 終了処理
//		m_pCamera->Uninit();
//
//		delete m_pCamera;
//
//		m_pCamera = nullptr;
//	}
//
//	// ライトの破棄
//	if (m_pLight != nullptr)
//	{
//		// 終了処理
//		m_pLight->Uninit();
//
//		delete m_pLight;
//
//		m_pLight = nullptr;
//	}
//
//	// デバッグの破棄
//	if (m_pDebugProc != nullptr)
//	{
//		// 終了処理
//		m_pDebugProc->Uninit();
//
//		delete m_pDebugProc;
//
//		m_pDebugProc = nullptr;
//	}
//}
//
////----------------------------------------
//// 更新処理
////----------------------------------------
//void CTitle::Update(void)
//{
//	CInputKeyboard* pInputKeyboard;
//
//	// キーボードの取得
//	pInputKeyboard = CTitle::GetInputKeyboard();
//
//	// キーボードの更新処理
//	m_pInputKeyboard->Update();
//
//	CRenderer* pRenderer = nullptr;
//
//	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
//	{// 決定キー(ENTERキー)が押された
//		// モード設定(ゲーム画面に移行)
//		pRenderer->SetMode(pRenderer->MODE_GAME);
//	}
//}
//
////----------------------------------------
//// 描画処理
////----------------------------------------
//void CTitle::Draw(void)
//{
//	m_pRenderer->Draw();
//}
//
////----------------------------------------
//// レンダラーの取得処理
////----------------------------------------
//CRenderer* CTitle::GetRenderer(void)
//{
//	return m_pRenderer;
//}
//
////----------------------------------------
//// キーボードの取得処理
////----------------------------------------
//CInputKeyboard* CTitle::GetInputKeyboard(void)
//{
//	return m_pInputKeyboard;
//}
//
////----------------------------------------
//// カメラの取得処理
////----------------------------------------
//CCamera* CTitle::GetCamera(void)
//{
//	return m_pCamera;
//}
//
////----------------------------------------
//// ライトの取得処理
////----------------------------------------
//CLight* CTitle::GetLight(void)
//{
//	return m_pLight;
//}
//
////----------------------------------------
//// デバッグの取得処理
////----------------------------------------
//CDebugProc* CTitle::GetDebugProc(void)
//{
//	return m_pDebugProc;
//}
//
////----------------------------------------
//// サウンドの取得処理
////----------------------------------------
//CSound* CTitle::GetSound(void)
//{
//	return m_pSound;
//}
//
////----------------------------------------
//// プレイヤーの取得処理
////----------------------------------------
//CPlayer* CTitle::GetPlayer(void)
//{
//	return m_pPlayer;
//}
//
////----------------------------------------
//// バックグラウンドの取得処理
////----------------------------------------
//CBackground* CTitle::GetBackground(void)
//{
//	return m_pBackground;
//}
//
////----------------------------------------
//// エネミーの取得処理
////----------------------------------------
//CEnemy* CTitle::GetEnemy(void)
//{
//	return m_pEnemy;
//}
//
////----------------------------------------
//// スコアの取得処理
////----------------------------------------
//CScore* CTitle::GetScore(void)
//{
//	return m_pScore;
//}
//
////----------------------------------------
//// エフェクトの取得処理
////----------------------------------------
//CEffect* CTitle::GetEffect(void)
//{
//	return m_pEffect;
//}