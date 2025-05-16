//==============================================================
//
// [object2D.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _OBJECT2D_H_ // このマクロ定義がされてなかったら
#define _OBJECT2D_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object.h"

// オブジェクト2Dクラス
class CObject2D : public CObject
{
public:
	CObject2D();
	~CObject2D();

	static CObject2D* Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetPosition(D3DXVECTOR3 pos);
	//void SetRotation(D3DXVECTOR3 rot);

private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;
	D3DXVECTOR3 m_pos;
	//D3DXVECTOR3 m_rot;
};

#endif