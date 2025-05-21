//==============================================================
//
// [player.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _PLAYER_H_ // ���̃}�N����`������ĂȂ�������
#define _PLAYER_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"object2D.h"

// �}�N����`
#define PLAYER_SPEED (0.1f) // �v���C���[�̑���

// �v���C���[�N���X
class CPlayer : public CObject2D
{
public:
	CPlayer();
	~CPlayer();

	static HRESULT Load(void);
	static void Unload(void);
	static CPlayer* Create(D3DXVECTOR3 pos);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetPosition(/*const */D3DXVECTOR3 pos);

private:
	static LPDIRECT3DTEXTURE9 m_pTexture;
	D3DXVECTOR3 m_move;
};

#endif