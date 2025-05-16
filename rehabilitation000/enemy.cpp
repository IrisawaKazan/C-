//==================================================
//
// [enemy.cpp]
// Irisawa Kazan
//
//==================================================
#include"enemy.h"

// �ÓI�����o�ϐ��錾
int CEnemy::m_nAttackBase = 0;            // �����l
const int CEnemy::m_nAttackLinit = 10000; // ���E�l

//-------------------------------------
// �R���X�g���N�^
//-------------------------------------
CEnemy::CEnemy() : m_nAttackMax(1000)
{
	m_nLife = 0;
	m_nAttack = 0;
	m_nSpeed = 0;
}

//-------------------------------------
// �R���X�g���N�^(�I�[�o�[���[�h)
//-------------------------------------
CEnemy::CEnemy(const int nAttackMax) : m_nAttackMax(nAttackMax)
{
	m_nLife = 0;
	m_nAttack = 0;
	m_nSpeed = 0;
}

//-------------------------------------
// �f�X�g���N�^
//-------------------------------------
CEnemy::~CEnemy()
{

}

//-------------------------------------
// ���Z�̃I�[�o�[���[�h
//-------------------------------------
CEnemy CEnemy::operator+(const CEnemy& enemy)
{
	CEnemy enemyWk;

	enemyWk.m_nAttack = m_nAttack + enemy.m_nAttack;

	return enemyWk;
}

//-------------------------------------
// ����̃I�[�o�[���[�h
//-------------------------------------
CEnemy &CEnemy::operator=(const CEnemy& enemy)
{
	m_nAttack = enemy.m_nAttack;

	return *this;
}

//-------------------------------------
// �O�u�C���N�������g�̃I�[�o�[���[�h
//-------------------------------------
CEnemy& CEnemy::operator++(void)
{
	m_nAttack++;

	return *this;
}

//-------------------------------------
// ��u�C���N�������g�̃I�[�o�[���[�h
//-------------------------------------
CEnemy CEnemy::operator++(int)
{
	CEnemy enemyWk;

	enemyWk = *this;

	m_nAttack++;

	return enemyWk;
}

//-------------------------------------
// ����������
//-------------------------------------
void CEnemy::Init(void)
{
	m_nLife = 100;
	m_nAttack = 50;
	m_nSpeed = 20;
}

//-------------------------------------
// �I������
//-------------------------------------
void CEnemy::Uninit(void)
{

}

//-------------------------------------
// ���͏���
//-------------------------------------
void CEnemy::Input(void)
{
	printf("�̗͂���͂��Ă������� > ");
	scanf("%d", &m_nLife);
	printf("�U���͂���͂��Ă������� > ");
	scanf("%d", &m_nAttack);
	printf("�f��������͂��Ă������� > ");
	scanf("%d", &m_nSpeed);
}

//-------------------------------------
// �o�͏���
//-------------------------------------
void CEnemy::Output(void)
{
	printf("\n�̗�: %d\n", m_nLife);
	printf("�U����: %d\n", m_nAttack);
	printf("�f����: %d\n", m_nSpeed);
}

//-------------------------------------
// �U���͂̐ݒ菈��
//-------------------------------------
void CEnemy::SetAttack(const int nAttack)
{
	m_nAttack = nAttack;
}

//-------------------------------------
// �U���͂̎擾����
//-------------------------------------
int CEnemy::GetAttack(void) const
{
	return m_nAttack;
}

////-------------------------------------
//// �U���݂͂̂̓��͏���
////-------------------------------------
//void CEnemy::AttackInput(void)
//{
//	printf("\n�U���͂��ē��͂��Ă������� > ");
//	scanf("%d", &m_nAttack);
//}
//
//
////-------------------------------------
//// �U���݂͂̂̏o�͏���
////-------------------------------------
//void CEnemy::AttackOutput(void)
//{
//	printf("\n�U���͂��ďo�� > %d\n", m_nAttack);
//}