//==============================================================
//
// [playerX.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _PLAYERX_H_ // ���̃}�N����`������ĂȂ�������
#define _PLAYERX_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"object.h"

// �}�N����`
#define MAX_PARTS (10)

// �O���錾
class CModel;

// �K�w�\���̃v���C���[�N���X
class CPlayerX : public CObject
{
public:
	CPlayerX();
	~CPlayerX();

	static CPlayerX* Create(D3DXVECTOR3 pos);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);

	D3DXVECTOR3 GetPos(void);

private:
	D3DXVECTOR3 m_pos;     // �ʒu
	D3DXVECTOR3 m_rot;     // ����
	D3DXMATRIX m_mtxWorld; // ���[���h�}�g���b�N�X

	CModel* m_apModel[MAX_PARTS]; // ���f��(�p�[�c)�ւ̃|�C���^
	int m_nNumModel;              // ���f��(�p�[�c)�̑���
};

#endif