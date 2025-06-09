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
#include"enemy.h"
#include"score.h"

// 静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CBullet::m_pTexture[ETYPE_MAX] = {};

//----------------------------------------
// バレットのコンストラクタ
//----------------------------------------
CBullet::CBullet(int nPriority) : CObject2D(nPriority)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = NULL;
	m_type = BTYPE_NONE;
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
		&m_pTexture[BTYPE_PLAYER]);

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\bullet001.png",
		&m_pTexture[BTYPE_ENEMY]);

	return S_OK;
}

//----------------------------------------
// テクスチャの破棄
//----------------------------------------
void CBullet::Unload(void)
{
	for (int nCount = 0; nCount < ETYPE_MAX; nCount++)
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
// バレットの生成処理
//----------------------------------------
CBullet* CBullet::Create(D3DXVECTOR3 pos, float xsize, float ysize, BTYPE type)
{
	CBullet* pBullet;

	int nNumAll = CObject::GetNumAll();

	if (nNumAll <= MAX_OBJ)
	{
		// オブジェクト2Dの生成
		pBullet = new CBullet;

		pBullet->m_type = type;

		// 初期化処理
		pBullet->Init(pos);

		// サイズの設定
		pBullet->SetSize(xsize, ysize);

		// テクスチャの割り当て
		pBullet->BindTexture(m_pTexture[type]);

		return pBullet;
	}

	return NULL;
}

//----------------------------------------
// バレットの初期化処理
//----------------------------------------
HRESULT CBullet::Init(D3DXVECTOR3 pos)
{
	// テクスチャの設定
	CObject2D::SetUV(1.0f, 1.0f);

	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = 120;

	SetPosition(pos);

	CObject2D::Init(pos);

	// 種類の設定処理
	CObject::SetType(TYPE_BULLET);

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
	D3DXVECTOR3 pos = GetPos();

	// 寿命のカウントダウン
	m_nLife--;

	switch (m_type)
	{
	case BTYPE_PLAYER:
		m_move.x = PBULLET_SPEED;
		// 外に出る, ライフがなくなると消す
		if (pos.x < 0.0f || pos.x > SCREEN_WIDTH || pos.y < 0.0f || pos.y > SCREEN_HEIGHT || m_nLife < 0)
		{
			CExplosion::Create(pos, 50.0f, 50.0f, CExplosion::EXPLOTYPE_000);

			Uninit();
			return;
		}
		break;

	case BTYPE_ENEMY:
		m_move.x = -EBULLET_SPEED;
		// 外に出る, ライフがなくなると消す
		if (pos.x < 0.0f || pos.x > SCREEN_WIDTH || pos.y < 0.0f || pos.y > SCREEN_HEIGHT || m_nLife < 0)
		{
			CExplosion::Create(pos, 50.0f, 50.0f, CExplosion::EXPLOTYPE_003);

			Uninit();
			return;
		}
		break;

	default:
		break;
	}

	// 位置を更新
	pos.x += m_move.x;
	pos.y += m_move.y;

	SetPosition(pos);

	/*// 外に出る, ライフがなくなると消す
	if (pos.x < 0.0f || pos.x > SCREEN_WIDTH || pos.y < 0.0f || pos.y > SCREEN_HEIGHT || m_nLife < 0)
	{
		CExplosion::Create(pos, 50.0f, 50.0f, CExplosion::EXPLOTYPE_000);

		//CBullet::Release();
		Uninit();
		return;
	}*/

	CObject2D::Update();

	Collision(pos);
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

//----------------------------------------
// バレットのタイプの設定処理
//----------------------------------------
void CBullet::SetType(BTYPE type)
{
	m_type = type;
}

//----------------------------------------
// バレットのタイプの取得処理
//----------------------------------------
CBullet::BTYPE CBullet::GetType(void)
{
	return m_type;
}

//----------------------------------------
// 当たり判定
//----------------------------------------
bool CBullet::Collision(D3DXVECTOR3 pos)
{
	for (int nCntPri = 0; nCntPri < MAX_PRI; nCntPri++)
	{
		for (int nCntObj = 0; nCntObj < MAX_OBJ; nCntObj++)
		{
			CObject* pObj; // オブジェクトの情報へのポインタ

			// オブジェクトを取得
			pObj = GetObj(nCntPri, nCntObj);

			if (pObj != NULL)
			{
				TYPE type;

				// 種類を取得
				type = pObj->GetType();

				if (type == TYPE_ENEMY)
				{// 種類が敵の場合

					BTYPE btype;

					btype = GetType();

					if (btype == BTYPE_PLAYER)
					{
						D3DXVECTOR3 EnemyPos;

						EnemyPos = pObj->GetPos();

						if (pos.x <= EnemyPos.x + 40.0f
							&& pos.x >= EnemyPos.x - 40.0f
							&& pos.y >= EnemyPos.y - 55.0f
							&& pos.y <= EnemyPos.y + 55.0f)
						{
							// 爆発を生成
							CExplosion::Create(EnemyPos, 50.0f, 50.0f, CExplosion::EXPLOTYPE_002);

							// スコア加算
							CScore::AddScore(1);

							// 敵の終了処理
							pObj->Uninit();

							// 自分自身の終了処理
							Uninit();

							return true;
						}
					}
				}
				if (type == TYPE_PLAYER)
				{// 種類がプレイヤーの場合

					BTYPE btype;

					btype = GetType();

					if (btype == BTYPE_ENEMY)
					{
						D3DXVECTOR3 PlayerPos;

						PlayerPos = pObj->GetPos();

						if (pos.x <= PlayerPos.x + 40.0f
							&& pos.x >= PlayerPos.x - 40.0f
							&& pos.y >= PlayerPos.y - 55.0f
							&& pos.y <= PlayerPos.y + 55.0f)
						{
							// 爆発を生成
							CExplosion::Create(PlayerPos, 50.0f, 50.0f, CExplosion::EXPLOTYPE_001);

							// 敵の終了処理
							pObj->Uninit();

							// 自分自身の終了処理
							Uninit();

							return true;
						}
					}
				}
			}
		}
	}

	return false;
}