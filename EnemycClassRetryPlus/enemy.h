//============================================
//
// 仮想関数[enemy.h]
// Author: Irisawa Kazan
//
//============================================
#ifndef _ENEMY_H_
#define _ENEMY_H_ // 2重インクルードの防止

#include"main.h"

#define MAX_ENEMY (3)

// 敵クラス(基本クラス)
class CEnemy
{
public:
	// 敵のタイプ
	typedef enum
	{
		TYPE_NONE = 0, // 終了
		TYPE_HUMAN,    // 人型
		TYPE_BIRD,     // 鳥型
		TYPE_MAX
	}TYPE;
	static CEnemy* Create(TYPE type);
	static void RleaseAll(void);
	static void OutputAll(void);

	CEnemy();                  // デフォルトコンストラクタ
	CEnemy(TYPE type);         // オーバーロードされたコンストラクタ
	virtual ~CEnemy();         // デストラクタ(仮想関数)

	virtual void Init(void) = 0;   // 初期化処理(仮想関数)
	virtual void Uinit(void) = 0;  // 終了処理(仮想関数)
	virtual void Input(void) = 0;  // 入力処理(仮想関数)
	virtual void Output(void) = 0; // 出力処理(仮想関数)
	static int GetNumAll(void) { return m_nNumAll; }
	static int GetNumHuman(void) { return m_nNumHuman; }
	static int GetNumBird(void) { return m_nNumBird; }

protected:
	int m_nLife;                         // 体力
	int m_nAttack;                       // 攻撃力

private:
	static int m_nNumAll;                // 敵の総数
	static int m_nNumHuman;              // 人型敵の総数
	static int m_nNumBird;               // 鳥型敵の総数
	static CEnemy* m_apEnemy[MAX_ENEMY]; // 敵のオブジェクトへのポインタ
};

// 人型敵のクラス(派生クラス)
class CEnemyHuman : public CEnemy
{
public:
	CEnemyHuman();     // コンストラクタ
	~CEnemyHuman();    // デストラクタ

	void Init(void);   // 初期化処理
	void Uinit(void);  // 終了処理
	void Input(void);  // 入力処理
	void Output(void); // 出力処理

private:
	int m_nSpeedWalk;     // 歩く速さ
};

// 鳥型敵のクラス(派生クラス)
class CEnemyBird : public CEnemy
{
public:
	CEnemyBird();      // コンストラクタ
	~CEnemyBird();	   // デストラクタ

	void Init(void);   // 初期化処理
	void Uinit(void);  // 終了処理
	void Input(void);  // 入力処理
	void Output(void); // 出力処理

private:
	int m_nSpeedFly;      // 飛ぶ速さ
};

#endif