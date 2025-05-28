//==============================================================
//
// [enemy.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _ENEMY_H_ // このマクロ定義がされてなかったら
#define _ENEMY_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object2D.h"

// マクロ定義
#define MAX_ENEMYTEX (5)

// エネミークラス
class CEnemy : public CObject2D
{
public:
	typedef enum
	{
		ETYPE_NONE = 0,
		ETYPE_000,
		ETYPE_001,

		ETYPE_MAX
	}ETYPE;

	CEnemy(int nPriority = 3);
	~CEnemy();

	static HRESULT Load(void);
	static void Unload(void);

	static CEnemy* Create(D3DXVECTOR3 pos, float xsize, float ysize, ETYPE type);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);
	void SetSize(float xsize, float ysize);

	void SetType(ETYPE type);
	ETYPE GetType(void);

private:
	static LPDIRECT3DTEXTURE9 m_pTexture[MAX_ENEMYTEX];
	D3DXVECTOR3 m_move;
	int m_nLife; // 寿命
	ETYPE m_type;
};

#endif