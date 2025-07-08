//==============================================================
//
// [manager.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"manager.h"

// 静的メンバ変数宣言
CRenderer* CManager::m_pRenderer = nullptr;
CInputKeyboard* CManager::m_pInputKeyboard = nullptr;
CInputMouse* CManager::m_pInputMouse = nullptr;
CInputJoypad* CManager::m_pInputJoypad = nullptr;
CSound* CManager::m_pSound = nullptr;
CCamera* CManager::m_pCamera = nullptr;
CLight* CManager::m_pLight = nullptr;
CDebugProc* CManager::m_pDebugProc = nullptr;

CPlayer* CManager::m_pPlayer = nullptr;
CBackground* CManager::m_pBackground = nullptr;
CEnemy* CManager::m_pEnemy = nullptr;
CScore* CManager::m_pScore = nullptr;
CTimer* CManager::m_pTimer = nullptr;
CEffect* CManager::m_pEffect = nullptr;
CPause* CManager::m_pPause = nullptr;

CObjectX* CManager::m_pObjectX = nullptr;

//----------------------------------------
// コンストラクタ
//----------------------------------------
CManager::CManager()
{
	m_bPause = NULL;
	m_nDebrisSpawn = NULL;

	for (int nCnt = 0; nCnt < MAX_FRAMECOUNTER; nCnt++)
	{
		m_nFrameCounter[nCnt] = NULL;
	}
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CManager::~CManager()
{

}

//----------------------------------------
// 初期化処理
//----------------------------------------
HRESULT CManager::Init(HINSTANCE nInstance, HWND hWnd)
{
	// レンダラーの生成
	m_pRenderer = new CRenderer;

	// レンダラーの初期化処理
	if (FAILED(m_pRenderer->Init(hWnd, TRUE)))
	{// 初期化処理が失敗した場合
		return -1;
	}

	// キーボードの生成
	m_pInputKeyboard = new CInputKeyboard;

	// キーボードの初期化処理
	if (FAILED(m_pInputKeyboard->Init(nInstance, hWnd)))
	{// 初期化処理が失敗した場合
		return -1;
	}

	// マウスの生成
	m_pInputMouse = new CInputMouse;

	// マウスの初期化処理
	if (FAILED(m_pInputMouse->Init(nInstance, hWnd)))
	{// 初期化処理が失敗した場合
		return -1;
	}

	// パッドの生成
	m_pInputJoypad = new CInputJoypad;

	// パッドの初期化処理
	if (FAILED(m_pInputJoypad->Init(nInstance, hWnd)))
	{// 初期化処理が失敗した場合
		return -1;
	}

	// サウンドの生成
	m_pSound = new CSound;

	// サウンドの初期化処理
	m_pSound->Init(hWnd);

	// カメラの生成
	m_pCamera = new CCamera;
	m_pCamera->Init();

	// ライトの生成
	m_pLight = new CLight;
	m_pLight->Init();

	// デバッグの生成
	m_pDebugProc = new CDebugProc;
	m_pDebugProc->Init();

	// バックグラウンドのテクスチャの読み込み
	CBackground::Load();

	// バレットのテクスチャの読み込み
	CBullet::Load();

	// エクスプロージョンのテクスチャの読み込み
	CExplosion::Load();

	// プレイヤーのテクスチャの読み込み
	CPlayer::Load();

	// エネミーのテクスチャの読み込み
	CEnemy::Load();

	// エフェクトのテクスチャの読み込み
	CEffect::Load();

	// スコアのテクスチャの読み込み
	CScore::Load();

	// タイマーのテクスチャの読み込み
	CTimer::Load();
	
	// ポーズのテクスチャの読み込み
	CPause::Load();

	// オブジェクトの生成(初期配置)
	//CBackground::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), SCREEN_WIDTH, SCREEN_HEIGHT); // 背景
	//CEnemy::Create(D3DXVECTOR3(SCREEN_WIDTH - 100.0f, SCREEN_HEIGHT / 3.0f, 0.0f), ENEMY_SIZEX, ENEMY_SIZEY, CEnemy::ETYPE_000); // 敵000
	//CEnemy::Create(D3DXVECTOR3(SCREEN_WIDTH - 100.0f, SCREEN_HEIGHT / 2.0f, 0.0f), ENEMY_SIZEX, ENEMY_SIZEY, CEnemy::ETYPE_001); // 敵001
	//CPlayer::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), 100.0f, 100.0f); // プレイヤー

	// オブジェクト3D(床ポリゴン)の生成(初期配置)
	//CObject3D::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// bgXの生成
	CBackgroundX::Create(D3DXVECTOR3(0.0f, -325.0f, 0.0f));

	// オブジェクトXの生成(初期配置)
	m_pObjectX = CObjectX::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// オブジェクトビルボード(木)の生成(初期配置)
	//CObjectBillboard::Create(D3DXVECTOR3(75.0f, 50.0f, 0.0f)/*, 50.0f, 50.0f*/);

	// 宇宙ゴミの生成(初期配置)
	CStardustX::Create(D3DXVECTOR3(-150.0f, 0.0f, 100.0f), CStardustX::STARDUST_000_A);

	// デッドゾーンの生成(初期配置)
	CDeadzoneX::Create(D3DXVECTOR3(0.0f, 0.0f, 147.5f));

	// スコア
	CScore::Create(D3DXVECTOR3(1100.0f, 50.0f, 0.0f), D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f), 30.0f, 90.0f);

	// タイマー
	//CTimer::Create(D3DXVECTOR3(1100.0f, 50.0f, 0.0f), D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f), 30.0f, 90.0f);

	// BGM
	m_pSound->PlaySoundA(CSound::SOUND_LABEL_MAINBGM);

	m_bPause = false; // ポーズ解除

	return S_OK;
}

//----------------------------------------
// 終了処理
//----------------------------------------
void CManager::Uninit(void)
{
	// 全てのオブジェクトの破棄
	CObject::ReleaseAll();

	// バックグラウンドのテクスチャの破棄
	CBackground::Unload();

	// バレットのテクスチャの破棄
	CBullet::Unload();

	// エクスプロージョンのテクスチャの破棄
	CExplosion::Unload();

	// プレイヤーのテクスチャの破棄
	CPlayer::Unload();

	// エネミーのテクスチャの破棄
	CEnemy::Unload();

	// エフェクトのテクスチャの破棄
	CEffect::Unload();

	// スコアのテクスチャの破棄
	CScore::Unload();

	// タイマーのテクスチャの破棄
	CTimer::Unload();

	// ポーズのテクスチャの破棄
	CPause::Unload();

	// キーボードの破棄
	if (m_pInputKeyboard != nullptr)
	{
		// 終了処理
		m_pInputKeyboard->Uninit();

		delete m_pInputKeyboard;

		m_pInputKeyboard = nullptr;
	}

	// マウスの破棄
	if (m_pInputMouse != nullptr)
	{
		// 終了処理
		m_pInputMouse->Uninit();

		delete m_pInputMouse;

		m_pInputMouse = nullptr;
	}

	// パッドの破棄
	if (m_pInputJoypad != nullptr)
	{
		// 終了処理
		m_pInputJoypad->Uninit();

		delete m_pInputJoypad;

		m_pInputJoypad = nullptr;
	}

	// レンダラーの破棄
	if (m_pRenderer != nullptr)
	{
		// 終了処理
		m_pRenderer->Uninit();

		delete m_pRenderer;

		m_pRenderer = nullptr;
	}

	// サウンドの破棄
	if (m_pSound != nullptr)
	{
		// 終了処理
		m_pSound->Uninit();

		delete m_pSound;

		m_pSound = nullptr;
	}

	// カメラの破棄
	if (m_pCamera != nullptr)
	{
		// 終了処理
		m_pCamera->Uninit();

		delete m_pCamera;

		m_pCamera = nullptr;
	}

	// ライトの破棄
	if (m_pLight != nullptr)
	{
		// 終了処理
		m_pLight->Uninit();

		delete m_pLight;

		m_pLight = nullptr;
	}

	// デバッグの破棄
	if (m_pDebugProc != nullptr)
	{
		// 終了処理
		m_pDebugProc->Uninit();

		delete m_pDebugProc;

		m_pDebugProc = nullptr;
	}

	// オブジェクトXの破棄
	m_pObjectX = nullptr;
}

//----------------------------------------
// 更新処理
//----------------------------------------
void CManager::Update(void)
{
	CInputKeyboard* pInputKeyboard;

	// キーボードの取得
	pInputKeyboard = CManager::GetInputKeyboard();

	// キーボードの更新処理
	m_pInputKeyboard->Update();

	// マウスの更新処理
	m_pInputMouse->Update();

	// パッドの更新処理
	m_pInputJoypad->Update();

	if (pInputKeyboard->GetTrigger(DIK_TAB) || pInputKeyboard->GetTrigger(DIK_P) == true)
	{// ポーズキーが押された
		m_bPause = m_bPause ? false : true;
	}

	if (m_bPause == true)
	{// ポーズ中
		//CPause::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), SCREEN_WIDTH, SCREEN_HEIGHT);

		//m_pPause->Update();
	}

	if (m_bPause == false)
	{// ポーズ中でなければ
		// レンダラーの更新処理
		m_pRenderer->Update();

		// カメラの更新処理
		m_pCamera->Update();

		// ライトの更新
		m_pLight->Update();

		// 敵のランダム生成
		m_nDebrisSpawn++;

		float fPosZ = (float)(rand() % 130/* 出てくる範囲 */);

		// 現在の時刻を種として設定
		srand(time(NULL));

		// 多段で出ないように制限するカウンター
		for (int nCnt = 0; nCnt < MAX_FRAMECOUNTER; nCnt++)
		{
			m_nFrameCounter[nCnt]++;
		}

		// トゲトゲ→
		if (m_nDebrisSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[0] >= NUM_FRAME_CNT)
		{
			CDebrisX::Create(D3DXVECTOR3(-DEBRIS_000_POS_X, 0.0f, fPosZ), CDebrisX::DEBRIS_000_A);

			m_nDebrisSpawn = 0;
			m_nFrameCounter[0] = 0;
		}
		if (m_nDebrisSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[1] >= NUM_FRAME_CNT)
		{
			CDebrisX::Create(D3DXVECTOR3(-DEBRIS_000_POS_X, 0.0f, -fPosZ), CDebrisX::DEBRIS_000_A);

			m_nDebrisSpawn = 0;
			m_nFrameCounter[1] = 0;
		}

		// ←トゲトゲ
		if (m_nDebrisSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[2] >= NUM_FRAME_CNT)
		{
			CDebrisX::Create(D3DXVECTOR3(DEBRIS_000_POS_X, 0.0f, fPosZ), CDebrisX::DEBRIS_000_B);

			m_nDebrisSpawn = 0;
			m_nFrameCounter[2] = 0;
		}
		if (m_nDebrisSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[3] >= NUM_FRAME_CNT)
		{
			CDebrisX::Create(D3DXVECTOR3(DEBRIS_000_POS_X, 0.0f, -fPosZ), CDebrisX::DEBRIS_000_B);

			m_nDebrisSpawn = 0;
			m_nFrameCounter[3] = 0;
		}

		// スクラップ→
		if (m_nDebrisSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[4] >= NUM_FRAME_CNT)
		{
			CScrap::Create(D3DXVECTOR3(-SCRAP_000_POS_X, 0.0f, fPosZ), CScrap::SCRAP_000_A);

			m_nDebrisSpawn = 0;
			m_nFrameCounter[4] = 0;
		}
		if (m_nDebrisSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[5] >= NUM_FRAME_CNT)
		{
			CScrap::Create(D3DXVECTOR3(-SCRAP_000_POS_X, 0.0f, -fPosZ), CScrap::SCRAP_000_A);

			m_nDebrisSpawn = 0;
			m_nFrameCounter[5] = 0;
		}

		// ←スクラップ
		if (m_nDebrisSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[6] >= NUM_FRAME_CNT)
		{
			CScrap::Create(D3DXVECTOR3(SCRAP_000_POS_X, 0.0f, fPosZ), CScrap::SCRAP_000_B);

			m_nDebrisSpawn = 0;
			m_nFrameCounter[6] = 0;
		}
		if (m_nDebrisSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[7] >= NUM_FRAME_CNT)
		{
			CScrap::Create(D3DXVECTOR3(SCRAP_000_POS_X, 0.0f, -fPosZ), CScrap::SCRAP_000_B);

			m_nDebrisSpawn = 0;
			m_nFrameCounter[7] = 0;
		}

		// 確認用
		// スコア加算(+1)
		if (pInputKeyboard->GetTrigger(DIK_1) == true)
		{
			// スコア加算
			CScore::AddScore(1);

			// SE
			m_pSound->PlaySoundA(CSound::SOUND_LABEL_SAMPLESE);
		}
		// スコア減算(-1)
		if (pInputKeyboard->GetTrigger(DIK_0) == true)
		{
			// スコア加算
			CScore::AddScore(-1);

			// SE
			m_pSound->PlaySoundA(CSound::SOUND_LABEL_SAMPLESE);
		}
	}
}

//----------------------------------------
// 描画処理
//----------------------------------------
void CManager::Draw(void)
{
	m_pRenderer->Draw();
}

//----------------------------------------
// レンダラーの取得処理
//----------------------------------------
CRenderer* CManager::GetRenderer(void)
{
	return m_pRenderer;
}

//----------------------------------------
// キーボードの取得処理
//----------------------------------------
CInputKeyboard* CManager::GetInputKeyboard(void)
{
	return m_pInputKeyboard;
}

//----------------------------------------
// マウスの取得処理
//----------------------------------------
CInputMouse* CManager::GetInputMouse(void)
{
	return m_pInputMouse;
}

//----------------------------------------
// パッドの取得処理
//----------------------------------------
CInputJoypad* CManager::GetInputJoypad(void)
{
	return m_pInputJoypad;
}

//----------------------------------------
// カメラの取得処理
//----------------------------------------
CCamera* CManager::GetCamera(void)
{
	return m_pCamera;
}

//----------------------------------------
// ライトの取得処理
//----------------------------------------
CLight* CManager::GetLight(void)
{
	return m_pLight;
}

//----------------------------------------
// デバッグの取得処理
//----------------------------------------
CDebugProc* CManager::GetDebugProc(void)
{
	return m_pDebugProc;
}

//----------------------------------------
// サウンドの取得処理
//----------------------------------------
CSound* CManager::GetSound(void)
{
	return m_pSound;
}

//----------------------------------------
// プレイヤーの取得処理
//----------------------------------------
CPlayer* CManager::GetPlayer(void)
{
	return m_pPlayer;
}

//----------------------------------------
// バックグラウンドの取得処理
//----------------------------------------
CBackground* CManager::GetBackground(void)
{
	return m_pBackground;
}

//----------------------------------------
// エネミーの取得処理
//----------------------------------------
CEnemy* CManager::GetEnemy(void)
{
	return m_pEnemy;
}

//----------------------------------------
// スコアの取得処理
//----------------------------------------
CScore* CManager::GetScore(void)
{
	return m_pScore;
}

//----------------------------------------
// タイマーの取得処理
//----------------------------------------
CTimer* CManager::GetTimer(void)
{
	return m_pTimer;
}

//----------------------------------------
// エフェクトの取得処理
//----------------------------------------
CEffect* CManager::GetEffect(void)
{
	return m_pEffect;
}

//----------------------------------------
// ポーズの取得処理
//----------------------------------------
CPause* CManager::GetPause(void)
{
	return m_pPause;
}

//----------------------------------------
// オブジェクトXの取得処理
//----------------------------------------
CObjectX* CManager::GetObjectX(void)
{
	return m_pObjectX;
}