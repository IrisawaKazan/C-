//==============================================================
//
// [coin10X.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _COIN10X_H_ // ���̃}�N����`������ĂȂ�������
#define _COIN10X_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"object.h"
#include"manager.h"

// �}�N����`
#define COIN10_UNINIT_POS (COIN10_000_POS_X + 50.0f)

// 10�R�C��X�N���X
class CCoin10X : public CObject
{
public:
	// 10�R�C��X�̎��
	typedef enum
	{
		COIN10_NONE = 0,
		COIN10_000_A, // ������
		COIN10_000_B, // ������

		COIN10_MAX
	}COIN10;

	CCoin10X(int nPriority = 3);
	~CCoin10X();

	static CCoin10X* Create(D3DXVECTOR3 pos, COIN10 type);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);
	void SetRotation(D3DXVECTOR3 rot);

	D3DXVECTOR3 GetPos(void);
	D3DXVECTOR3 GetRot(void);

	void SetType(COIN10 type);
	COIN10 GetType(void);

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
	COIN10 m_type;
	D3DXVECTOR3 m_vtxMin; // ���f���̍ŏ��l
	D3DXVECTOR3 m_vtxMax; // ���f���̍ő�l
};

#endif