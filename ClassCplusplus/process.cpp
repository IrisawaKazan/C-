//========================================
//
// �N���X�E�t�@�C������[process.cpp]
// Author: Irisawa Kazan	
//
//========================================
#include"process.h"

//----------------------------
// �R���X�g���N�^
//----------------------------
CProcess::CProcess()
{
	m_nNumPlayer = 0;
}

//----------------------------
// �f�X�g���N�^
//----------------------------
CProcess::~CProcess()
{

}

//----------------------------
// ����������
//----------------------------
void CProcess::Init(void)
{
	for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		m_aPlayer[nCount].Init();
	}
}

//----------------------------
// �I������
//----------------------------
void CProcess::Uninit(void)
{
	for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		m_aPlayer[nCount].Uninit();
	}
}

//----------------------------
// �I������
//----------------------------
void CProcess::SelectMode(void)
{
	int nSelect;

	do
	{
		printf("��������ԍ����ȉ�����I��ł�������\n");
		printf("1.�f�[�^����\n");
		printf("2.�f�[�^�o��\n");
		printf("0.�I��\n\n");

		printf("��������ԍ� > ");
		scanf("%d", &nSelect);

		switch (nSelect)
		{
		case MODE_INPUT:
			Input();
			break;

		case MODE_OUTPUT:
			Output();
			break;

		case MODE_FINISH:
			break;
		}

		printf("\n");

	} while (nSelect != 0);
}

//----------------------------
// ���͏���
//----------------------------
void CProcess::Input(void)
{
	printf("�l������� > ");
	scanf("%d", &m_nNumPlayer);

	for (int nCount = 0; nCount < m_nNumPlayer; nCount++)
	{
		m_aPlayer[nCount].Input();
	}
}

//----------------------------
// �o�͏���
//----------------------------
void CProcess::Output(void)
{
	for (int nCount = 0; nCount < m_nNumPlayer; nCount++)
	{
		m_aPlayer[nCount].Output();
	}
}