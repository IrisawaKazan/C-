//========================================
//
// クラス・ファイル分割[process.h]
// Author: Irisawa Kazan	
//
//========================================
#ifndef _PROCESS_H_
#define _PROCESS_H_ // 2重インクルードの防止

#include"main.h"
#include"player.h"

// マクロ定義
#define MAX_PLAYER (5)

// プロセスクラスの定義
class CProcess
{
public: // アクセス指定子(誰でも)
	// モードの列挙型定義
	typedef enum
	{
		MODE_FINISH = 0, // 終了処理
		MODE_INPUT,      // 入力処理
		MODE_OUTPUT,     // 出力処理
		MODE_MAX
	}MODE;

	CProcess();            // コンストラクタ
	~CProcess();           // デストラクタ
	void Init(void);       // 初期化処理
	void Uninit(void);     // 終了処理
	void SelectMode(void); // 選択処理

private: // アクセス指定子(自分だけ)
	void Input(void);  // 入力処理
	void Output(void); // 出力処理

	CPlayer m_aPlayer[MAX_PLAYER];
	int m_nNumPlayer;
};

#endif