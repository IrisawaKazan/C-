//==============================================================
//
// [renderer.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"renderer.h"
#include"object.h"
#include"debugproc.h"
#include"manager.h"
#include"titlemanager.h"

// 静的メンバ変数宣言
int CRenderer::m_nCntFPS = NULL;

//----------------------------------------
// コンストラクタ
//----------------------------------------
CRenderer::CRenderer()
{
	m_pD3D = nullptr;
	m_pD3DDevice = nullptr;
	//m_mode = MODE_TITLE;
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CRenderer::~CRenderer()
{

}

//----------------------------------------
// 初期化処理
//----------------------------------------
HRESULT CRenderer::Init(HWND hWnd, BOOL bWindow)
{
	D3DDISPLAYMODE d3ddm;        // ディスプレイモード
	D3DPRESENT_PARAMETERS d3dpp; // プレゼンテーションパラメータ

	// Direct3Dオブジェクト作成
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (m_pD3D == nullptr)
	{
		return E_FAIL;
	}

	// 現在のディスプレイモードを取得
	if (FAILED(m_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
	{
		return E_FAIL;
	}

	// デバイスのプレゼンテーションパラメータの設定
	ZeroMemory(&d3dpp, sizeof(d3dpp));                          // パラメータのゼロクリア
	d3dpp.BackBufferWidth = SCREEN_WIDTH;                       // ゲーム画面のサイズ(幅)
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;                     // ゲーム画面のサイズ(高さ)
	d3dpp.BackBufferFormat = d3ddm.Format;                      // バックバッファの形式
	d3dpp.BackBufferCount = 1;                                  // バックバッファの数
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;                   // ダブルバッファの切り替え(映像信号に同期)
	d3dpp.EnableAutoDepthStencil = TRUE;                        // デプスバッファとステンシルバッファを作成
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;                  // デプスバッファとして16bitを使う
	d3dpp.Windowed = bWindow;                                   // ウィンドウモード
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT; // リフレッシュレート
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;   // インターバル

	// Direct3Dデバイスの生成(描画処理と頂点処理をハードウェアで行う)
	if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &m_pD3DDevice)))
	{
		// Direct3Dデバイスの生成(描画処理と頂点処理をハードウェアで行う)
		if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &m_pD3DDevice)))
		{
			// Direct3Dデバイスの生成(描画処理と頂点処理をCPUで行なう)
			if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &m_pD3DDevice)))
			{
				return E_FAIL;
			}
		}
	}

	// レンダーステートの設定
	m_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	m_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	m_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	m_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	// サンプラーステートの設定
	m_pD3DDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	m_pD3DDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	m_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
	m_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);

	// テクスチャステージステートの設定
	m_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	m_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	m_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_CURRENT);

	return S_OK;
}

//----------------------------------------
// 終了処理
//----------------------------------------
void CRenderer::Uninit(void)
{
	//// タイトル画面の取得
	//CTitle* pTitle = nullptr;

	//// ゲーム画面の取得
	//CManager* pManager = nullptr;

	//switch (m_mode)
	//{
	//case MODE_TITLE: // タイトル(最高スコア)画面
	//	pTitle->Uninit();
	//	break;

	//case MODE_GAME: // ゲーム画面
	//	pManager->Uninit();
	//	break;
	//}

	CObject::ReleaseAll();

	// Direct3Dデバイスの破棄
	if (m_pD3DDevice != nullptr)
	{
		m_pD3DDevice->Release();
		m_pD3DDevice = nullptr;
	}

	// Direct3Dオブジェクトの破棄
	if (m_pD3D != nullptr)
	{
		m_pD3D->Release();
		m_pD3D = nullptr;
	}
}

//----------------------------------------
// 更新処理
//----------------------------------------
void CRenderer::Update(void)
{
	// 全てのオブジェクトの更新処理
	CObject::UpdateAll();

	//// タイトル画面の取得
	//CTitle* pTitle = nullptr;

	//// ゲーム画面の取得
	//CManager* pManager = nullptr;

	//switch (m_mode)
	//{
	//case MODE_TITLE: // タイトル(最高スコア)画面
	//	pTitle->Update();
	//	break;

	//case MODE_GAME: // ゲーム画面
	//	pManager->Update();
	//	break;
	//}
}

//----------------------------------------
// 描画処理
//----------------------------------------
void CRenderer::Draw(void)
{
	// 画面クリア(バックバッファ&Zバッファのクリア)
	m_pD3DDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER), D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
	
	// 描画開始
	if (SUCCEEDED(m_pD3DDevice->BeginScene()))
	{
		// 全てのオブジェクトの描画処理
		CObject::DrawAll();

		//// タイトル画面の取得
		//CTitle* pTitle = nullptr;

		//// ゲーム画面の取得
		//CManager* pManager = nullptr;

		//switch (m_mode)
		//{
		//case MODE_TITLE: // タイトル(最高スコア)画面
		//	pTitle->Update();
		//	break;

		//case MODE_GAME: // ゲーム画面
		//	pManager->Draw();
		//	break;
		//}

#ifdef _DEBUG

		m_nCntFPS = GetFPS();

		CDebugProc::Print("FPS: %d", m_nCntFPS);

		CDebugProc::Draw();

#endif

		// 描画終了
		m_pD3DDevice->EndScene();
	}


	// バックバッファとフロントバッファの入れ替え
	m_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

//----------------------------------------
// 取得処理
//----------------------------------------
LPDIRECT3DDEVICE9 CRenderer::GetDevice(void)
{
	return m_pD3DDevice;
}

////----------------------------------------
//// モードの設定処理
////----------------------------------------
//void CRenderer::SetMode(MODE mode)
//{
//	// タイトル画面の取得
//	CTitle* pTitle = nullptr;
//
//	// ゲーム画面の取得
//	CManager* pManager = nullptr;
//
//	// 現在の画面(モード)の終了処理
//	switch (m_mode)
//	{
//	case MODE_TITLE: // タイトル(最高スコア)画面
//		pTitle->Uninit();
//		break;
//
//	case MODE_GAME: // ゲーム画面
//		pManager->Uninit();
//		break;
//	}
//
//	// 新しい画面(モード)の初期化処理
//	switch (m_mode)
//	{
//	case MODE_TITLE: // タイトル(最高スコア)画面
//		pTitle->Init();
//		break;
//
//	case MODE_GAME: // ゲーム画面
//		pManager->Init();
//		break;
//	}
//
//	m_mode = mode;
//}

////----------------------------------------
//// モードの取得処理
////----------------------------------------
//CRenderer::MODE CRenderer::GetMode(void)
//{
//	return m_mode;
//}