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

// 静的メンバ変数宣言
CRenderer* CManager::m_pRenderer = {};
CInputKeyboard* CManager::m_pInputKeyboard = {};
CPlayer* CManager::m_pPlayer = {};
CBackground* CManager::m_pBackground = {};
CEnemy* CManager::m_pEnemy = {};

//----------------------------------------
// コンストラクタ
//----------------------------------------
CManager::CManager()
{
	m_pRenderer = NULL;
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
HRESULT CManager::Init(HINSTANCE nInstance, HWND hWnd, BOOL bWindow)
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

	// オブジェクトの生成
	m_pBackground = CBackground::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), SCREEN_WIDTH, SCREEN_HEIGHT); // 背景

	m_pEnemy = CEnemy::Create(D3DXVECTOR3(SCREEN_WIDTH - 100.0f, SCREEN_HEIGHT / 3.0f, 0.0f), 150.0f, 100.0f); // 敵
	m_pEnemy = CEnemy::Create(D3DXVECTOR3(SCREEN_WIDTH - 100.0f, SCREEN_HEIGHT / 2.0f, 0.0f), 150.0f, 100.0f); // 敵
	m_pPlayer = CPlayer::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), 100.0f, 100.0f); // プレイヤー(ランニングマン正面)

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

	// エネミーのテクスチャの読み込み
	CPlayer::Unload();

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