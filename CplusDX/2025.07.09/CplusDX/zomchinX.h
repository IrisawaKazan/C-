//==============================================================
//
// [zomchinX.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _ZOMCHINX_H_ // ���̃}�N����`������ĂȂ�������
#define _ZOMCHINX_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"object.h"
#include"manager.h"

// �}�N����`
#define ZOMCHIN_UNINIT_POS (ZOMCHIN_000_POS_X + 50.0f)

// �G�l�~�[X�N���X
class CZomchinX : public CObject
{
public:
	// ZomchinX�̎��
	typedef enum
	{
		ZOMCHIN_NONE = 0,
		ZOMCHIN_000_A, // �_��
		ZOMCHIN_000_B, // ���_

		ZOMCHIN_MAX
	}ZOMCHIN;

	CZomchinX(int nPriority = 3);
	~CZomchinX();

	static CZomchinX* Create(D3DXVECTOR3 pos, ZOMCHIN type);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);
	void SetRotation(D3DXVECTOR3 rot);

	D3DXVECTOR3 GetPos(void);
	D3DXVECTOR3 GetRot(void);

	void SetType(ZOMCHIN type);
	ZOMCHIN GetType(void);

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
	ZOMCHIN m_type;
	D3DXVECTOR3 m_vtxMin; // ���f���̍ŏ��l
	D3DXVECTOR3 m_vtxMax; // ���f���̍ő�l
};

#endif