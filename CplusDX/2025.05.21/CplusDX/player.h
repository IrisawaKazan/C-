//==============================================================
//
// [player.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _PLAYER_H_ // このマクロ定義がされてなかったら
#define _PLAYER_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object2D.h"

// マクロ定義
#define PLAYER_SPEED (0.1f) // プレイヤーの速さ

// プレイヤークラス
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