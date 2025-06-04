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
class CPlayer;
class CBackground;
class CEnemy;
//class CSound;
class CScore;

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
	static CPlayer* GetPlayer(void);
	static CBackground* GetBackground(void);
	static CEnemy* GetEnemy(void);
	//static CSound* GetSound(void);
	static CScore* GetScore(void);

private:
	static CRenderer* m_pRenderer;
	static CInputKeyboard* m_pInputKeyboard;
	static CPlayer* m_pPlayer;
	static CBackground* m_pBackground;
	static CEnemy* m_pEnemy;
	//static CSound* m_pSound;
	static CScore* m_pScore;
};

#endif