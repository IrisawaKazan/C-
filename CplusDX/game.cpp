//==============================================================
//
// [game.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"game.h"
#include"object2D.h"
#include"player.h"
#include"background.h"
#include"renderer.h"
#include"input.h"
#include"bullet.h"
#include"explosion.h"
#include"enemy.h"
#include"sound.h"
#include"score.h"
#include"camera.h"
#include"light.h"
#include"object3D.h"
#include"timer.h"
#include"objectX.h"
#include"objectBillboard.h"
#include"debugproc.h"
#include"effect.h"
#include"pause.h"
#include"playerX.h"
#include"bgX.h"
#include"debrisX.h"
#include"deadzoneX.h"
#include"scrapX.h"
#include"stardustX.h"
#include"coin10X.h"
#include"SmallThingsX.h"
#include"effect3D.h"
#include"boostUI.h"
#include"BlackThingsX.h"
#include"fade.h"
#include"UFO.h"
#include"gameBG.h"
#include"spaceshipX.h"
#include"spaceship_rotationX.h"
#include"DStarX.h"
#include"mfX.h"

// 静的メンバ変数宣言
CObjectX* CGame::m_pObjectX = nullptr;
CPause* CGame::m_pPause = nullptr;

//----------------------------------------
// コンストラクタ
//----------------------------------------
CGame::CGame() : CScene(CScene::MODE_GAME)
{
	m_bPause = false;
	m_nSpawn = NULL;

	for (int nCnt = 0; nCnt < MAX_FRAMECOUNTER; nCnt++)
	{
		m_nFrameCounter[nCnt] = NULL;
	}

	m_nScrapCounter = NULL;
	m_nSmallThingsCounter = NULL;
	m_nBlackThingsCounter = NULL;

	m_nSmallThingsSpawn = NULL;

	m_nTransition = NULL;
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CGame::~CGame()
{

}

//----------------------------------------
// 初期化処理
//----------------------------------------
HRESULT CGame::Init(void)
{
	// エフェクトのテクスチャの読み込み
	CEffect::Load();

	// スコアのテクスチャの読み込み
	CScore::Load();

	// タイマーのテクスチャの読み込み
	CTimer::Load();

	// ポーズのテクスチャの読み込み
	CPause::Load();

	// サウンドの取得
	CSound* pSound = CManager::GetSound();

	// bgXの生成
	//CBackgroundX::Create(D3DXVECTOR3(0.0f, -325.0f, 0.0f));
	CGameBGX::Create(D3DXVECTOR3(0.0f, -600.0f, 0.0f));

	// 背景の宇宙船の生成
	CSpaceshipX::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	CSpaceshipRotationX::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// 背景のDスターの生成
	CDStarX::Create(D3DXVECTOR3(-350.0f, -500.0f, 200.0f));

	// 背景のMFの生成
	CMf::Create(D3DXVECTOR3(-100.0f, -300.0f, 0.0f));

	// オブジェクトXの生成(初期配置)
	m_pObjectX = CObjectX::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// 確認用
	//CCoin10X::Create(D3DXVECTOR3(300.0f, 0.0f, -100.0f), CCoin10X::COIN10_000_B);

	// デッドゾーンの生成(初期配置)
	CDeadzoneX::Create(D3DXVECTOR3(0.0f, 0.0f, 147.5f));

	// スコア
	CScore::Create(D3DXVECTOR3(1100.0f, 50.0f, 0.0f), 30.0f, 90.0f);

#ifdef _DEBUG // Debug時のみ

	// タイマー
	CTimer::Create(D3DXVECTOR3(50.0f, 675.0f, 0.0f), 30.0f, 90.0f);

#endif

	// BGM
	pSound->PlaySoundA(CSound::SOUND_LABEL_GAME_BGM);

	m_bPause = false; // ポーズ解除

	m_nTransition = 0;

	return S_OK;
}

//----------------------------------------
// 終了処理
//----------------------------------------
void CGame::Uninit(void)
{
	// エフェクトのテクスチャの破棄
	CEffect::Unload();

	// スコアのテクスチャの破棄
	CScore::Unload();

	// タイマーのテクスチャの破棄
	CTimer::Unload();

	// ポーズのテクスチャの破棄
	CPause::Unload();

	CObject::Release();

	//// プレイヤーの破棄
	//if (m_pObjectX != nullptr)
	//{
	//	m_pObjectX = nullptr;
	//}
}

//----------------------------------------
// 更新処理
//----------------------------------------
void CGame::Update(void)
{
	// キーボードの取得
	CInputKeyboard* pInputKeyboard;
	pInputKeyboard = CManager::GetInputKeyboard();

	// マウスの取得
	CInputMouse* pInputMouse;
	pInputMouse = CManager::GetInputMouse();

	// パッドの取得
	CInputJoypad* pInputJoypad;
	pInputJoypad = CManager::GetInputJoypad();

	// サウンドの取得
	CSound* pSound = CManager::GetSound();

	//if (pInputKeyboard->GetTrigger(DIK_TAB) || pInputKeyboard->GetTrigger(DIK_P) || pInputJoypad->GetTrigger(pInputJoypad->JOYKEY_B) == true)
	//{// プレイヤーが生きている時にポーズキーが押された
	//	m_bPause = m_bPause ? false : true;
	//}

	//if (m_bPause == true)
	{// ポーズ中
		//m_pPause = CPause::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), SCREEN_WIDTH, SCREEN_HEIGHT);

		//m_pPause->Update();

		//m_pPause->Draw();
	}

	//if (m_bPause == false)
	{// ポーズ中でなければ
		// ランダム生成
		m_nSpawn++;
		m_nSmallThingsSpawn++;

		float fPosZ = (float)(rand() % 130/* 出てくる範囲 */);

		// 現在の時刻を種として設定
		srand((unsigned int)time(nullptr));

		// 多段で出ないように制限するカウンター
		for (int nCnt = 0; nCnt < MAX_FRAMECOUNTER; nCnt++)
		{
			m_nFrameCounter[nCnt]++;
		}

		// トゲトゲ→
		if (m_nSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[0] >= NUM_FRAME_CNT)
		{
			CDebrisX::Create(D3DXVECTOR3(-SPAWN_POS_X, 0.0f, fPosZ), CDebrisX::DEBRIS_000_A);

			m_nSpawn = 0;
			m_nFrameCounter[0] = 0;
		}
		if (m_nSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[1] >= NUM_FRAME_CNT)
		{
			CDebrisX::Create(D3DXVECTOR3(-SPAWN_POS_X, 0.0f, -fPosZ), CDebrisX::DEBRIS_000_A);

			m_nSpawn = 0;
			m_nFrameCounter[1] = 0;
		}

		// ←トゲトゲ
		if (m_nSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[2] >= NUM_FRAME_CNT)
		{
			CDebrisX::Create(D3DXVECTOR3(SPAWN_POS_X, 0.0f, fPosZ), CDebrisX::DEBRIS_000_B);

			m_nSpawn = 0;
			m_nFrameCounter[2] = 0;
		}
		if (m_nSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[3] >= NUM_FRAME_CNT)
		{
			CDebrisX::Create(D3DXVECTOR3(SPAWN_POS_X, 0.0f, -fPosZ), CDebrisX::DEBRIS_000_B);

			m_nSpawn = 0;
			m_nFrameCounter[3] = 0;
		}

		// m_nScrapCounterを止める
		if (m_nScrapCounter <= 60 * 20/* 秒 */) // m_nScrapCounter(初期値: 0)が1200以下の時
		{
			m_nScrapCounter++; // インクリメントし続ける
		}

		// 20秒経ったら出現しだす
		if (m_nScrapCounter >= 60 * 20/* 秒 */) // m_nScrapCounter(初期値: 0)が1200以上の時
		{
			// スクラップ→
			if (m_nSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[4] >= NUM_FRAME_CNT)
			{
				CScrap::Create(D3DXVECTOR3(-SPAWN_POS_X, 0.0f, fPosZ), CScrap::SCRAP_000_A);

				m_nSpawn = 0;
				m_nFrameCounter[4] = 0;
			}
			if (m_nSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[5] >= NUM_FRAME_CNT)
			{
				CScrap::Create(D3DXVECTOR3(-SPAWN_POS_X, 0.0f, -fPosZ), CScrap::SCRAP_000_A);

				m_nSpawn = 0;
				m_nFrameCounter[5] = 0;
			}

			// ←スクラップ
			if (m_nSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[6] >= NUM_FRAME_CNT)
			{
				CScrap::Create(D3DXVECTOR3(SPAWN_POS_X, 0.0f, fPosZ), CScrap::SCRAP_000_B);

				m_nSpawn = 0;
				m_nFrameCounter[6] = 0;
			}
			if (m_nSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[7] >= NUM_FRAME_CNT)
			{
				CScrap::Create(D3DXVECTOR3(SPAWN_POS_X, 0.0f, -fPosZ), CScrap::SCRAP_000_B);

				m_nSpawn = 0;
				m_nFrameCounter[7] = 0;
			}
		}

		// m_nSmallThingsCounterを止める
		if (m_nSmallThingsCounter <= 60 * 40/* 秒 */) // m_nSmallThingsCounter(初期値: 0)が2400以下の時
		{
			m_nSmallThingsCounter++; // インクリメントし続ける
		}

		// 40秒経ったら出現しだす
		if (m_nSmallThingsCounter >= 60 * 40/* 秒 */) // m_nSmallThingsCounter(初期値: 0)が2400以上の時
		{
			// スモールエネミー→
			if (m_nSmallThingsSpawn >= rand() / MAX_SmallThings_SPAWN && m_nFrameCounter[16] >= NUM_FRAME_CNT)
			{
				CSmallThingsX::Create(D3DXVECTOR3(-SPAWN_POS_X, 0.0f, fPosZ), CSmallThingsX::SMALLTHINGS_000_A);

				m_nSmallThingsSpawn = 0;
				m_nFrameCounter[16] = 0;
			}
			if (m_nSmallThingsSpawn >= rand() / MAX_SmallThings_SPAWN && m_nFrameCounter[17] >= NUM_FRAME_CNT)
			{
				CSmallThingsX::Create(D3DXVECTOR3(-SPAWN_POS_X, 0.0f, -fPosZ), CSmallThingsX::SMALLTHINGS_000_A);

				m_nSmallThingsSpawn = 0;
				m_nFrameCounter[17] = 0;
			}

			// ←スモールエネミー
			if (m_nSmallThingsSpawn >= rand() / MAX_SmallThings_SPAWN && m_nFrameCounter[18] >= NUM_FRAME_CNT)
			{
				CSmallThingsX::Create(D3DXVECTOR3(SPAWN_POS_X, 0.0f, fPosZ), CSmallThingsX::SMALLTHINGS_000_B);

				m_nSmallThingsSpawn = 0;
				m_nFrameCounter[18] = 0;
			}
			if (m_nSmallThingsSpawn >= rand() / MAX_SmallThings_SPAWN && m_nFrameCounter[19] >= NUM_FRAME_CNT)
			{
				CSmallThingsX::Create(D3DXVECTOR3(SPAWN_POS_X, 0.0f, -fPosZ), CSmallThingsX::SMALLTHINGS_000_B);

				m_nSmallThingsSpawn = 0;
				m_nFrameCounter[19] = 0;
			}
		}

		// m_nBlackThingsCounterを止める
		if (m_nBlackThingsCounter <= 60 * 60/* 秒 */) // m_nBlackThingsCounter(初期値: 0)が3600以下の時
		{
			m_nBlackThingsCounter++; // インクリメントし続ける
		}

		// 60秒経ったら出現しだす
		if (m_nBlackThingsCounter >= 60 * 60/* 秒 */) // m_nBlackThingsCounter(初期値: 0)が3600以上の時
		{
			// ブラックエネミー→
			if (m_nSmallThingsSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[20] >= NUM_FRAME_CNT)
			{
				CBlackThingsX::Create(D3DXVECTOR3(-SPAWN_POS_X, 0.0f, fPosZ), CBlackThingsX::BLACKTHINGS_000_A);

				m_nSpawn = 0;
				m_nFrameCounter[20] = 0;
			}
			if (m_nSmallThingsSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[21] >= NUM_FRAME_CNT)
			{
				CBlackThingsX::Create(D3DXVECTOR3(-SPAWN_POS_X, 0.0f, -fPosZ), CBlackThingsX::BLACKTHINGS_000_A);

				m_nSpawn = 0;
				m_nFrameCounter[21] = 0;
			}

			// ←ブラックエネミー
			if (m_nSmallThingsSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[22] >= NUM_FRAME_CNT)
			{
				CBlackThingsX::Create(D3DXVECTOR3(SPAWN_POS_X, 0.0f, fPosZ), CBlackThingsX::BLACKTHINGS_000_B);

				m_nSpawn = 0;
				m_nFrameCounter[22] = 0;
			}
			if (m_nSmallThingsSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[23] >= NUM_FRAME_CNT)
			{
				CBlackThingsX::Create(D3DXVECTOR3(SPAWN_POS_X, 0.0f, -fPosZ), CBlackThingsX::BLACKTHINGS_000_B);

				m_nSpawn = 0;
				m_nFrameCounter[23] = 0;
			}
		}


		// アイテム→
		if (m_nSpawn >= rand() / MAX_STARDUST_SPAWN &&
			m_nFrameCounter[8] >= NUM_STARDUST_FRAME_CNT &&
			m_pObjectX->GetSigns() == false &&
			m_pObjectX->GetPowerUp() == false &&
			m_pObjectX->GetScoreBonus() == false)
		{
			CStardustX::Create(D3DXVECTOR3(-SPAWN_POS_X, 0.0f, fPosZ), CStardustX::STARDUST_000_A);

			m_nSpawn = 0;
			m_nFrameCounter[8] = 0;
		}
		if (m_nSpawn >= rand() / MAX_STARDUST_SPAWN &&
			m_nFrameCounter[9] >= NUM_STARDUST_FRAME_CNT &&
			m_pObjectX->GetSigns() == false &&
			m_pObjectX->GetPowerUp() == false &&
			m_pObjectX->GetScoreBonus() == false)
		{
			CStardustX::Create(D3DXVECTOR3(-SPAWN_POS_X, 0.0f, -fPosZ), CStardustX::STARDUST_000_A);

			m_nSpawn = 0;
			m_nFrameCounter[9] = 0;
		}

		// ←アイテム
		if (m_nSpawn >= rand() / MAX_STARDUST_SPAWN &&
			m_nFrameCounter[10] >= NUM_STARDUST_FRAME_CNT &&
			m_pObjectX->GetSigns() == false &&
			m_pObjectX->GetPowerUp() == false &&
			m_pObjectX->GetScoreBonus() == false)
		{
			CStardustX::Create(D3DXVECTOR3(SPAWN_POS_X, 0.0f, fPosZ), CStardustX::STARDUST_000_B);

			m_nSpawn = 0;
			m_nFrameCounter[10] = 0;
		}
		if (m_nSpawn >= rand() / MAX_STARDUST_SPAWN &&
			m_nFrameCounter[11] >= NUM_STARDUST_FRAME_CNT &&
			m_pObjectX->GetSigns() == false &&
			m_pObjectX->GetPowerUp() == false &&
			m_pObjectX->GetScoreBonus() == false)
		{
			CStardustX::Create(D3DXVECTOR3(SPAWN_POS_X, 0.0f, -fPosZ), CStardustX::STARDUST_000_B);

			m_nSpawn = 0;
			m_nFrameCounter[11] = 0;
		}

		// 10コイン→
		if (m_nSpawn >= rand() / MAX_COIN10_SPAWN && m_nFrameCounter[12] >= NUM_COIN10_FRAME_CNT)
		{
			CCoin10X::Create(D3DXVECTOR3(-SPAWN_POS_X, 0.0f, fPosZ), CCoin10X::COIN10_000_A);

			m_nSpawn = 0;
			m_nFrameCounter[12] = 0;
		}
		if (m_nSpawn >= rand() / MAX_COIN10_SPAWN && m_nFrameCounter[13] >= NUM_COIN10_FRAME_CNT)
		{
			CCoin10X::Create(D3DXVECTOR3(-SPAWN_POS_X, 0.0f, -fPosZ), CCoin10X::COIN10_000_A);

			m_nSpawn = 0;
			m_nFrameCounter[13] = 0;
		}

		// ←10コイン
		if (m_nSpawn >= rand() / MAX_COIN10_SPAWN && m_nFrameCounter[14] >= NUM_COIN10_FRAME_CNT)
		{
			CCoin10X::Create(D3DXVECTOR3(SPAWN_POS_X, 0.0f, fPosZ), CCoin10X::COIN10_000_B);

			m_nSpawn = 0;
			m_nFrameCounter[14] = 0;
		}
		if (m_nSpawn >= rand() / MAX_COIN10_SPAWN && m_nFrameCounter[15] >= NUM_COIN10_FRAME_CNT)
		{
			CCoin10X::Create(D3DXVECTOR3(SPAWN_POS_X, 0.0f, -fPosZ), CCoin10X::COIN10_000_B);

			m_nSpawn = 0;
			m_nFrameCounter[15] = 0;
		}

#ifdef _DEBUG // Debug時のみ

		// 確認用
		// スコア加算(+1)
		if (pInputKeyboard->GetTrigger(DIK_1) == true)
		{
			// スコア加算
			CScore::AddScore(1);

			// SE
			pSound->PlaySoundA(CSound::SOUND_LABEL_SAMPLE_SE);
		}
		// スコア減算(-1)
		if (pInputKeyboard->GetTrigger(DIK_0) == true)
		{
			// スコア加算
			CScore::AddScore(-1);

			// SE
			pSound->PlaySoundA(CSound::SOUND_LABEL_SAMPLE_SE);
		}

		if (m_pObjectX->GetEnable() == false)
		{
			// デバッグ用プレイヤー復活
			if (pInputKeyboard->GetTrigger(DIK_NUMPADPLUS) == true)
			{// 10キーの+
				m_pObjectX = CObjectX::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			}
		}

		if (pInputKeyboard->GetTrigger(DIK_RETURN) || pInputJoypad->GetTrigger(pInputJoypad->JOYKEY_START) == true)
		{// 決定キー(ENTERキー)が押された
			CManager::SetMode(MODE_RESULT);
		}

#endif

#ifdef NDEBUG // Release時のみ

		if (m_pObjectX->GetEnable() == false)
		{
			if (m_nTransition <= 60 * 4)
			{
				m_nTransition++;
			}

			if (m_nTransition >= 60 * 4)
			{
				//if (pInputKeyboard->GetTrigger(DIK_RETURN) || pInputJoypad->GetTrigger(pInputJoypad->JOYKEY_START) == true)
				{// 決定キー(ENTERキー)が押された
					CManager::SetMode(MODE_RESULT);
				}
			}
		}

#endif

	}
}

//----------------------------------------
// 描画処理
//----------------------------------------
void CGame::Draw(void)
{
	/* ゲーム画面だけにある特別な描画があるなら記入する */
}

//----------------------------------------
// オブジェクトXの取得処理
//----------------------------------------
CObjectX* CGame::GetObjectX(void)
{
	return m_pObjectX;
}

//----------------------------------------
// ポーズの取得処理
//----------------------------------------
CPause* CGame::GetPause(void)
{
	return m_pPause;
}

//----------------------------------------
// デストロイプレイヤー処理
//----------------------------------------
void CGame::DestoryPlayer(void)
{
	//if (m_pObjectX->GetEnable() == true)
	//{
	//	m_pObjectX->SetEnable(false);
	//}

	m_pObjectX = nullptr;
}