//==============================================================
//
// [coin10X.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _COIN10X_H_ // このマクロ定義がされてなかったら
#define _COIN10X_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object.h"
#include"manager.h"

// マクロ定義
#define COIN10_UNINIT_POS (COIN10_000_POS_X + 50.0f)

// 10コインXクラス
class CCoin10X : public CObject
{
public:
	// 10コインXの種類
	typedef enum
	{
		COIN10_NONE = 0,
		COIN10_000_A, // 星屑→
		COIN10_000_B, // ←星屑

		COIN10_MAX
	}COIN10;

	CCoin10X(int nPriority = 3);
	~CCoin10X();

	static CCoin10X* Create(D3DXVECTOR3 pos, COIN10 type);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);
	void SetRotation(D3DXVECTOR3 rot);

	D3DXVECTOR3 GetPos(void);
	D3DXVECTOR3 GetRot(void);

	void SetType(COIN10 type);
	COIN10 GetType(void);

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
	COIN10 m_type;
	D3DXVECTOR3 m_vtxMin; // モデルの最小値
	D3DXVECTOR3 m_vtxMax; // モデルの最大値
};

#endif