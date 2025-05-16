//========================================
//
// �N���X�E�t�@�C������[process.h]
// Author: Irisawa Kazan	
//
//========================================
#ifndef _PROCESS_H_
#define _PROCESS_H_ // 2�d�C���N���[�h�̖h�~

#include"main.h"
#include"player.h"

// �}�N����`
#define MAX_PLAYER (5)

// �v���Z�X�N���X�̒�`
class CProcess
{
public: // �A�N�Z�X�w��q(�N�ł�)
	// ���[�h�̗񋓌^��`
	typedef enum
	{
		MODE_FINISH = 0, // �I������
		MODE_INPUT,      // ���͏���
		MODE_OUTPUT,     // �o�͏���
		MODE_MAX
	}MODE;

	CProcess();            // �R���X�g���N�^
	~CProcess();           // �f�X�g���N�^
	void Init(void);       // ����������
	void Uninit(void);     // �I������
	void SelectMode(void); // �I������

private: // �A�N�Z�X�w��q(��������)
	void Input(void);  // ���͏���
	void Output(void); // �o�͏���

	CPlayer m_aPlayer[MAX_PLAYER];
	int m_nNumPlayer;
};

#endif