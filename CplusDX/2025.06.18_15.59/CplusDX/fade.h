//==============================================================
//
// [fade.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _FADE_H_ // このマクロ定義がされてなかったら
#define _FADE_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"renderer.h"
//#include"object2D.h"

// フェードクラス
class CFade/* : CObject2D*/
{
public:
	// フェードの状態
	typedef enum
	{
		FADE_NONE = 0, // 何もしていない状態
		FADE_IN,       // フェードイン状態
		FADE_OUT,      // フェードアウト状態

		FADE_MAX
	}FADE;

	CFade();
	~CFade();

	void Init(CRenderer::MODE modeNext);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void Set(CRenderer::MODE modeNext);

	FADE Get(void);

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff; // 頂点バッファへのポインタ
	FADE m_fade;                        // フェードの状態
	CRenderer::MODE m_modeNext;         // 次の画面(モード)
	D3DXCOLOR m_color;                  // ポリゴン(フェード)の色
};

#endif