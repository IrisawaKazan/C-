//==============================================================
//
// [effect.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _EFFECT_H_ // このマクロ定義がされてなかったら
#define _EFFECT_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object2D.h"

// エフェクトクラス
class CEffect : public CObject2D
{
	CEffect(int nPriority = 3);
	~CEffect();

	static HRESULT Load(void);
	static void Unload(void);

	static CEffect* Create(D3DXVECTOR3 pos, float xsize, float ysize);

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