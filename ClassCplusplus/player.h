//========================================
//
// クラス・ファイル分割[player.h]
// Author: Irisawa Kazan	
//
//========================================
#ifndef _PLAYER_H_
#define _PLAYER_H_ // 2重インクルードの防止

#include"main.h"

// プレイヤークラスの定義
class CPlayer
{
public: // アクセス指定子(誰でも)
	CPlayer();         // コンストラクタ
	~CPlayer();        // デストラクタ
	void Init(void);   // 初期化処理
	void Uninit(void); // 終了処理
	void Input(void);  // 入力処理
	void Output(void); // 出力処理

private: // アクセス指定子(自分だけ)
	int m_nLife;       // 体力
	int m_nAttack;     // 攻撃力
	int m_nSpeed;      // 素早さ
};

#endif