//==============================================================
//
// [objectX.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _OBJECTX_H_ // ���̃}�N����`������ĂȂ�������
#define _OBJECTX_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"object.h"

// �}�N����`
#define MAX_PMOVE (2.0f) // BOX�̑���

// �I�u�W�F�N�gX�N���X
class CObjectX : public CObject
{
public:
	CObjectX(int nPriority = 3);
	~CObjectX();

	static CObjectX* Create(D3DXVECTOR3 pos);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);

	D3DXVECTOR3 GetPos(void);

private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	LPD3DXMESH m_pMesh;      // ���b�V��(���_���W)�ւ̃|�C���^
	LPD3DXBUFFER m_pBuffMat; // �}�e���A���ւ̃|�C���^
	DWORD m_dwNumMat;        // �}�e���A���̐�
	D3DXVECTOR3 m_pos;       // �ʒu
	D3DXVECTOR3 m_rot;       // ����
	D3DXMATRIX m_mtxWorld;   // ���[���h�}�g���b�N�X

	int m_nCounterRotation; // ���[�e�[�V�����J�E���^�[
	int m_nPatternRotation; // ���[�e�[�V�����p�^�[��
};

#endif