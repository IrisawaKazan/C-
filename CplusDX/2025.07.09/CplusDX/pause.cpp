//==============================================================
//
// [pause.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"pause.h"
#include"manager.h"
#include"renderer.h"
#include"input.h"

// 静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CPause::m_pTexture = nullptr;

//----------------------------------------
// ポーズのコンストラクタ
//----------------------------------------
CPause::CPause(int nPriority)
{

}

//----------------------------------------
// ポーズのデストラクタ
//----------------------------------------
CPause::~CPause()
{
}

//----------------------------------------
// テクスチャの生成(読み込み)
//----------------------------------------
HRESULT CPause::Load(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\pause001.png",
		&m_pTexture);

	return S_OK;
}

//----------------------------------------
// テクスチャの破棄
//----------------------------------------
void CPause::Unload(void)
{
	// テクスチャの破棄
	if (m_pTexture != nullptr)
	{
		m_pTexture->Release();
		m_pTexture = nullptr;
	}
}

//----------------------------------------
// 生成処理
//----------------------------------------
CPause* CPause::Create(D3DXVECTOR3 pos, float xsize, float ysize)
{
	CPause* pPause;

	int nNumAll = CObject::GetNumAll();

	if (nNumAll <= MAX_OBJ)
	{
		// オブジェクト2Dの生成
		pPause = new CPause;

		// テクスチャの設定
		pPause->SetUV(1.0f, 1.0f);

		// 初期化処理
		pPause->Init(pos);

		pPause->SetPosition(pos);

		// サイズの設定
		pPause->SetSize(xsize, ysize);

		// テクスチャの割り当て
		pPause->BindTexture(m_pTexture);

		return pPause;
	}

	return NULL;
}

//----------------------------------------
// ポーズの初期化処理
//----------------------------------------
HRESULT CPause::Init(D3DXVECTOR3 pos)
{
	CObject2D::Init(pos);

	// 種類の設定処理
	CObject::SetType(TYPE_PAUSE);

	return S_OK;
}

//----------------------------------------
// ポーズの終了処理
//----------------------------------------
void CPause::Uninit(void)
{
	CObject2D::Uninit();
}

//----------------------------------------
// ポーズの更新処理
//----------------------------------------
void CPause::Update(void)
{
	CObject2D::Update();
}

//----------------------------------------
// ポーズの描画処理
//----------------------------------------
void CPause::Draw(void)
{
	CObject2D::Draw();
}

//----------------------------------------
// ポーズの位置の設定処理
//----------------------------------------
void CPause::SetPosition(D3DXVECTOR3 pos)
{
	CObject2D::SetPosition(pos);
}

//----------------------------------------
// ポーズのサイズの設定処理
//----------------------------------------
void CPause::SetSize(float xsize, float ysize)
{
	CObject2D::SetSize(xsize, ysize);
}