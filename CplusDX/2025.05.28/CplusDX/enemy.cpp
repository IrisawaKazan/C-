//==============================================================
//
// [enemy.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"enemy.h"
#include"renderer.h"
#include"manager.h"
#include"input.h"
#include"explosion.h"

// 静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CEnemy::m_pTexture = 0;

//----------------------------------------
// エネミーのコンストラクタ
//----------------------------------------
CEnemy::CEnemy()
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = 0;
}

//----------------------------------------
// エネミーのデストラクタ
//----------------------------------------
CEnemy::~CEnemy()
{

}

//----------------------------------------
// テクスチャの生成(読み込み)
//----------------------------------------
HRESULT CEnemy::Load(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\sampleenemy.png",
		&m_pTexture);

	return S_OK;
}

//----------------------------------------
// テクスチャの生成(読み込み)
//----------------------------------------
void CEnemy::Unload(void)
{
	// テクスチャの破棄
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//----------------------------------------
// エネミーの生成処理
//----------------------------------------
CEnemy* CEnemy::Create(D3DXVECTOR3 pos, float xsize, float ysize)
{
	CEnemy* pEnemy;

	// オブジェクト2Dの生成
	pEnemy = new CEnemy;

	// テクスチャの設定
	pEnemy->SetUV(1.0f, 1.0f);

	// 初期化処理
	pEnemy->Init(pos);

	pEnemy->SetPosition(pos);

	// サイズの設定
	pEnemy->SetSize(xsize, ysize);

	// テクスチャの割り当て
	pEnemy->BindTexture(m_pTexture);

	return pEnemy;
}

//----------------------------------------
// エネミーの初期化処理
//----------------------------------------
HRESULT CEnemy::Init(D3DXVECTOR3 pos)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = 120;

	CObject2D::Init(pos);

	// 種類の設定処理
	SetType(TYPE_ENEMY);

	return S_OK;
}

//----------------------------------------
// エネミーの終了処理
//----------------------------------------
void CEnemy::Uninit(void)
{
	CObject2D::Uninit();
}

//----------------------------------------
// エネミーの更新処理
//----------------------------------------
void CEnemy::Update(void)
{
	// 位置の取得
	D3DXVECTOR3 pos = CEnemy::GetPos();

	CEnemy::SetPosition(pos);

	CObject2D::Update();
}

//----------------------------------------
// エネミーの描画処理
//----------------------------------------
void CEnemy::Draw(void)
{
	CObject2D::Draw();
}

//----------------------------------------
// エネミーの位置の設定処理
//----------------------------------------
void CEnemy::SetPosition(D3DXVECTOR3 pos)
{
	CObject2D::SetPosition(pos);
}

//----------------------------------------
// エネミーのサイズの設定処理
//----------------------------------------
void CEnemy::SetSize(float xsize, float ysize)
{
	CObject2D::SetSize(xsize, ysize);
}