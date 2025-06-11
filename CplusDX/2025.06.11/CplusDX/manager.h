//==============================================================
//
// [manager.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _MANAGER_H_ // このマクロ定義がされてなかったら
#define _MANAGER_H_ // 2重インクルード防止のマクロ定義

#include"main.h"

// 前方宣言
class CRenderer;
class CInputKeyboard;
class CSound;
class CCamera;
class CLight;
class CDebugProc;

class CPlayer;
class CBackground;
class CEnemy;
class CScore;
class CTimer;
class CEffect;

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
};

#endif