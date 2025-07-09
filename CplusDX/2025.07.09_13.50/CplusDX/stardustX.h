//==============================================================
//
// [stardustX.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _STARDUSTX_H_ // このマクロ定義がされてなかったら
#define _STARDUSTX_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object.h"
#include"manager.h"

// マクロ定義
#define STARDUST_UNINIT_POS (STARDUST_000_POS_X + 50.0f)

// アイテムXクラス
class CStardustX : public CObject
{
public:
	// アイテムXの種類
	typedef enum
	{
		STARDUST_NONE = 0,
		STARDUST_000_A, // 星屑→
		STARDUST_000_B, // ←星屑

		STARDUST_MAX
	}STARDUST;

	CStardustX(int nPriority = 3);
	~CStardustX();

	static CStardustX* Create(D3DXVECTOR3 pos, STARDUST type);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);
	void SetRotation(D3DXVECTOR3 rot);

	D3DXVECTOR3 GetPos(void);
	D3DXVECTOR3 GetRot(void);

	void SetType(STARDUST type);
	STARDUST GetType(void);

	void Collision(void);

private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	LPD3DXMESH m_pMesh;      // メッシュ(頂点座標)へのポインタ
	LPD3DXBUFFER m_pBuffMat; // マテリアルへのポインタ
	DWORD m_dwNumMat;        // マテリアルの数
	D3DXVECTOR3 m_pos;       // 位置
	D3DXVECTOR3 m_rot;       // 向き
	D3DXMATRIX m_mtxWorld;   // ワールドマトリックス

	float m_fRotation; // ローテーション
	STARDUST m_type;
	D3DXVECTOR3 m_vtxMin; // モデルの最小値
	D3DXVECTOR3 m_vtxMax; // モデルの最大値
};

#endif