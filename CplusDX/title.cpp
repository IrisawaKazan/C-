//==============================================================
//
// [title.h]
// Author: Irisawa Kazan
//
//==============================================================
#include"title.h"
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
#include"titleOBJ.h"
#include"game.h"
#include"titleEarthX.h"
#include"UFO.h"

// 静的メンバ変数宣言
//CObjectX* CTitle::m_pObjectX = nullptr;

//----------------------------------------
// コンストラクタ
//----------------------------------------
CTitle::CTitle() : CScene(CScene::MODE_TITLE)
{
	m_nPlay = NULL;

	for (int nCnt = 0; nCnt < MAX_PLAYER; nCnt++)
	{
		m_nCounter[nCnt] = NULL;
	}

	for (int nCnt = 0; nCnt < MAX_FRAMECOUNTER_F; nCnt++)
	{
		m_nFrameCounter[nCnt] = NULL;
	}

	m_nSpawnFloating = NULL;
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CTitle::~CTitle()
{

}

//----------------------------------------
// 初期化処理
//----------------------------------------
HRESULT CTitle::Init(void)
{
	//CObjectX* pObjectX;
	//pObjectX = CGame::GetObjectX();

	//if (pObjectX->GetEnable() == true)
	//{
	//	pObjectX->SetEnable(false);
	//}

	// タイトルオブジェクトの生成
	CTitleObjX::Create(D3DXVECTOR3(0.0f, 100.0f, 0.0f));

	// タイトルアースの生成
	CTitleEarthX::Create(D3DXVECTOR3(0.0f, 350.0f, -35.0f));

	// bgXの生成
	CBackgroundX::Create(D3DXVECTOR3(0.0f, -325.0f, 0.0f));

	//m_pObjectX = CObjectX::Create(D3DXVECTOR3(0.0f, 0.0f, 200.0f));

	// サウンドの取得
	CSound* pSound = CManager::GetSound();

	// BGM
	pSound->PlaySoundA(CSound::SOUND_LABEL_TITLE_BGM);

	return S_OK;
}

//----------------------------------------
// 終了処理
//----------------------------------------
void CTitle::Uninit(void)
{
	CObject::Release();
}

//----------------------------------------
// 更新処理
//----------------------------------------
void CTitle::Update(void)
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

	// ランダム再生
	m_nPlay++;

	// 多段で出ないように制限するカウンター
	for (int nCnt = 0; nCnt < MAX_PLAYER; nCnt++)
	{
		m_nCounter[nCnt]++;
	}

	// 現在の時刻を種として設定
	srand((unsigned int)time(nullptr));

	// ノイズ
	if (m_nPlay >= rand() / 20 && m_nCounter[0] >= NUM_SEPLAY_FRAME_CNT)
	{
		pSound->PlaySoundA(CSound::SOUND_LABEL_NOISE_SE);

		m_nPlay = 0;
		m_nCounter[0] = 0;
	}

	// 信号
	if (m_nPlay >= rand() / 20 && m_nCounter[1] >= NUM_SEPLAY_FRAME_CNT + 60 * 10)
	{
		pSound->PlaySoundA(CSound::SOUND_LABEL_MORSE_SE);

		m_nPlay = 0;
		m_nCounter[1] = 0;
	}

	m_nSpawnFloating++;

	float fPosX = (float)(rand() % 500/* 出てくる範囲 */);

	// 現在の時刻を種として設定
	srand((unsigned int)time(nullptr));

	// 多段で出ないように制限するカウンター
	for (int nCnt = 0; nCnt < MAX_FRAMECOUNTER_F; nCnt++)
	{
		m_nFrameCounter[nCnt]++;
	}

	// 背景の浮遊物
	// UFO↑
	if (m_nSpawnFloating >= rand() / MAX_SPAWN_FLOAT && m_nFrameCounter[0] >= NUM_FRAME_CNT)
	{
		CUfo::Create(D3DXVECTOR3(fPosX, -50.0f, -SPAWN_POS_Z), CUfo::UFO_000_A);

		m_nSpawnFloating = 0;
		m_nFrameCounter[0] = 0;
	}
	if (m_nSpawnFloating >= rand() / MAX_SPAWN_FLOAT && m_nFrameCounter[1] >= NUM_FRAME_CNT)
	{
		CUfo::Create(D3DXVECTOR3(-fPosX, -50.0f, -SPAWN_POS_Z), CUfo::UFO_000_A);

		m_nSpawnFloating = 0;
		m_nFrameCounter[1] = 0;
	}

	// UFO↓
	if (m_nSpawnFloating >= rand() / MAX_SPAWN_FLOAT && m_nFrameCounter[2] >= NUM_FRAME_CNT)
	{
		CUfo::Create(D3DXVECTOR3(fPosX, -50.0f, SPAWN_POS_Z), CUfo::UFO_000_B);

		m_nSpawnFloating = 0;
		m_nFrameCounter[2] = 0;
	}
	if (m_nSpawnFloating >= rand() / MAX_SPAWN_FLOAT && m_nFrameCounter[3] >= NUM_FRAME_CNT)
	{
		CUfo::Create(D3DXVECTOR3(-fPosX, -50.0f, SPAWN_POS_Z), CUfo::UFO_000_B);

		m_nSpawnFloating = 0;
		m_nFrameCounter[3] = 0;
	}

	if (pInputKeyboard->GetTrigger(DIK_RETURN) || pInputJoypad->GetTrigger(pInputJoypad->JOYKEY_START) || pInputMouse->GetTrigger(pInputMouse->MOUSE_LEFTBUTTON) == true == true)
	{// 決定キー(ENTERキー)が押された
		CManager::SetMode(MODE_TUTORIAL);
	}
}

//----------------------------------------
// 描画処理
//----------------------------------------
void CTitle::Draw(void)
{

}

//CObjectX* CTitle::GetObjectX(void)
//{
//	return m_pObjectX;
//}
//
////----------------------------------------
//// デストロイプレイヤー処理
////----------------------------------------
//void CTitle::DestoryPlayer(void)
//{
//	//if (m_pObjectX->GetEnable() == true)
//	//{
//	//	m_pObjectX->SetEnable(false);
//	//}
//
//	m_pObjectX = nullptr;
//}