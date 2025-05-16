//============================================
//
// ���z�֐�[enemy.cpp]
// Author: Irisawa Kazan
//
//============================================
#include"enemy.h"

// �ÓI�����o�ϐ��錾
int CEnemy::m_nNumAll = 0;                 // �G�̑���
int CEnemy::m_nNumHuman = 0;               // �l�^�G�̑���
int CEnemy::m_nNumBird = 0;                // ���^�G�̑���
CEnemy* CEnemy::m_apEnemy[MAX_ENEMY] = {}; // �I�u�W�F�N�g�ւ̃|�C���^

//------------------------------------
// �I�u�W�F�N�g�̐�������
//------------------------------------
CEnemy* CEnemy::Create(TYPE type)
{
	if (m_nNumAll < MAX_ENEMY)
	{
		int nIdx;

		nIdx = m_nNumAll; // ���݂̑�������

		switch (type)
		{
		case CEnemy::TYPE_HUMAN:
			m_apEnemy[nIdx] = new CEnemyHuman;
			break;

		case CEnemy::TYPE_BIRD:
			m_apEnemy[nIdx] = new CEnemyBird;
			break;
		}

		return m_apEnemy[nIdx];
	}

	return NULL;
}

//------------------------------------
// ���������I������
//------------------------------------
void CEnemy::RleaseAll(void)
{
	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (m_apEnemy[nCntEnemy] != NULL)
		{
			// �I������
			m_apEnemy[nCntEnemy]->Uinit();

			delete m_apEnemy[nCntEnemy];
			m_apEnemy[nCntEnemy] = NULL;
		}
	}
}

//------------------------------------
// �o�͏���
//------------------------------------
void CEnemy::OutputAll(void)
{
	int nNumAll = 0;      // �G�̑���
	int nNumAllHuman = 0; // �l�^�G�̑���
	int nNumAllBird = 0;  // ���^�G�̑���

	// �G�̑������擾
	nNumAll = CEnemy::GetNumAll();
	nNumAllHuman = CEnemy::GetNumHuman();
	nNumAllBird = CEnemy::GetNumBird();

	printf("\n* �o�� *\n");

	for (int nCntEnemy = 0; nCntEnemy < nNumAll; nCntEnemy++)
	{
		if (m_apEnemy[nCntEnemy] != NULL)
		{
			// �o�͏���
			m_apEnemy[nCntEnemy]->Output();
		}

		delete m_apEnemy[nCntEnemy];
		m_apEnemy[nCntEnemy] = NULL;
	}

	printf("\n�G�̑���: %d", nNumAll);
	printf("\n�l�^�G�̑���: %d", nNumAllHuman);
	printf("\n���^�G�̑���: %d", nNumAllBird);
}

//------------------------------------
// �G�̃R���X�g���N�^
//------------------------------------
CEnemy::CEnemy()
{
	m_nLife = 0;
	m_nAttack = 0;
	m_nNumAll++; // �G�̑����J�E���g�A�b�v
}

//------------------------------------
// �G�̃R���X�g���N�^(�I�[�o�[���[�h)
//------------------------------------
CEnemy::CEnemy(TYPE type)
{
	m_nLife = 0;
	m_nAttack = 0;
	m_nNumAll++; // �G�̑����J�E���g�A�b�v

	switch (type)
	{
	case TYPE_HUMAN:
		m_nNumHuman++;
		break;

	case TYPE_BIRD:
		m_nNumBird++;
		break;
	}
}

//------------------------------------
// �G�̃f�X�g���N�^
//------------------------------------
CEnemy::~CEnemy()
{

}

#if 0
//------------------------------------
// �G�̏���������
//------------------------------------
void CEnemy::Init(void)
{
	m_nLife = 100;
	m_nAttack = 50;
}
#endif // 0

//------------------------------------
// �G�̏I������
//------------------------------------
void CEnemy::Uinit(void)
{

}

//------------------------------------
// �G�̓��͏���
//------------------------------------
void CEnemy::Input(void)
{
	printf("\n�̗͂���� > ");
	scanf("%d", &m_nLife);
	printf("�U���͂���� > ");
	scanf("%d", &m_nAttack);
}

//------------------------------------
// �G�̏o�͏���
//------------------------------------
void CEnemy::Output(void)
{
	printf("\n�̗�: %d\n", m_nLife);
	printf("�U����: %d\n", m_nAttack);
}

//------------------------------------
// �l�^�G�̃R���X�g���N�^
//------------------------------------
CEnemyHuman::CEnemyHuman() : CEnemy(TYPE_HUMAN)
{
	m_nSpeedWalk = 0;
}

//------------------------------------
// �l�^�G�̃f�X�g���N�^
//------------------------------------
CEnemyHuman::~CEnemyHuman()
{

}

//------------------------------------
// �l�^�G�̏���������
//------------------------------------
void CEnemyHuman::Init(void)
{
	m_nLife = 100;
	m_nAttack = 50;

	m_nSpeedWalk = 30;
}

//------------------------------------
// �l�^�G�̏I������
//------------------------------------
void CEnemyHuman::Uinit(void)
{

}

//------------------------------------
// �l�^�G�̓��͏���
//------------------------------------
void CEnemyHuman::Input(void)
{
	printf("\n[�l�^�̓G]\n");
	CEnemy::Input();

	printf("������������� > ");
	scanf("%d", &m_nSpeedWalk);
}

//------------------------------------
// �l�^�G�̏o�͏���
//------------------------------------
void CEnemyHuman::Output(void)
{
	printf("\n[�l�^�̓G]");
	CEnemy::Output();

	printf("��������: %d\n", m_nSpeedWalk);
}

//------------------------------------
// ���^�G�̃R���X�g���N�^
//------------------------------------
CEnemyBird::CEnemyBird() : CEnemy(TYPE_BIRD)
{
	m_nSpeedFly = 0;
}

//------------------------------------
// ���^�G�̃f�X�g���N�^
//------------------------------------
CEnemyBird::~CEnemyBird()
{

}

//------------------------------------
// ���^�G�̏���������
//------------------------------------
void CEnemyBird::Init(void)
{
	m_nLife = 100;
	m_nAttack = 50;

	m_nSpeedFly = 40;
}

//------------------------------------
// ���^�G�̏I������
//------------------------------------
void CEnemyBird::Uinit(void)
{

}

//------------------------------------
// ���^�G�̓��͏���
//------------------------------------
void CEnemyBird::Input(void)
{
	printf("\n[���^�̓G]\n");
	CEnemy::Input();

	printf("��ԑ�������� > ");
	scanf("%d", &m_nSpeedFly);
}

//------------------------------------
// ���^�G�̏o�͏���
//------------------------------------
void CEnemyBird::Output(void)
{
	printf("\n[���^�̓G]");
	CEnemy::Output();

	printf("��ԑ���: %d\n", m_nSpeedFly);
}