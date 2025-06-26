//==============================================================
//
// [deadzoneX.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _DEADZONEX_H_ // ���̃}�N����`������ĂȂ�������
#define _DEADZONEX_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"object.h"

// �f�b�h�]�[��X�N���X
class CDeadzoneX : public CObject
{
public:
	CDeadzoneX(int nPriority = 3);
	~CDeadzoneX();

	static CDeadzoneX* Create(D3DXVECTOR3 pos);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);
	void SetRotation(D3DXVECTOR3 rot);

	D3DXVECTOR3 GetPos(void);
	D3DXVECTOR3 GetRot(void);

	void SetVtxMin(D3DXVECTOR3 vtxMin);
	void SetVtxMax(D3DXVECTOR3 vtxMax);
	D3DXVECTOR3 GetVtxMin(void);
	D3DXVECTOR3 GetVtxMax(void);

	static CDeadzoneX* Collision(void);

private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	LPD3DXMESH m_pMesh;      // ���b�V��(���_���W)�ւ̃|�C���^
	LPD3DXBUFFER m_pBuffMat; // �}�e���A���ւ̃|�C���^
	DWORD m_dwNumMat;        // �}�e���A���̐�
	D3DXVECTOR3 m_pos;       // �ʒu
	D3DXVECTOR3 m_rot;       // ����
	D3DXMATRIX m_mtxWorld;   // ���[���h�}�g���b�N�X

	D3DXVECTOR3 m_vtxMin; // ���f���̍ŏ��l
	D3DXVECTOR3 m_vtxMax; // ���f���̍ő�l

	float m_fRotation; // ���[�e�[�V����
};

#endif