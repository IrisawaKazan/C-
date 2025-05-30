//==============================================================
//
// [explosion.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _EXPLOSION_H_ // このマクロ定義がされてなかったら
#define _EXPLOSION_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object2D.h"

// マクロ定義


// エクスプロージョンクラス
class CExplosion : public CObject2D
{
public:
	typedef enum
	{
		EXPLOTYPE_NONE = 0,
		EXPLOTYPE_000, // 白
		EXPLOTYPE_001, // 黒
		EXPLOTYPE_002, // 赤

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