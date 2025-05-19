//==============================================================
//
// [manager.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"manager.h"
#include"object2D.h"

// 静的メンバ変数宣言
CRenderer* CManager::m_pRenderer = {};
CInputKeyboard* CManager::m_pInputKeyboard = {};

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

	// オブジェクトの生成
	CObject2D::Create()->SetPosition(D3DXVECTOR3(100.0f, 100.0f, 0.0f));
	//CObject2D::Create()->SetPosition(D3DXVECTOR3(500.0f, 500.0f, 0.0f));
	//CObject2D::Create()->SetPosition(D3DXVECTOR3(800.0f, 250.0f, 0.0f));
	CPlayer::Create()->SetPosition(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f)); // ランニングマン
}
//----------------------------------------
// 終了処理
//----------------------------------------
void CManager::Uninit(void)
{
	// 全てのオブジェクトの破棄
	CObject::ReleaseAll;

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