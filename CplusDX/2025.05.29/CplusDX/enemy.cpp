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
#include"bullet.h"

// 静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CEnemy::m_pTexture[MAX_ENEMYTEX] = {};

//----------------------------------------
// エネミーのコンストラクタ
//----------------------------------------
CEnemy::CEnemy(int nPriority) : CObject2D(nPriority)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = 0;
	m_type = ETYPE_NONE;
	m_nCntTimer = 0;
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
		"data\\TEXTURE\\enemy000.png",
		&m_pTexture[ETYPE_000]);

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\enemy001.png",
		&m_pTexture[ETYPE_001]);

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\enemy002.png",
		&m_pTexture[ETYPE_002]);

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\enemy003.png",
		&m_pTexture[ETYPE_003]);

	return S_OK;
}

//----------------------------------------
// テクスチャの破棄
//----------------------------------------
void CEnemy::Unload(void)
{
	for (int nCount = 0; nCount < MAX_ENEMYTEX; nCount++)
	{
		// テクスチャの破棄
		if (m_pTexture[nCount] != NULL)
		{
			m_pTexture[nCount]->Release();
			m_pTexture[nCount] = NULL;
		}
	}
}

//----------------------------------------
// エネミーの生成処理
//----------------------------------------
CEnemy* CEnemy::Create(D3DXVECTOR3 pos, float xsize, float ysize, ETYPE type)
{
	CEnemy* pEnemy;

	int nNumAll = CObject::GetNumAll();

	if (nNumAll <= MAX_OBJ)
	{
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
		pEnemy->BindTexture(m_pTexture[type]);

		return pEnemy;
	}

	return NULL;
}

//----------------------------------------
// エネミーの初期化処理
//----------------------------------------
HRESULT CEnemy::Init(D3DXVECTOR3 pos)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = 3;
	m_nCntTimer = 180;

	CObject2D::Init(pos);

	// 種類の設定処理
	CObject::SetType(TYPE_ENEMY);

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

	// 位置を更新
	pos.x += m_move.x;
	pos.y += m_move.y;

	// 弾の生成
	//CBullet::Create(pos, 50.0f, 50.0f, CBullet::BTYPE_ENEMY);

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

//----------------------------------------
// エネミーのタイプの設定処理
//----------------------------------------
void CEnemy::SetType(ETYPE type)
{
	m_type = type;
}

//----------------------------------------
// エネミーのタイプの取得処理
//----------------------------------------
CEnemy::ETYPE CEnemy::GetType(void)
{
	return m_type;
}