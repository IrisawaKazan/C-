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
#include"explosion.h"

// 静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CBullet::m_pTexture = 0;

//----------------------------------------
// バレットのコンストラクタ
//----------------------------------------
CBullet::CBullet()
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = 0;
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
CBullet* CBullet::Create(D3DXVECTOR3 pos, float xsize, float ysize)
{
	CBullet* pBullet;

	// テクスチャの設定
	CObject2D::SetUV(1.0f, 1.0f);

	// オブジェクト2Dの生成
	pBullet = new CBullet;

	// 初期化処理
	pBullet->Init(pos);
	
	pBullet->SetPosition(pos);

	// サイズの設定
	pBullet->SetSize(xsize, ysize);

	// テクスチャの割り当て
	pBullet->BindTexture(m_pTexture);

	return pBullet;
}

//----------------------------------------
// バレットの初期化処理
//----------------------------------------
HRESULT CBullet::Init(D3DXVECTOR3 pos)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = 120;

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
	// 位置の取得
	D3DXVECTOR3 pos = CBullet::GetPos();

	// 寿命のカウントダウン
	m_nLife--;

	m_move.x += BULLET_SPEED;

	// 位置を更新
	pos.x += m_move.x;
	pos.y += m_move.y;

	CBullet::SetPosition(pos);

	CObject2D::Update();

	// 外に出る, ライフがなくなると消す
	if (pos.x < 0.0f || pos.x > SCREEN_WIDTH || pos.y < 0.0f || pos.y > SCREEN_HEIGHT || m_nLife < 0)
	{
		CExplosion::Create(pos, 50.0f, 50.0f);

		CBullet::Release();
	}
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

//----------------------------------------
// バレットのサイズの設定処理
//----------------------------------------
void CBullet::SetSize(float xsize, float ysize)
{
	CObject2D::SetSize(xsize, ysize);
}