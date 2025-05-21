//==============================================================
//
// [player.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _PLAYER_H_ // このマクロ定義がされてなかったら
#define _PLAYER_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object.h"
#include"object2D.h"

// マクロ定義
#define PLAYER_SPEED (0.1f) // プレイヤーの速さ

// プレイヤークラス
class CPlayer : public CObject2D
{
public:
	CPlayer();
	~CPlayer();

	static CPlayer* Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetPosition(D3DXVECTOR3 pos);

private:
	int m_nCounterAnim; // アニメーションカウンター
	int m_nPatternAnim; // アニメーションパターンNo.
	D3DXVECTOR3 m_move;
};

#endif