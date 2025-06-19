//==============================================================
//
// [manager.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _MANAGER_H_ // このマクロ定義がされてなかったら
#define _MANAGER_H_ // 2重インクルード防止のマクロ定義

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

// マネージャクラス
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

private:
	static CRenderer* m_pRenderer;
	static CInputKeyboard* m_pInputKeyboard;
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

	bool m_bPause;
};

#endif