//=======================================
//
// �G�l�~�[�N���X[enemy.cpp]
// Irisawa Kazan
//
//=======================================
#include"enemy.h"

//----------------------------
// �G�N���X�̃R���X�g���N�^
//----------------------------
CEnemy::CEnemy()
{
	m_nLife = 0;
	m_nAttack = 0;
}

//----------------------------
// �G�N���X�̃f�X�g���N�^
//----------------------------
CEnemy::~CEnemy()
{

}

//----------------------------
// �G�N���X�̏���������
//----------------------------
void CEnemy::Init(void)
{
	m_nLife = 100;
	m_nAttack = 50;
}

//----------------------------
// �G�N���X�̏I������
//----------------------------
void CEnemy::Uinit(void)
{

}

//----------------------------
// �G�N���X�̓��͏���
//----------------------------
void CEnemy::Input(void)
{
	printf("�̗͂���� > ");
	scanf("%d", &m_nLife);
	printf("�U���͂���� > ");
	scanf("%d", &m_nAttack);
}

//----------------------------
// �G�N���X�̏o�͏���
//----------------------------
void CEnemy::Output(void)
{
	printf("�̗�: %d\n", m_nLife);
	printf("�U����: %d\n", m_nAttack);
}

//----------------------------
// �l�^�G�N���X�̃R���X�g���N�^
//----------------------------
CEnemyHuman::CEnemyHuman()
{
	m_SpeedWalk = 0;
}

//----------------------------
// �l�^�G�N���X�̃f�X�g���N�^
//----------------------------
CEnemyHuman::~CEnemyHuman()
{

}

//----------------------------
// �l�^�G�N���X�̏���������
//----------------------------
void CEnemyHuman::Init(void)
{
	//// private:�ł̓A�N�Z�X�ł��Ȃ�
	//m_nLife = 100;
	//m_nAttack = 50;

	CEnemy::Init(); // ��{�N���X�̃X�R�[�v���g�p���ă����o�֐����Ăяo��(private:�ŃA�N�Z�X�ł���)

	m_SpeedWalk = 30;
}

//----------------------------
// �l�^�G�N���X�̏I������
//----------------------------
void CEnemyHuman::Uinit(void)
{
	CEnemy::Uinit();
}

//----------------------------
// �l�^�G�N���X�̓��͏���
//----------------------------
void CEnemyHuman::Input(void)
{
	printf("< �l�^�G >\n");
	CEnemy::Input();

	printf("������������� > ");
	scanf("%d", &m_SpeedWalk);
}

//----------------------------
// �l�^�G�N���X�̏o�͏���
//----------------------------
void CEnemyHuman::Output(void)
{
	printf("< �l�^�G >\n");
	CEnemy::Output();

	printf("��������: %d\n", m_SpeedWalk);
}

//----------------------------
// ���^�G�N���X�̃R���X�g���N�^
//----------------------------
CEnemyBird::CEnemyBird()
{
	m_SpeedFly = 0;
}

//----------------------------
// ���^�G�N���X�̃f�X�g���N�^
//----------------------------
CEnemyBird::~CEnemyBird()
{

}

//----------------------------
// ���^�G�N���X�̏���������
//----------------------------
void CEnemyBird::Init(void)
{
	CEnemy::Init(); // ��{�N���X�̃X�R�[�v���g�p���ă����o�֐����Ăяo��

	m_SpeedFly = 30;
}

//----------------------------
// ���^�G�N���X�̏I������
//----------------------------
void CEnemyBird::Uinit(void)
{
	CEnemy::Uinit();
}

//----------------------------
// ���^�G�N���X�̓��͏���
//----------------------------
void CEnemyBird::Input(void)
{
	printf("< ���^�G >\n");
	CEnemy::Input();

	printf("��ԑ�������� > ");
	scanf("%d", &m_SpeedFly);
}

//----------------------------
// ���^�G�N���X�̏o�͏���
//----------------------------
void CEnemyBird::Output(void)
{
	printf("< ���^�G >\n");
	CEnemy::Output();

	printf("��ԑ���: %d\n", m_SpeedFly);
}