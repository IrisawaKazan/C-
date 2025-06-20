//==============================================================
//
// [renderer.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _RENDERER_H_ // ���̃}�N����`������ĂȂ�������
#define _RENDERER_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"

// �����_���[�N���X
class CRenderer
{
public:
	// ���(���[�h)�̎��
	typedef enum
	{
		MODE_TITLE = 0, // �^�C�g��(�ō��X�R�A)���
		MODE_GAME,      // �Q�[�����
		//MODE_RESULT,    // ���U���g(�Q�[���I�[�o�[, �X�R�A)���
		//MODE_PAUSE,     // �|�[�Y���
		//MODE_TUTORIAL,  // �`���[�g���A�����

		MODE_MAX
	}MODE;

	CRenderer();
	~CRenderer();

	HRESULT Init(HWND hWnd, BOOL bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	LPDIRECT3DDEVICE9 GetDevice(void);

	//void SetMode(MODE mode);
	//MODE GetMode(void);

private:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pD3DDevice;
	static int m_nCntFPS;
	//MODE m_mode;
};

#endif