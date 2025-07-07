//==============================================================
//
// [manager.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _MANAGER_H_ // ���̃}�N����`������ĂȂ�������
#define _MANAGER_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

// �C���N���[�h
#include"main.h"
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
#include"zomchinX.h"
#include"stardustX.h"

// �}�N����`
#define MAX_SPAWN (20)              // �G�̗N����(�������������Əo�����ɂ����Ȃ�)
#define NUM_FRAME_CNT (120)         // ������ނ̓G���ǂꂾ���A�����ĕ�����
#define MAX_FRAMECOUNTER (10)       // �t���[���J�E���^�[�̐�
#define DEBRIS_000_POS_X (300.0f)   // DEBRIS_000���N���ꏊ
#define SCRAP_000_POS_X (1500.0f)   // SCRAP_000���N���ꏊ
#define ZOMCHIN_000_POS_X (3000.0f) // ZOMCHIN_000���N���ꏊ

// �}�l�[�W���N���X
class CManager
{
public:
	CManager();
	~CManager();

	HRESULT Init(HINSTANCE nInstance, HWND hWnds);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CRenderer* GetRenderer(void);
	static CInputKeyboard* GetInputKeyboard(void);
	static CInputMouse* GetInputMouse(void);
	static CInputJoypad* GetInputJoypad(void);
	static CSound* GetSound(void);
	static CCamera* GetCamera(void);
	static CLight* GetLight(void);
	static CDebugProc* GetDebugProc(void);

	static CPlayer* GetPlayer(void);
	static CBackground* GetBackground(void);
	static CEnemy* GetEnemy(void);
	static CScore* GetScore(void);
	static CTimer* GetTimer(void);
	static CEffect* GetEffect(void);
	static CPause* GetPause(void);

	static CObjectX* GetObjectX(void);

	static void DestoryPlayer(void) { m_pObjectX = nullptr; };

private:
	static CRenderer* m_pRenderer;
	static CInputKeyboard* m_pInputKeyboard;
	static CInputMouse* m_pInputMouse;
	static CInputJoypad* m_pInputJoypad;
	static CSound* m_pSound;
	static CCamera* m_pCamera;
	static CLight* m_pLight;
	static CDebugProc* m_pDebugProc;

	static CPlayer* m_pPlayer;
	static CBackground* m_pBackground;
	static CEnemy* m_pEnemy;
	static CScore* m_pScore;
	static CTimer* m_pTimer;
	static CEffect* m_pEffect;
	static CPause* m_pPause;

	static CObjectX* m_pObjectX;

	bool m_bPause;
	int m_nDebrisSpawn;
	int m_nFrameCounter[MAX_FRAMECOUNTER];
};

#endif