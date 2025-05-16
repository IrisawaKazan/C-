//=======================================
//
// エネミークラス[enemy.h]
// Irisawa Kazan
//
//=======================================
#ifndef _ENEMY_H_
#define _ENEMY_H_ // 2重インクルードの防止

#include"main.h"

// 敵クラスの定義(基本クラス)
class CEnemy
{
public: // アクセス指定子(誰でも)
	// 敵の種類
	typedef enum
	{
		TYPE_NONE = 0, // なし
		TYPE_HUMAN,    // 人型
		TYPE_BIRD,     // 鳥型
		TYPE_MAX
	}TYPE;
	CEnemy();          // コンストラクタ
	~CEnemy();         // デストラクタ
	void Init(void);   // 初期化処理
	void Uinit(void);  // 終了処理
	void Input(void);  // 入力処理
	void Output(void); // 出力処理

private: // アクセス指定子(自分だけ)
//protected: // アクセス指定子(派生クラスと自分だけ) ※滅多に使わない
	int m_nLife;   // 体力
	int m_nAttack; // 攻撃
};

// 人型敵クラスの定義(派生クラス)
class CEnemyHuman : public CEnemy
{
public: // アクセス指定子(誰でも)
	CEnemyHuman();     // コンストラクタ
	~CEnemyHuman();    // デストラクタ
	void Init(void);   // 初期化処理
	void Uinit(void);  // 終了処理
	void Input(void);  // 入力処理
	void Output(void); // 出力処理

private: // アクセス指定子(自分だけ)
	int m_SpeedWalk;   // 歩く速さ
};

// 鳥型敵クラスの定義(派生クラス)
class CEnemyBird : public CEnemy
{
public: // アクセス指定子(誰でも)
	CEnemyBird();      // コンストラクタ
	~CEnemyBird();     // デストラクタ
	void Init(void);   // 初期化処理
	void Uinit(void);  // 終了処理
	void Input(void);  // 入力処理
	void Output(void); // 出力処理

private: // アクセス指定子(自分だけ)
	int m_SpeedFly;    // 飛ぶ速さ
};

#endif