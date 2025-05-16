//==================================================
//
// [enemy.h]
// Irisawa Kazan
//
//==================================================
#ifndef _ENEMY_H_
#define _ENEMY_H_ // 2�d�C���N���[�h�̖h�~

#include"main.h"

// �G�l�~�[�N���X
class CEnemy
{
public:
	CEnemy();
	CEnemy(const int nAttackMax);
	~CEnemy();
	// ���Z�q�̃I�[�o�[���[�h
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
	int m_nLife;                     // �̗�
	int m_nAttack;                   // �U����
	int m_nSpeed;                    // �f����
	static int m_nAttackBase;        // ������
	const int m_nAttackMax;          // �ő�l
	static const int m_nAttackLinit; // ���E�n
};

#endif // !_ENEMY_H_