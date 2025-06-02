//==============================================================
//
// [main.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"main.h"
#include"renderer.h"
#include"object.h"
#include"object2D.h"
#include"manager.h"

// プロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam);

//----------------------------------------
// メイン関数
//----------------------------------------
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hinstancePrev, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	CManager* pManager = NULL;

	//DWORD dwCurrentTime;
	//DWORD dwExecLastTime;

	WNDCLASSEX wcex
	{
		sizeof(WNDCLASSEX),             // WINDCLASSEXのメモリサイズ
		CS_CLASSDC,                     // ウィンドウのスタイル
		WindowProc,                     // ウィンドウプロシージャ
		0,                              // 0にする(通常は使用しない)
		0,                              // 0にする(通常は使用しない)
		hInstance,                      // インスタンスハンドル
		LoadIcon(NULL,IDI_APPLICATION), // タスクバーのアイコン
		LoadCursor(NULL,IDC_ARROW),     // マウスカーソル
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,
		CLASS_NAME,
		LoadIcon(NULL,IDI_APPLICATION)
	};

	HWND hWnd;                                      // ウィンドウハンドル
	MSG msg;                                        // メッセージを格納する変数
	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT }; // 画面サイズの構造体

	// ウィンドウクラスの登録
	RegisterClassEx(&wcex);

	// クライアント領域を指定のサイズに調整
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	// ウィンドウを生成
	hWnd = CreateWindowEx(0,
		CLASS_NAME,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		(rect.right - rect.left), // ウィンドウの幅
		(rect.bottom - rect.top), // ウィンドウの高さ
		NULL,
		NULL,
		hInstance,
		NULL);

	// マネージャの生成
	pManager = new CManager;

	// マネージャの初期化処理
	pManager->Init(hInstance, hWnd);

	//// オブジェクトの生成
	//CObject2D::Create()->SetPosition(D3DXVECTOR3(100.0f, 100.0f, 0.0f));
	//CObject2D::Create()->SetPosition(D3DXVECTOR3(500.0f, 500.0f, 0.0f));
	//CObject2D::Create()->SetPosition(D3DXVECTOR3(800.0f, 250.0f, 0.0f));

	// ウィンドウの表示
	ShowWindow(hWnd, nCmdShow); // ウィンドウの表示状態を設定
	UpdateWindow(hWnd);         // クライアント領域を更新

	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
		{// windowsの処理
			if (msg.message == WM_QUIT)
			{// WM_QUITメッセージを受け取ったらメッセージループを抜ける
				break;
			}
			else
			{
				// メッセージの設定
				TranslateMessage(&msg); // 仮想キーメッセージを文字メッセージへ変換
				DispatchMessage(&msg);  // ウィンドウプロシージャへメッセージを送出
			}
		}
		else
		{
			// マネージャの更新処理
			pManager->Update();

			// マネージャの描画処理
			pManager->Draw();
		}
	}
	
	//// オブジェクトの破棄
	//CObject::ReleaseAll();

	//// レンダラーの破棄
	//if (pManager != NULL)
	//{
	//	// 終了処理
	//	pManager->Uninit();

	//	delete pManager;

	//	pManager = NULL;
	//}

	// ウィンドウクラスの登録を解除
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	return (int)msg.wParam;
}

//----------------------------------------
// ウィンドウプロシージャ
//----------------------------------------
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		// WM_QUITメッセージを送る
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			// ウィンドウを破棄する
			DestroyWindow(hWnd);
			break;
		}
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, IParam);
}