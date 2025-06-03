//==============================================================
//
// [number.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _NUMBER_H_ // ���̃}�N����`������ĂȂ�������
#define _NUMBER_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"

// �i���o�[�N���X
class CNumber
{
public:
	CNumber();
	~CNumber();

	static CNumber* Create(D3DXVECTOR3 pos);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);      
	void Update(void);      
	void Draw(void);

private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;
	D3DXVECTOR3 m_pos;
	float m_fLength;
	float m_fAngle;
	float m_faUV;
	float m_fzUV;
	float m_fxSize;
	float m_fySize;
};

#endif