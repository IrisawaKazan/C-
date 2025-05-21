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

//----------------------------------------
// プレイヤーのコンストラクタ
//----------------------------------------
CPlayer::CPlayer()
{
	m_nCounterAnim = 0;
	m_nPatternAnim = 0;
	m_move = D3DXVECTOR3(NULL, NULL, NULL);
}

//----------------------------------------
// プレイヤーのデストラクタ
//----------------------------------------
CPlayer::~CPlayer()
{

}

//----------------------------------------
// プレイヤーの生成処理
//----------------------------------------
CPlayer* CPlayer::Create(void)
{
	CPlayer* pCPlayer;

	// オブジェクト2Dの生成
	pCPlayer = new CPlayer;

	// 初期化処理
	pCPlayer->Init();

	return pCPlayer;
}

//----------------------------------------
// プレイヤーの初期化処理
//----------------------------------------
HRESULT CPlayer::Init(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// テクスチャの初期化処理
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\runningman000.png",
		&m_pTexture);

	// 頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_2D* pVtx; // 頂点情報へのポインタ

	// 頂点バッファをロックし,頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点座標の設定
	pVtx[0].pos.x = m_pos.x - 50.0f;
	pVtx[0].pos.y = m_pos.y;
	pVtx[0].pos.z = 0.0f;
	pVtx[1].pos.x = m_pos.x + 50.0f;
	pVtx[1].pos.y = m_pos.y;
	pVtx[1].pos.z = 0.0f;
	pVtx[2].pos.x = m_pos.x - 50.0f;
	pVtx[2].pos.y = m_pos.y + 80.0f;
	pVtx[2].pos.z = 0.0f;
	pVtx[3].pos.x = m_pos.x + 50.0f;
	pVtx[3].pos.y = m_pos.y + 80.0f;
	pVtx[3].pos.z = 0.0f;

	// rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	// 頂点カラーの設定
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	// テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(0.125f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(0.125f, 1.0f);

	// 頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

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

	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	VERTEX_2D* pVtx = NULL; // 頂点情報へのポインタ

	// 頂点バッファをロックし,頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	m_nCounterAnim++; // カウンターを計算

	if (m_pos.y >= -10.0f)
	{// 上への移動制限

		if (m_pos.x >= 80.0f)
		{// 左への移動制限

			if (m_pos.x <= SCREEN_WIDTH - 70.0f)
			{// 右への移動制限

				if (m_pos.y <= SCREEN_HEIGHT - 190.0f)
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
					m_pos.x += m_move.x;
					m_pos.y += m_move.y;
					//m_move.y += 0.05f; // 重力加算

					// 移動量を更新(減衰させる)
					m_move.x += (0.0f - m_move.x) * 0.085f;
					m_move.y += (0.0f - m_move.y) * 0.085f;
				}
				else
				{// 下への移動制限(上へ押し返す)
					m_pos.y -= 1.0f;
				}
			}
			else
			{// 右への移動制限(左へ押し返す)
				m_pos.x -= 1.0f;
			}
		}
		else
		{// 左への移動制限(右へ押し返す)
			m_pos.x += 1.0f;
		}
	}
	else
	{// 上への移動制限(下へ押し返す)
		m_pos.y += 1.0f;
	}
	// 移動するとアニメーションする
	if (pInputKeyboard->GetPress(DIK_W) || pInputKeyboard->GetPress(DIK_A) || pInputKeyboard->GetPress(DIK_S) || pInputKeyboard->GetPress(DIK_D) == true)
	{
		// アニメーション
		if (m_nCounterAnim % 15 == 0)
		{
			m_nCounterAnim = 0;                        // カウンターを初期値に戻す
			m_nPatternAnim = (m_nPatternAnim + 1) % 8; // パターンNo.を更新する

			// テクスチャ座標の設定
			pVtx[0].tex = D3DXVECTOR2(m_nPatternAnim * 0.125f, 0.0f);
			pVtx[1].tex = D3DXVECTOR2(m_nPatternAnim * 0.125f + 0.125f, 0.0f);
			pVtx[2].tex = D3DXVECTOR2(m_nPatternAnim * 0.125f, 1.0f);
			pVtx[3].tex = D3DXVECTOR2(m_nPatternAnim * 0.125f + 0.125f, 1.0f);
		}
	}

	// テクスチャ座標の更新
	pVtx[0].pos.x = m_pos.x - 100.0f;
	pVtx[0].pos.y = m_pos.y;
	pVtx[0].pos.z = 0.0f;
	pVtx[1].pos.x = m_pos.x + 100.0f;
	pVtx[1].pos.y = m_pos.y;
	pVtx[1].pos.z = 0.0f;
	pVtx[2].pos.x = m_pos.x - 100.0f;
	pVtx[2].pos.y = m_pos.y + 200.0f;
	pVtx[2].pos.z = 0.0f;
	pVtx[3].pos.x = m_pos.x + 100.0f;
	pVtx[3].pos.y = m_pos.y + 200.0f;
	pVtx[3].pos.z = 0.0f;

	// 頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
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
	VERTEX_2D* pVtx; // 頂点情報へのポインタ

	// 頂点バッファをロックし,頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	m_pos = pos;

	pVtx[0].pos.x = m_pos.x - 50.0f;
	pVtx[0].pos.y = m_pos.y;
	pVtx[0].pos.z = 0.0f;
	pVtx[1].pos.x = m_pos.x + 50.0f;
	pVtx[1].pos.y = m_pos.y;
	pVtx[1].pos.z = 0.0f;
	pVtx[2].pos.x = m_pos.x - 50.0f;
	pVtx[2].pos.y = m_pos.y + 80.0f;
	pVtx[2].pos.z = 0.0f;
	pVtx[3].pos.x = m_pos.x + 50.0f;
	pVtx[3].pos.y = m_pos.y + 80.0f;
	pVtx[3].pos.z = 0.0f;

	// 頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}