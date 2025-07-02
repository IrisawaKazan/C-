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

	void ChangeTarget(D3DXVECTOR3 posV, D3DXVECTOR3 posR, D3DXVECTOR3 vecU);
	LPDIRECT3DTEXTURE9 GetTextureMT(void);

	//void SetMode(MODE mode);
	//MODE GetMode(void);

private:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pD3DDevice;
	static int m_nCntFPS;

	LPDIRECT3DTEXTURE9 m_pTextureMT; // �����_�����O�^�[�Q�b�g�p�e�N�X�`��
	LPDIRECT3DSURFACE9 m_pRenderMT;  // �e�N�X�`�������_�����O�p�C���^�[�t�F�[�X
	LPDIRECT3DSURFACE9 m_pZBuffMT;   // �e�N�X�`�������_�����O�pZ�o�b�t�@
	D3DVIEWPORT9 m_viewportMT;       // �e�N�X�`�������_�����O�p�r���[�|�[�g

	//MODE m_mode;
};

#endif