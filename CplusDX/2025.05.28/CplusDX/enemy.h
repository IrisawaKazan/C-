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

// バレットクラス
class CEnemy : public CObject2D
{
public:
	CEnemy();
	~CEnemy();

	static HRESULT Load(void);
	static void Unload(void);

	static CEnemy* Create(D3DXVECTOR3 pos, float xsize, float ysize);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);
	void SetSize(float xsize, float ysize);

private:
	static LPDIRECT3DTEXTURE9 m_pTexture;
	D3DXVECTOR3 m_move;
	int m_nLife; // 寿命
};

#endif