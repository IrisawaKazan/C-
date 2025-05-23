//==============================================================
//
// [explosion.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _EXPLOSION_H_ // ���̃}�N����`������ĂȂ�������
#define _EXPLOSION_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"object2D.h"

// �G�N�X�v���[�W�����N���X
class CExplosion : public CObject2D
{
public:
	CExplosion();
	~CExplosion();

	static HRESULT Load(void);
	static void Unload(void);

	static CExplosion* Create(D3DXVECTOR3 pos, float xsize, float ysize);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);
	void SetSize(float xsize, float ysize);

private:
	static LPDIRECT3DTEXTURE9 m_pTexture;
};

#endif