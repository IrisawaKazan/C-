//==============================================================
//
// [stardustX.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _STARDUSTX_H_ // ���̃}�N����`������ĂȂ�������
#define _STARDUSTX_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"object.h"
#include"manager.h"

// �}�N����`
#define STARDUST_UNINIT_POS (STARDUST_000_POS_X + 50.0f)

// �A�C�e��X�N���X
class CStardustX : public CObject
{
public:
	// �A�C�e��X�̎��
	typedef enum
	{
		STARDUST_NONE = 0,
		STARDUST_000_A, // ������
		STARDUST_000_B, // ������

		STARDUST_MAX
	}STARDUST;

	CStardustX(int nPriority = 3);
	~CStardustX();

	static CStardustX* Create(D3DXVECTOR3 pos, STARDUST type);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);
	void SetRotation(D3DXVECTOR3 rot);

	D3DXVECTOR3 GetPos(void);
	D3DXVECTOR3 GetRot(void);

	void SetType(STARDUST type);
	STARDUST GetType(void);

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
	STARDUST m_type;
	D3DXVECTOR3 m_vtxMin; // ���f���̍ŏ��l
	D3DXVECTOR3 m_vtxMax; // ���f���̍ő�l
};

#endif