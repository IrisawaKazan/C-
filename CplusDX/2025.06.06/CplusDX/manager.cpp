//==============================================================
//
// [manager.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"manager.h"
#include"object2D.h"
#include"player.h"
#include"background.h"
#include"renderer.h"
#include"input.h"
#include"bullet.h"
#include"explosion.h"
#include"enemy.h"
#include"sound.h"
#include"score.h"
#include"camera.h"
#include"light.h"
#include"object3D.h"
#include"timer.h"
#include"objectX.h"
#include"objectBillboard.h"

// 静的メンバ変数宣言
CRenderer* CManager::m_pRenderer = NULL;
CInputKeyboard* CManager::m_pInputKeyboard = NULL;
//CSound* CManager::m_pSound = NULL;
CCamera* CManager::m_pCamera = NULL;
CLight* CManager::m_pLight = NULL;

CPlayer* CManager::m_pPlayer = NULL;
CBackground* CManager::m_pBackground = NULL;
CEnemy* CManager::m_pEnemy = NULL;
CScore* CManager::m_pScore = NULL;
CTimer* CManager::m_pTimer = NULL;

//----------------------------------------
// コンストラクタ
//----------------------------------------
CManager::CManager()
{

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

	// サウンドの生成
	//m_pSound = new CSound;

	// サウンドの初期化処理
	//m_pSound->Init(hWnd);

	// カメラの生成
	m_pCamera = new CCamera;
	m_pCamera->Init();

	// ライトの生成
	m_pLight = new CLight;
	m_pLight->Init();

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

	// スコアのテクスチャの読み込み
	CScore::Load();

	// タイマーのテクスチャの読み込み
	CTimer::Load();

	// オブジェクトの生成(初期配置)
	//CBackground::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), SCREEN_WIDTH, SCREEN_HEIGHT); // 背景
	//CEnemy::Create(D3DXVECTOR3(SCREEN_WIDTH - 100.0f, SCREEN_HEIGHT / 3.0f, 0.0f), ENEMY_SIZEX, ENEMY_SIZEY, CEnemy::ETYPE_000); // 敵000
	//CEnemy::Create(D3DXVECTOR3(SCREEN_WIDTH - 100.0f, SCREEN_HEIGHT / 2.0f, 0.0f), ENEMY_SIZEX, ENEMY_SIZEY, CEnemy::ETYPE_001); // 敵001
	//CPlayer::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), 100.0f, 100.0f); // プレイヤー

	// オブジェクト3D(床ポリゴン)の生成(初期配置)
	CObject3D::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// オブジェクトX(BOX)の生成(初期配置)
	CObjectX::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// オブジェクトビルボード(木)の生成(初期配置)
	CObjectBillboard::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), 50.0f, 50.0f);

	// スコア
	CScore::Create(D3DXVECTOR3(50.0f, 50.0f, 0.0f), D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f), 30.0f, 90.0f);

	// タイマー
	CTimer::Create(D3DXVECTOR3(1100.0f, 50.0f, 0.0f), D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f), 30.0f, 90.0f);

	// BGM
	//m_pSound->PlaySound(CSound::SOUND_LABEL_MAINBGM);

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

	// スコアのテクスチャの破棄
	CScore::Unload();

	// タイマーのテクスチャの破棄
	CTimer::Unload();

	// キーボードの破棄
	if (m_pInputKeyboard != NULL)
	{
		// 終了処理
		m_pInputKeyboard->Uninit();

		delete m_pInputKeyboard;

		m_pInputKeyboard = NULL;
	}

	// レンダラーの破棄
	if (m_pRenderer != NULL)
	{
		// 終了処理
		m_pRenderer->Uninit();

		delete m_pRenderer;

		m_pRenderer = NULL;
	}

	//// サウンドの破棄
	//if (m_pSound != NULL)
	//{
	//	// 終了処理
	//	m_pSound->Uninit();

	//	delete m_pSound;

	//	m_pSound = NULL;
	//}

	// カメラの破棄
	if (m_pCamera != NULL)
	{
		// 終了処理
		m_pCamera->Uninit();

		delete m_pCamera;

		m_pCamera = NULL;
	}

	// ライトの破棄
	if (m_pLight != NULL)
	{
		// 終了処理
		m_pLight->Uninit();

		delete m_pLight;

		m_pLight = NULL;
	}
}

//----------------------------------------
// 更新処理
//----------------------------------------
void CManager::Update(void)
{
	// キーボードの更新処理
	m_pInputKeyboard->Update();

	// レンダラーの更新処理
	m_pRenderer->Update();

	// カメラの更新処理
	m_pCamera->Update();

	// ライトの更新
	m_pLight->Update();

	CInputKeyboard* pInputKeyboard;

	// キーボードの取得
	pInputKeyboard = CManager::GetInputKeyboard();

	/*float fPosX = (float)(rand() % SCREEN_WIDTH);
	float fPosY = (float)(rand() % SCREEN_HEIGHT);
	
	// Rで敵000の生成
	if (pInputKeyboard->GetTrigger(DIK_R) == true)
	{
		CEnemy::Create(D3DXVECTOR3(fPosX, fPosY, 0.0f), ENEMY_SIZEX, ENEMY_SIZEY, CEnemy::ETYPE_000); // 敵
	}
	// Tで敵001の生成
	if (pInputKeyboard->GetTrigger(DIK_T) == true)
	{
		CEnemy::Create(D3DXVECTOR3(fPosX, fPosY, 0.0f), ENEMY_SIZEX, ENEMY_SIZEY, CEnemy::ETYPE_001); // 敵
	}
	// Yで敵002の生成
	if (pInputKeyboard->GetTrigger(DIK_Y) == true)
	{
		CEnemy::Create(D3DXVECTOR3(fPosX, fPosY, 0.0f), ENEMY_SIZEX, ENEMY_SIZEY, CEnemy::ETYPE_002); // 敵
	}
	// Uで敵003の生成
	if (pInputKeyboard->GetTrigger(DIK_U) == true)
	{
		CEnemy::Create(D3DXVECTOR3(fPosX, fPosY, 0.0f), ENEMY_SIZEX, ENEMY_SIZEY, CEnemy::ETYPE_003); // 敵
	}

	// エンターキーで2体目以降のプレイヤー生成
	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
	{
		m_pPlayer = CPlayer::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), 100.0f, 100.0f); // プレイヤー
	}*/

	// スコア加算(+1)
	if (pInputKeyboard->GetTrigger(DIK_1) == true)
	{
		// スコア加算
		CScore::AddScore(1);
	}
	// スコア減算(-1)
	if (pInputKeyboard->GetTrigger(DIK_0) == true)
	{
		// スコア加算
		CScore::AddScore(-1);
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
// サウンドの取得処理
//----------------------------------------
//CSound* CManager::GetSound(void)
//{
//	return m_pSound;
//}

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