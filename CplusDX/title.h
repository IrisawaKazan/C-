//==============================================================
//
// [title.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _TITLE_H_ // このマクロ定義がされてなかったら
#define _TITLE_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"manager.h"

// 前方宣言
//class CObjectX;

// マクロ定義
#define MAX_PLAYER (4)                 // 再生プレイヤーの数
#define NUM_SEPLAY_FRAME_CNT (60 * 20) // 同じ種類のSEがどれだけ連続して再生されるか

// タイトル画面クラス
class CTitle : public CScene
{
public:
	CTitle();
	~CTitle();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	//static CObjectX* GetObjectX(void);
	//static void DestoryPlayer(void);

private:
	int m_nPlay;                // SEを再生する
	int m_nCounter[MAX_PLAYER]; // 多段で再生しないためのカウンター

	//static CObjectX* m_pObjectX;
};

#endif