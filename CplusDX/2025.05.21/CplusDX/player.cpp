//==============================================================
//
// [player.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"player.h"
#include"renderer.h"
#include"manager.h"
#include"input.h"
#include"bullet.h"

// 静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CPlayer::m_pTexture = {};

//----------------------------------------
// プレイヤーのコンストラクタ
//----------------------------------------
CPlayer::CPlayer()
{
	m_move = D3DXVECTOR3(NULL, NULL, NULL);
}

//----------------------------------------
// プレイヤーのデストラクタ
//----------------------------------------
CPlayer::~CPlayer()
{

}

//----------------------------------------
// テクスチャの生成(読み込み)
//----------------------------------------
HRESULT CPlayer::Load(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\runningman000.png",
		&m_pTexture);

	return S_OK;
}

//----------------------------------------
// テクスチャの生成(読み込み)
//----------------------------------------
void CPlayer::Unload(void)
{
	// テクスチャの破棄
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//----------------------------------------
// プレイヤーの生成処理
//----------------------------------------
CPlayer* CPlayer::Create(D3DXVECTOR3 pos)
{
	CPlayer* pPlayer;

	// オブジェクト2Dの生成
	pPlayer = new CPlayer;

	// 初期化処理
	pPlayer->Init(pos);

	pPlayer->SetPosition(pos);

	// テクスチャの割り当て
	pPlayer->BindTexture(m_pTexture);

	return pPlayer;
}

//----------------------------------------
// プレイヤーの初期化処理
//----------------------------------------
HRESULT CPlayer::Init(D3DXVECTOR3 pos)
{
	CObject2D::Init(pos);

	return S_OK;
}

//----------------------------------------
// プレイヤーの終了処理
//----------------------------------------
void CPlayer::Uninit(void)
{
	CObject2D::Uninit();
}

//----------------------------------------
// プレイヤーの更新処理
//----------------------------------------
void CPlayer::Update(void)
{
	CInputKeyboard* pInputKeyboard;

	// キーボードの取得
	pInputKeyboard = CManager::GetInputKeyboard();

	// 位置の取得
	D3DXVECTOR3 pPos = CPlayer::GetPos();

	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	VERTEX_2D* pVtx = NULL; // 頂点情報へのポインタ

	if (pPos.y >= 0.0f)
	{// 上への移動制限

		if (pPos.x >= 40.0f)
		{// 左への移動制限

			if (pPos.x <= SCREEN_WIDTH - 40.0f)
			{// 右への移動制限

				if (pPos.y <= SCREEN_HEIGHT - 80.0f)
				{// 下への移動制限

					// 上へ移動
					if (pInputKeyboard->GetPress(DIK_W) == true)
					{
						m_move.y -= PLAYER_SPEED;
					}
					// 左へ移動
					if (pInputKeyboard->GetPress(DIK_A) == true)
					{
						m_move.x -= PLAYER_SPEED;
					}
					// 下へ移動
					if (pInputKeyboard->GetPress(DIK_S) == true)
					{
						m_move.y += PLAYER_SPEED;
					}
					// 右へ移動
					if (pInputKeyboard->GetPress(DIK_D) == true)
					{
						m_move.x += PLAYER_SPEED;
					}

					// 位置を更新
					pPos.x += m_move.x;
					pPos.y += m_move.y;
					//m_move.y += 0.05f; // 重力加算

					// 移動量を更新(減衰させる)
					m_move.x += (0.0f - m_move.x) * 0.085f;
					m_move.y += (0.0f - m_move.y) * 0.085f;
				}
				else
				{// 下への移動制限(上へ押し返す)
					pPos.y -= 1.0f;
				}
			}
			else
			{// 右への移動制限(左へ押し返す)
				pPos.x -= 1.0f;
			}
		}
		else
		{// 左への移動制限(右へ押し返す)
			pPos.x += 1.0f;
		}
	}
	else
	{// 上への移動制限(下へ押し返す)
		pPos.y += 1.0f;
	}
	// 移動するとアニメーションする
	if (pInputKeyboard->GetPress(DIK_W) || pInputKeyboard->GetPress(DIK_A) || pInputKeyboard->GetPress(DIK_S) || pInputKeyboard->GetPress(DIK_D) == true)
	{
		CObject2D::TextureAnimation(8, 1);
	}
	// 弾を発射
	if (pInputKeyboard->GetTrigger(DIK_SPACE) == true)
	{
		CBullet::Create(pPos);
	}

	CPlayer::SetPosition(pPos);

	CObject2D::Update();
}

//----------------------------------------
// プレイヤーの描画処理
//----------------------------------------
void CPlayer::Draw(void)
{
	CObject2D::Draw();
}

//----------------------------------------
// プレイヤーの位置の設定処理
//----------------------------------------
void CPlayer::SetPosition(D3DXVECTOR3 pos)
{
	CObject2D::SetPosition(pos);
}