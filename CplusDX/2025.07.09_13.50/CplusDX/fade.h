//==============================================================
//
// [fade.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _FADE_H_ // ���̃}�N����`������ĂȂ�������
#define _FADE_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"renderer.h"
//#include"object2D.h"

// �t�F�[�h�N���X
class CFade/* : CObject2D*/
{
public:
	// �t�F�[�h�̏��
	typedef enum
	{
		FADE_NONE = 0, // �������Ă��Ȃ����
		FADE_IN,       // �t�F�[�h�C�����
		FADE_OUT,      // �t�F�[�h�A�E�g���

		FADE_MAX
	}FADE;

	CFade();
	~CFade();

	void Init(CRenderer::MODE modeNext);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void Set(CRenderer::MODE modeNext);

	FADE Get(void);

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff; // ���_�o�b�t�@�ւ̃|�C���^
	FADE m_fade;                        // �t�F�[�h�̏��
	CRenderer::MODE m_modeNext;         // ���̉��(���[�h)
	D3DXCOLOR m_color;                  // �|���S��(�t�F�[�h)�̐F
};

#endif