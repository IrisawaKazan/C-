//==============================================================
//
// [model.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _MODEL_H_ // ���̃}�N����`������ĂȂ�������
#define _MODEL_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"

// ���f���N���X
class CModel
{
public:
	CModel();
	~CModel();

	static CModel* Create(D3DXVECTOR3 pos);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetParent(CModel* pModel);
	D3DXMATRIX GetMtxWorld(void);

private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	LPD3DXMESH m_pMesh;      // ���b�V��(���_���W)�ւ̃|�C���^
	LPD3DXBUFFER m_pBuffMat; // �}�e���A���ւ̃|�C���^
	DWORD m_dwNumMat;        // �}�e���A���̐�
	D3DXVECTOR3 m_pos;       // �ʒu
	D3DXVECTOR3 m_rot;       // ����
	D3DXMATRIX m_mtxWorld;   // ���[���h�}�g���b�N�X
	CModel* m_pParent;       // �e���f���ւ̃|�C���^
};

#endif