//==============================================================
//
// [objectBillboard.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _OBJECTBILLBOARD_H_ // ���̃}�N����`������ĂȂ�������
#define _OBJECTBILLBOARD_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"object.h"

// �I�u�W�F�N�g�r���{�[�h�N���X
class CObjectBillboard : public CObject
{
public:
	CObjectBillboard(int nPriority = 3);
	~CObjectBillboard();

	static CObjectBillboard* Create(D3DXVECTOR3 pos);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);

	D3DXVECTOR3 GetPos(void);

private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;
	D3DXVECTOR3 m_pos;     // �ʒu
	D3DXVECTOR3 m_rot;     // ����
	D3DXMATRIX m_mtxWorld; // ���[���h�}�g���b�N�X
};

#endif