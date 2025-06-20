//==============================================================
//
// [renderer.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _RENDERER_H_ // このマクロ定義がされてなかったら
#define _RENDERER_H_ // 2重インクルード防止のマクロ定義

#include"main.h"

// レンダラークラス
class CRenderer
{
public:
	// 画面(モード)の種類
	typedef enum
	{
		MODE_TITLE = 0, // タイトル(最高スコア)画面
		MODE_GAME,      // ゲーム画面
		//MODE_RESULT,    // リザルト(ゲームオーバー, スコア)画面
		//MODE_PAUSE,     // ポーズ画面
		//MODE_TUTORIAL,  // チュートリアル画面

		MODE_MAX
	}MODE;

	CRenderer();
	~CRenderer();

	HRESULT Init(HWND hWnd, BOOL bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	LPDIRECT3DDEVICE9 GetDevice(void);

	//void SetMode(MODE mode);
	//MODE GetMode(void);

private:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pD3DDevice;
	static int m_nCntFPS;
	//MODE m_mode;
};

#endif