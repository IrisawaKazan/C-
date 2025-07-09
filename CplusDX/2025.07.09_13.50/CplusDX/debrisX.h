//==============================================================
//
// [debrisX.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _DEBRISX_H_ // ���̃}�N����`������ĂȂ�������
#define _DEBRISX_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"object.h"
#include"manager.h"

// �}�N����`
#define DEBRIS_UNINIT_POS (DEBRIS_000_POS_X + 50.0f)

// �G�l�~�[X�N���X
class CDebrisX : public CObject
{
public:
	// �G�l�~�[X�̎��
	typedef enum
	{
		DEBRIS_NONE = 0,
		DEBRIS_000_A, // �g�Q�g�Q��
		DEBRIS_000_B, // ���g�Q�g�Q

		DEBRIS_MAX
	}DEBRIS;

	CDebrisX(int nPriority = 3);
	~CDebrisX();

	static CDebrisX* Create(D3DXVECTOR3 pos, DEBRIS type);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);
	void SetRotation(D3DXVECTOR3 rot);
	void SetPositionOld(D3DXVECTOR3 posOld);
	void SetSize(D3DXVECTOR3 size);

	D3DXVECTOR3 GetPos(void);
	D3DXVECTOR3 GetRot(void);
	D3DXVECTOR3 GetPosOld(void);
	D3DXVECTOR3 GetSize(void);


	void SetType(DEBRIS type);
	DEBRIS GetType(void);

	void Collision(void);

private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	LPD3DXMESH m_pMesh;      // ���b�V��(���_���W)�ւ̃|�C���^
	LPD3DXBUFFER m_pBuffMat; // �}�e���A���ւ̃|�C���^
	DWORD m_dwNumMat;        // �}�e���A���̐�
	D3DXVECTOR3 m_pos;       // �ʒu
	D3DXVECTOR3 m_posOld;    // �O��̈ʒu
	D3DXVECTOR3 m_rot;       // ����
	D3DXMATRIX m_mtxWorld;   // ���[���h�}�g���b�N�X

	float m_fRotation;    // ���[�e�[�V����
	D3DXVECTOR3 m_size;	  // �傫��
	DEBRIS m_type;
	D3DXVECTOR3 m_vtxMin; // ���f���̍ŏ��l
	D3DXVECTOR3 m_vtxMax; // ���f���̍ő�l
};

#endif