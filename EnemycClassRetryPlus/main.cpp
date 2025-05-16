//============================================
//
// ���z�֐�[main.cpp]
// Author: Irisawa Kazan
//
//============================================
#include"main.h"
#include"enemy.h"

// �v���g�^�C�v�錾
void Init(void);
void Uninit(void);
void Input(void);
void Output(void);

//------------------------------------
// ���C���֐�
//------------------------------------
int main(void)
{
	Init();

	Input();

	Output();

	Uninit();

	// �L�[���͑҂�
	printf("\n\n--- �G���^�[�L�[�ŏI�� ---");
	rewind(stdin);
	getchar();
	return 0;
}

//------------------------------------
// ����������
//------------------------------------
void Init(void)
{
	CEnemy::RleaseAll();
}

//------------------------------------
// �I���֐�
//------------------------------------
void Uninit(void)
{
	CEnemy::RleaseAll();
}

//------------------------------------
// ���͏���
//------------------------------------
void Input(void)
{
	CEnemy* pEnemy;

	CEnemy::TYPE type = CEnemy::TYPE_NONE;

	int nCount = 0;

	do
	{
		printf("[ ��������G�̎�ނ�I�� ]\n%d.�l�^\n%d.���^\n%d.�I��\n�ԍ������ > ", CEnemy::TYPE_HUMAN, CEnemy::TYPE_BIRD, CEnemy::TYPE_NONE);
		scanf("%d", &type);

		pEnemy = CEnemy::Create(type);

		if (pEnemy != NULL)
		{
			// ����������
			pEnemy->Init();

			// ���͏���
			pEnemy->Input();

			printf("\n");
		}

		nCount++;
	} while (type != 0 && nCount < MAX_ENEMY);
}

//------------------------------------
// �o�͏���
//------------------------------------
void Output(void)
{
	CEnemy::OutputAll();
}