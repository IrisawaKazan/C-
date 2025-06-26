//==============================================================
//
// [playerX.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _PLAYERX_H_ // このマクロ定義がされてなかったら
#define _PLAYERX_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object.h"

// マクロ定義
#define MAX_PARTS (10)

// 前方宣言
class CModel;

// 階層構造のプレイヤークラス
class CPlayerX : public CObject
{
public:
	CPlayerX();
	~CPlayerX();

	static CPlayerX* Create(D3DXVECTOR3 pos);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);

	D3DXVECTOR3 GetPos(void);

private:
	D3DXVECTOR3 m_pos;     // 位置
	D3DXVECTOR3 m_rot;     // 向き
	D3DXMATRIX m_mtxWorld; // ワールドマトリックス

	CModel* m_apModel[MAX_PARTS]; // モデル(パーツ)へのポインタ
	int m_nNumModel;              // モデル(パーツ)の総数
};

#endif