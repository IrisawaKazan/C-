//==============================================================
//
// [bullet.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"bullet.h"
#include"renderer.h"
#include"manager.h"
#include"input.h"

// 静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CBullet::m_pTexture = {};

//----------------------------------------
// バレットのコンストラクタ
//----------------------------------------
CBullet::CBullet()
{
	m_move = {};
}

//----------------------------------------
// バレットのデストラクタ
//----------------------------------------
CBullet::~CBullet()
{

}

//----------------------------------------
// テクスチャの生成(読み込み)
//----------------------------------------
HRESULT CBullet::Load(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\bullet000.png",
		&m_pTexture);

	return S_OK;
}

//----------------------------------------
// テクスチャの生成(読み込み)
//----------------------------------------
void CBullet::Unload(void)
{
	// テクスチャの破棄
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//----------------------------------------
// バレットの生成処理
//----------------------------------------
CBullet* CBullet::Create(D3DXVECTOR3 pos)
{
	CBullet* pBullet;

	// オブジェクト2Dの生成
	pBullet = new CBullet;

	// 初期化処理
	pBullet->Init(pos);

	pBullet->SetPosition(pos);

	// テクスチャの割り当て
	pBullet->BindTexture(m_pTexture);

	return pBullet;
}

//----------------------------------------
// バレットの初期化処理
//----------------------------------------
HRESULT CBullet::Init(D3DXVECTOR3 pos)
{
	CObject2D::Init(pos);

	return S_OK;
}

//----------------------------------------
// バレットの終了処理
//----------------------------------------
void CBullet::Uninit(void)
{
	CObject2D::Uninit();
}

//----------------------------------------
// バレットの更新処理
//----------------------------------------
void CBullet::Update(void)
{
	CObject2D::Update();
}

//----------------------------------------
// バレットの描画処理
//----------------------------------------
void CBullet::Draw(void)
{
	CObject2D::Draw();
}

//----------------------------------------
// バレットの位置の設定処理
//----------------------------------------
void CBullet::SetPosition(D3DXVECTOR3 pos)
{
	CObject2D::SetPosition(pos);
}