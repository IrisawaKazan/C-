//==============================================================
//
// [debugproc.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"debugproc.h"
#include"manager.h"
#include"renderer.h"

// 静的メンバ変数宣言
LPD3DXFONT CDebugProc::m_pFont = nullptr;
char CDebugProc::m_aStr[MAX_CHARACTER] = {};

//----------------------------------------
// コンストラクタ
//----------------------------------------
CDebugProc::CDebugProc()
{

}

//----------------------------------------
// デストラクタ
//----------------------------------------
CDebugProc::~CDebugProc()
{

}

//----------------------------------------
// 初期化処理
//----------------------------------------
void CDebugProc::Init(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// デバッグ表示用フォントの生成
	D3DXCreateFont(pDevice, 18, 0, 0, 0,
		FALSE, SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH,
		"Terminal", &m_pFont);

	// バッファのクリア
	pDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER), D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
}

//----------------------------------------
// 終了処理
//----------------------------------------
void CDebugProc::Uninit(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// デバッグ表示用フォントの破棄
	if (m_pFont != NULL)
	{
		m_pFont->Release();
		m_pFont = NULL;
	}

	// Direct3Dデバイスの破棄
	if (pDevice != NULL)
	{
		pDevice->Release();
		pDevice = NULL;
	}
}

//----------------------------------------
// printf
//----------------------------------------
void CDebugProc::Print(const char* fint, ...)
{
	va_list args;

	va_start(args, fint);

	while (*fint)
	{
		if (*fint == '%')
		{
			fint++;
			switch (*fint)
			{
			case 'd':
				printf("%d", va_arg(args, int));
				break;
			}
		}
		else
		{
			putchar(*fint);
		}

		fint++;
	}

	va_end(args);

	// 取り出した値(文字)をバッファに連結する
	va_copy(args, m_aStr);
}

//----------------------------------------
// 描画処理
//----------------------------------------
void CDebugProc::Draw(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };

	m_pFont->DrawText(NULL, &m_aStr[0], -1, &rect, DT_LEFT, D3DCOLOR_RGBA(255, 255, 255, 255));

	// バッファのクリア
	pDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER), D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
}