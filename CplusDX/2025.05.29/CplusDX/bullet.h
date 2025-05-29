//==============================================================
//
// [bullet.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _BULLET_H_ // ���̃}�N����`������ĂȂ�������
#define _BULLET_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"object2D.h"

// �}�N����`
#define BULLET_SPEED (5.0f)
#define MAX_BULLETTEX (5)

// �o���b�g�N���X
class CBullet : public CObject2D
{
public:
	typedef enum
	{
		BTYPE_NONE = 0,
		BTYPE_PLAYER, // �v���C���[
		BTYPE_ENEMY,  // �G�l�~�[

		ETYPE_MAX
	}BTYPE;

	CBullet(int nPriority = 4);
	~CBullet();

	static HRESULT Load(void);
	static void Unload(void);

	static CBullet* Create(D3DXVECTOR3 pos, float xsize, float ysize, BTYPE type);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);
	void SetSize(float xsize, float ysize);

	void SetType(BTYPE type);
	BTYPE GetType(void);

	bool CollisionEnemy(D3DXVECTOR3 pos);
	bool CollisionPlayer(D3DXVECTOR3 pos);

private:
	static LPDIRECT3DTEXTURE9 m_pTexture[MAX_BULLETTEX];
	D3DXVECTOR3 m_move;
	int m_nLife;        // ����
	BTYPE m_type;
};

#endif