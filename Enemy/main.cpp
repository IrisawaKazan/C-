//=======================================
//
// �G�l�~�[�N���X[main.cpp]
// Irisawa Kazan
//
//=======================================
#include"main.h"
#include"enemy.h"

//----------------------------
// ���C���֐�
//----------------------------
int main(void)
{
	// �G
	/*CEnemy enemy; // �G�̃C���X�^���X�𐶐�

	// ����������
	enemy.Init();

	// ���͏���
	enemy.Input();

	printf("\n");

	// �o�͏���
	enemy.Output();

	// �I������
	enemy.Uinit();*/

	// �l�^�ƒ��^
	/*
	CEnemyHuman enemyhuman; // �l�^�G�̃C���X�^���X�𐶐�
	CEnemyBird enemybird;   // ���^�G�̃C���X�^���X�𐶐�

	// ����������
	enemyhuman.Init();
	enemybird.Init();

	// ���͏���
	enemyhuman.Input();
	printf("\n");
	enemybird.Input();

	printf("\n");

	// �o�͏���
	enemyhuman.Output();
	printf("\n");
	enemybird.Output();

	// �I������
	enemyhuman.Uinit();
	enemybird.Uinit();*/

	// �l�^�G
	CEnemyHuman* pEnemyHuman = NULL; // �l�^�G�N���X�̃|�C���^��錾
	// ���^�G
	CEnemyBird* pEnemyBird = NULL;   // ���^�G�N���X�̃|�C���^��錾

	CEnemy::TYPE type;

	int nSelect;
	int nNumEnemy;

	printf("��������G�̎�ނ�I��ł�������\n%d.�l�^\n%d.���^\n�ԍ� > ", CEnemy::TYPE_HUMAN, CEnemy::TYPE_BIRD);
	scanf("%d", &nSelect);
	printf("\n");

	printf("��������G�̐������ > ");
	scanf("%d", &nNumEnemy);

	switch (nSelect)
	{
	case CEnemy::TYPE_HUMAN:
		if (pEnemyHuman == NULL)
		{
			pEnemyHuman = new CEnemyHuman[nNumEnemy]; // �l�^�G�̃C���X�^���X�𐶐�

			if (pEnemyHuman != NULL)
			{
				for (int nCount = 0; nCount < nNumEnemy; nCount++)
				{
					// ����������
					(pEnemyHuman + nCount)->Init();

					// ���͏���
					(pEnemyHuman + nCount)->Input();
				}

				printf("\n");

				for (int nCount = 0; nCount < nNumEnemy; nCount++)
				{
					// �o�͏���
					(pEnemyHuman + nCount)->Output();

					// �I������
					(pEnemyHuman + nCount)->Uinit();
				}
				delete[] pEnemyHuman;
				pEnemyHuman = NULL;
			}
			else
			{
				printf("\n�G���[\n");
			}
		}
		break;

	case CEnemy::TYPE_BIRD:
		if (pEnemyBird == NULL)
		{
			pEnemyBird = new CEnemyBird[nNumEnemy]; // ���^�G�̃C���X�^���X�𐶐�

			if (pEnemyBird != NULL)
			{
				for (int nCount = 0; nCount < nNumEnemy; nCount++)
				{
					// ����������
					(pEnemyBird + nCount)->Init();

					// ���͏���
					(pEnemyBird + nCount)->Input();
				}

				printf("\n");

				for (int nCount = 0; nCount < nNumEnemy; nCount++)
				{
					// �o�͏���
					(pEnemyBird + nCount)->Output();

					// �I������
					(pEnemyBird + nCount)->Uinit();
				}
				delete[] pEnemyBird;
				pEnemyBird = NULL;
			}
			else
			{
				printf("�G���[");
			}
		}
		break;
	}

	// �L�[���͑҂�
	printf("\n\n--- �G���^�[�L�[�ŏI�� ---");
	rewind(stdin);
	getchar();
	return 0;
}