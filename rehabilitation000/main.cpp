//==================================================
//
// [main.cpp]
// Irisawa Kazan
//
//==================================================
#include"main.h"
#include"enemy.h"

// ���Z�����̃e���v���[�g�֐�[�e���v���[�g�^ "T" ���`����]
template<class T> T Add(const T data0, const T data1)
{
	T answer;

	answer = data0 + data1;

	return answer;
}

//-------------------------------------
// ���C���֐�
//-------------------------------------
int main(void)
{
	/*int nData;
	int nData1;

	CEnemy *pEnemy = NULL; // �G�I�u�W�F�N�g�ւ̃|�C���^

	// �������m��
	pEnemy = new CEnemy;

	// ����������
	pEnemy->Init();

	// ���͏���
	pEnemy->Input();

	// �o�͏���
	pEnemy->Output();

	printf("\n�U���͂��ē��͂��Ă������� > ");
	scanf("%d", &nData);

	// �ݒ菈��
	pEnemy->SetAttack(nData);

	// �擾����
	nData1 = pEnemy->GetAttack();

	printf("\n�U���͂��ďo��: %d\n", nData1);

	//// �U���݂͂̂̓��͏���
	//pEnemy->AttackInput();

	//// �U���݂͂̂̏o�͏���
	//pEnemy->AttackOutput();

	// �I������
	pEnemy->Uninit();

	// ���������
	delete pEnemy;
	pEnemy = NULL;*/

	/*int aNum[2];

	for (int nCount = 0; nCount < 2; nCount++)
	{
		printf("%d�ڂ̐��l����͂��Ă������� > ", nCount + 1);
		scanf("%d", &aNum[nCount]);

		printf("\n");
	}

	printf("2�̐��l�̍��v: %d\n", aNum[0] + aNum[1]);*/

	/*float fNum[MAX_NUM];

	for (int nCount = 0; nCount < MAX_NUM; nCount++)
	{
		printf("%d�ڂ̐��l����͂��Ă������� > ", nCount + 1);
		scanf("%f", &fNum[nCount]);

		printf("\n");
	}

	printf("%d�̐��l�̍��v: %.1f\n", MAX_NUM, fNum[0] + fNum[1]);*/

	int nData0, nData1;

	printf("1�ڂ̐��l����� > ");
	scanf("%d", &nData0);
	printf("2�ڂ̐��l����� > ");
	scanf("%d", &nData1);

	printf("\n1�ڂ̐��l: %d\n", nData1);
	printf("\n2�ڂ̐��l: %d\n", nData0);

	// �L�[���͑҂�
	printf("\n*** �G���^�[�L�[�ŏI�� ***");
	rewind(stdin);
	getchar();
	return 0;
}