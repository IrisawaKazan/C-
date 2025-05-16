//========================================
//
// �N���X�E�t�@�C������[player.cpp]
// Author: Irisawa Kazan	
//
//========================================
#include"player.h"

//----------------------------
// �R���X�g���N�^
//----------------------------
CPlayer::CPlayer()
{
	m_nLife = 0;
	m_nAttack = 0;
	m_nSpeed = 0;
}

//----------------------------
// �f�X�g���N�^
//----------------------------
CPlayer::~CPlayer()
{

}

//----------------------------
// ����������
//----------------------------
void CPlayer::Init(void)
{
	m_nLife = 0;
	m_nAttack = 0;
	m_nSpeed = 0;
}

//----------------------------
// �I������
//----------------------------
void CPlayer::Uninit(void)
{

}

//----------------------------
// ���͏���
//----------------------------
void CPlayer::Input(void)
{
	printf("�v���C���[�̗̑͂���� > ");
	scanf("%d", &m_nLife);
	printf("�v���C���[�̍U���͂���� > ");
	scanf("%d", &m_nAttack);
	printf("�v���C���[�̑f��������� > ");
	scanf("%d", &m_nSpeed);

	printf("\n");
}

//----------------------------
// �o�͏���
//----------------------------
void CPlayer::Output(void)
{
	printf("�v���C���[�̗̑�: %d\n", m_nLife);
	printf("�v���C���[�̍U����: %d\n", m_nAttack);
	printf("�v���C���[�̑f����: %d\n", m_nSpeed);

	printf("\n");
}