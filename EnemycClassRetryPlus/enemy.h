//============================================
//
// ���z�֐�[enemy.h]
// Author: Irisawa Kazan
//
//============================================
#ifndef _ENEMY_H_
#define _ENEMY_H_ // 2�d�C���N���[�h�̖h�~

#include"main.h"

#define MAX_ENEMY (3)

// �G�N���X(��{�N���X)
class CEnemy
{
public:
	// �G�̃^�C�v
	typedef enum
	{
		TYPE_NONE = 0, // �I��
		TYPE_HUMAN,    // �l�^
		TYPE_BIRD,     // ���^
		TYPE_MAX
	}TYPE;
	static CEnemy* Create(TYPE type);
	static void RleaseAll(void);
	static void OutputAll(void);

	CEnemy();                  // �f�t�H���g�R���X�g���N�^
	CEnemy(TYPE type);         // �I�[�o�[���[�h���ꂽ�R���X�g���N�^
	virtual ~CEnemy();         // �f�X�g���N�^(���z�֐�)

	virtual void Init(void) = 0;   // ����������(���z�֐�)
	virtual void Uinit(void) = 0;  // �I������(���z�֐�)
	virtual void Input(void) = 0;  // ���͏���(���z�֐�)
	virtual void Output(void) = 0; // �o�͏���(���z�֐�)
	static int GetNumAll(void) { return m_nNumAll; }
	static int GetNumHuman(void) { return m_nNumHuman; }
	static int GetNumBird(void) { return m_nNumBird; }

protected:
	int m_nLife;                         // �̗�
	int m_nAttack;                       // �U����

private:
	static int m_nNumAll;                // �G�̑���
	static int m_nNumHuman;              // �l�^�G�̑���
	static int m_nNumBird;               // ���^�G�̑���
	static CEnemy* m_apEnemy[MAX_ENEMY]; // �G�̃I�u�W�F�N�g�ւ̃|�C���^
};

// �l�^�G�̃N���X(�h���N���X)
class CEnemyHuman : public CEnemy
{
public:
	CEnemyHuman();     // �R���X�g���N�^
	~CEnemyHuman();    // �f�X�g���N�^

	void Init(void);   // ����������
	void Uinit(void);  // �I������
	void Input(void);  // ���͏���
	void Output(void); // �o�͏���

private:
	int m_nSpeedWalk;     // ��������
};

// ���^�G�̃N���X(�h���N���X)
class CEnemyBird : public CEnemy
{
public:
	CEnemyBird();      // �R���X�g���N�^
	~CEnemyBird();	   // �f�X�g���N�^

	void Init(void);   // ����������
	void Uinit(void);  // �I������
	void Input(void);  // ���͏���
	void Output(void); // �o�͏���

private:
	int m_nSpeedFly;      // ��ԑ���
};

#endif