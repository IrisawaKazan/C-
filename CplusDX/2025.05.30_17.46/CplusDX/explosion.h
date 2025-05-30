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

// �}�N����`


// �G�N�X�v���[�W�����N���X
class CExplosion : public CObject2D
{
public:
	typedef enum
	{
		EXPLOTYPE_NONE = 0,
		EXPLOTYPE_000, // ��
		EXPLOTYPE_001, // ��
		EXPLOTYPE_002, // ��

		EXPLOTYPE_MAX
	}EXPLOTYPE;

	CExplosion(int nPriority = 3);
	~CExplosion();

	static HRESULT Load(void);
	static void Unload(void);

	static CExplosion* Create(D3DXVECTOR3 pos, float xsize, float ysize, EXPLOTYPE type);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);
	void SetSize(float xsize, float ysize);

private:
	static LPDIRECT3DTEXTURE9 m_pTexture[EXPLOTYPE_MAX];
};

#endif