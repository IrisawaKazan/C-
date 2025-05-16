//========================================
//
// �N���X�E�t�@�C������[player.h]
// Author: Irisawa Kazan	
//
//========================================
#ifndef _PLAYER_H_
#define _PLAYER_H_ // 2�d�C���N���[�h�̖h�~

#include"main.h"

// �v���C���[�N���X�̒�`
class CPlayer
{
public: // �A�N�Z�X�w��q(�N�ł�)
	CPlayer();         // �R���X�g���N�^
	~CPlayer();        // �f�X�g���N�^
	void Init(void);   // ����������
	void Uninit(void); // �I������
	void Input(void);  // ���͏���
	void Output(void); // �o�͏���

private: // �A�N�Z�X�w��q(��������)
	int m_nLife;       // �̗�
	int m_nAttack;     // �U����
	int m_nSpeed;      // �f����
};

#endif