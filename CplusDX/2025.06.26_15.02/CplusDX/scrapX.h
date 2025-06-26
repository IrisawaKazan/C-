//==============================================================
//
// [scrapX.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _SCRAPX_H_ // このマクロ定義がされてなかったら
#define _SCRAPX_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object.h"
#include"manager.h"

// マクロ定義
#define SCRAP_UNINIT_POS (SCRAP_000_POS_X + 50.0f)

// エネミーXクラス
class CScrap : public CObject
{
public:
	// エネミーXの種類
	typedef enum
	{
		SCRAP_NONE = 0,
		SCRAP_000_A, // スクラップ→
		SCRAP_000_B, // ←スクラップ

		SCRAP_MAX
	}SCRAP;

	CScrap(int nPriority = 3);
	~CScrap();

	static CScrap* Create(D3DXVECTOR3 pos, SCRAP type);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);
	void SetRotation(D3DXVECTOR3 rot);

	D3DXVECTOR3 GetPos(void);
	D3DXVECTOR3 GetRot(void);

	void SetType(SCRAP type);
	SCRAP GetType(void);

	void SetVtxMin(D3DXVECTOR3 vtxMin);
	void SetVtxMax(D3DXVECTOR3 vtxMax);
	D3DXVECTOR3 GetVtxMin(void);
	D3DXVECTOR3 GetVtxMax(void);

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
	SCRAP m_type;
	D3DXVECTOR3 m_vtxMin; // モデルの最小値
	D3DXVECTOR3 m_vtxMax; // モデルの最大値
};

#endif