//==============================================================
//
// [bullet.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _BULLET_H_ // ���̃}�N����`������ĂȂ�������
#define _BULLET_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"object.h"
#include"object2D.h"

// �}�N����`
#define BULLET_SPEED (0.1f)

// �o���b�g�N���X
class CBullet : public CObject2D
{
public:
	CBullet();
	~CBullet();

	static HRESULT Load(void);
	static void Unload(void);
	static CBullet* Create(D3DXVECTOR3 pos, float xsize, float ysize);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetPosition(D3DXVECTOR3 pos);
	void SetSize(float xsize, float ysize);

private:
	static LPDIRECT3DTEXTURE9 m_pTexture;
	D3DXVECTOR3 m_move;
	int m_nLife;        // ����
};

#endif