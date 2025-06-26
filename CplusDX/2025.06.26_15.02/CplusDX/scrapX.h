//==============================================================
//
// [scrapX.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _SCRAPX_H_ // ���̃}�N����`������ĂȂ�������
#define _SCRAPX_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"object.h"
#include"manager.h"

// �}�N����`
#define SCRAP_UNINIT_POS (SCRAP_000_POS_X + 50.0f)

// �G�l�~�[X�N���X
class CScrap : public CObject
{
public:
	// �G�l�~�[X�̎��
	typedef enum
	{
		SCRAP_NONE = 0,
		SCRAP_000_A, // �X�N���b�v��
		SCRAP_000_B, // ���X�N���b�v

		SCRAP_MAX
	}SCRAP;

	CScrap(int nPriority = 3);
	~CScrap();

	static CScrap* Create(D3DXVECTOR3 pos, SCRAP type);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);
	void SetRotation(D3DXVECTOR3 rot);

	D3DXVECTOR3 GetPos(void);
	D3DXVECTOR3 GetRot(void);

	void SetType(SCRAP type);
	SCRAP GetType(void);

	void SetVtxMin(D3DXVECTOR3 vtxMin);
	void SetVtxMax(D3DXVECTOR3 vtxMax);
	D3DXVECTOR3 GetVtxMin(void);
	D3DXVECTOR3 GetVtxMax(void);

	void Collision(void);

private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	LPD3DXMESH m_pMesh;      // ���b�V��(���_���W)�ւ̃|�C���^
	LPD3DXBUFFER m_pBuffMat; // �}�e���A���ւ̃|�C���^
	DWORD m_dwNumMat;        // �}�e���A���̐�
	D3DXVECTOR3 m_pos;       // �ʒu
	D3DXVECTOR3 m_rot;       // ����
	D3DXMATRIX m_mtxWorld;   // ���[���h�}�g���b�N�X

	float m_fRotation; // ���[�e�[�V����
	SCRAP m_type;
	D3DXVECTOR3 m_vtxMin; // ���f���̍ŏ��l
	D3DXVECTOR3 m_vtxMax; // ���f���̍ő�l
};

#endif