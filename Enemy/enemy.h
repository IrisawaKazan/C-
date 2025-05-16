//=======================================
//
// �G�l�~�[�N���X[enemy.h]
// Irisawa Kazan
//
//=======================================
#ifndef _ENEMY_H_
#define _ENEMY_H_ // 2�d�C���N���[�h�̖h�~

#include"main.h"

// �G�N���X�̒�`(��{�N���X)
class CEnemy
{
public: // �A�N�Z�X�w��q(�N�ł�)
	// �G�̎��
	typedef enum
	{
		TYPE_NONE = 0, // �Ȃ�
		TYPE_HUMAN,    // �l�^
		TYPE_BIRD,     // ���^
		TYPE_MAX
	}TYPE;
	CEnemy();          // �R���X�g���N�^
	~CEnemy();         // �f�X�g���N�^
	void Init(void);   // ����������
	void Uinit(void);  // �I������
	void Input(void);  // ���͏���
	void Output(void); // �o�͏���

private: // �A�N�Z�X�w��q(��������)
//protected: // �A�N�Z�X�w��q(�h���N���X�Ǝ�������) ���ő��Ɏg��Ȃ�
	int m_nLife;   // �̗�
	int m_nAttack; // �U��
};

// �l�^�G�N���X�̒�`(�h���N���X)
class CEnemyHuman : public CEnemy
{
public: // �A�N�Z�X�w��q(�N�ł�)
	CEnemyHuman();     // �R���X�g���N�^
	~CEnemyHuman();    // �f�X�g���N�^
	void Init(void);   // ����������
	void Uinit(void);  // �I������
	void Input(void);  // ���͏���
	void Output(void); // �o�͏���

private: // �A�N�Z�X�w��q(��������)
	int m_SpeedWalk;   // ��������
};

// ���^�G�N���X�̒�`(�h���N���X)
class CEnemyBird : public CEnemy
{
public: // �A�N�Z�X�w��q(�N�ł�)
	CEnemyBird();      // �R���X�g���N�^
	~CEnemyBird();     // �f�X�g���N�^
	void Init(void);   // ����������
	void Uinit(void);  // �I������
	void Input(void);  // ���͏���
	void Output(void); // �o�͏���

private: // �A�N�Z�X�w��q(��������)
	int m_SpeedFly;    // ��ԑ���
};

#endif