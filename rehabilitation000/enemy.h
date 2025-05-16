//==================================================
//
// [enemy.h]
// Irisawa Kazan
//
//==================================================
#ifndef _ENEMY_H_
#define _ENEMY_H_ // 2重インクルードの防止

#include"main.h"

// エネミークラス
class CEnemy
{
public:
	CEnemy();
	CEnemy(const int nAttackMax);
	~CEnemy();
	// 演算子のオーバーロード
	CEnemy operator + (const CEnemy& enemy);
	CEnemy& operator= (const CEnemy & enemy);
	CEnemy& operator++(void);
	CEnemy operator++(int);
	void Init(void);
	void Uninit(void);
	void Input(void);
	void Output(void);
	void SetAttack(const int nAttack);
	int GetAttack(void) const;
	//void AttackInput(void);
	//void AttackOutput(void);
private:
	int m_nLife;                     // 体力
	int m_nAttack;                   // 攻撃力
	int m_nSpeed;                    // 素早さ
	static int m_nAttackBase;        // 初期化
	const int m_nAttackMax;          // 最大値
	static const int m_nAttackLinit; // 限界地
};

#endif // !_ENEMY_H_