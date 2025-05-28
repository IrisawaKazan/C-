//==============================================================
//
// [input.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"input.h"

// 静的メンバ変数宣言
LPDIRECTINPUT8 CInput::m_pInput = NULL;

//----------------------------------------
// コンストラクタ
//----------------------------------------
CInput::CInput()
{
	m_pInput = NULL;
	m_pDevice = NULL;
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CInput::~CInput()
{

}

//----------------------------------------
// 初期化処理
//----------------------------------------
HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
	if (m_pInput == NULL)
	{
		// DirectInputオブジェクトの生成
		if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInput, NULL)))
		{
			return E_FAIL;
		}
	}

	return S_OK;
}

//----------------------------------------
// 終了処理
//----------------------------------------
void CInput::Uninit(void)
{
	// 入力デバイスの破棄
	if (m_pDevice != NULL)
	{
		m_pDevice->Unacquire(); // アクセス権を破棄
		m_pDevice->Release();
		m_pDevice = NULL;
	}

	// DirectInputオブジェクトの破棄
	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}
}

//----------------------------------------
// キーボードのコンストラクタ
//----------------------------------------
CInputKeyboard::CInputKeyboard()
{
	for (int nCount = 0; nCount < NUM_KEY_MAX; nCount++)
	{
		m_aKeyStatePress[nCount] = NULL;
		m_aKeyStateTrigger[nCount] = NULL;
	}
}

//----------------------------------------
// キーボードのデストラクタ
//----------------------------------------
CInputKeyboard::~CInputKeyboard()
{

}

//----------------------------------------
// キーボードの初期化処理
//----------------------------------------
HRESULT CInputKeyboard::Init(HINSTANCE hInstance, HWND hWnd)
{
	CInput::Init(hInstance, hWnd);

	// デバイスの生成
	if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}

	// データフォーマットを設定
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	// 協調モードを設定
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	return S_OK;
}

//----------------------------------------
// キーボードの終了処理
//----------------------------------------
void CInputKeyboard::Uninit(void)
{
	CInput::Uninit();
}

//----------------------------------------
// キーボードの更新処理
//----------------------------------------
void CInputKeyboard::Update(void)
{
	BYTE aKeyState[NUM_KEY_MAX]; // キーボードの入力情報

	// 入力デバイスからデータを取得
	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (int nCount = 0; nCount < NUM_KEY_MAX; nCount++)
		{
			m_aKeyStateTrigger[nCount] = (m_aKeyStatePress[nCount] ^ aKeyState[nCount]) & aKeyState[nCount];
			m_aKeyStatePress[nCount] = aKeyState[nCount]; // キーボードのプレス情報を保存
		}
	}
	else
	{
		m_pDevice->Acquire(); // キーボードへのアクセス権を獲得
	}
}

//----------------------------------------
// キーボードのプレス情報取得処理
//----------------------------------------
bool CInputKeyboard::GetPress(int nKey)
{
	return (m_aKeyStatePress[nKey] & 0x80) ? true : false;
}

//----------------------------------------
// キーボードのトリガー情報取得処理
//----------------------------------------
bool CInputKeyboard::GetTrigger(int nKey)
{
	return (m_aKeyStateTrigger[nKey] & 0x80) ? true : false;
}