//==============================================================
//
// [debrisX.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _DEBRISX_H_ // このマクロ定義がされてなかったら
#define _DEBRISX_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object.h"
#include"manager.h"

// マクロ定義
#define DEBRIS_UNINIT_POS (DEBRIS_000_POS_X + 50.0f)

// エネミーXクラス
class CDebrisX : public CObject
{
public:
	// エネミーXの種類
	typedef enum
	{
		DEBRIS_NONE = 0,
		DEBRIS_000_A, // トゲトゲ→
		DEBRIS_000_B, // ←トゲトゲ

		DEBRIS_MAX
	}DEBRIS;

	CDebrisX(int nPriority = 3);
	~CDebrisX();

	static CDebrisX* Create(D3DXVECTOR3 pos, DEBRIS type);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);
	void SetRotation(D3DXVECTOR3 rot);
	void SetPositionOld(D3DXVECTOR3 posOld);
	void SetSize(D3DXVECTOR3 size);

	D3DXVECTOR3 GetPos(void);
	D3DXVECTOR3 GetRot(void);
	D3DXVECTOR3 GetPosOld(void);
	D3DXVECTOR3 GetSize(void);


	void SetType(DEBRIS type);
	DEBRIS GetType(void);

	void Collision(void);

private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	LPD3DXMESH m_pMesh;      // メッシュ(頂点座標)へのポインタ
	LPD3DXBUFFER m_pBuffMat; // マテリアルへのポインタ
	DWORD m_dwNumMat;        // マテリアルの数
	D3DXVECTOR3 m_pos;       // 位置
	D3DXVECTOR3 m_posOld;    // 前回の位置
	D3DXVECTOR3 m_rot;       // 向き
	D3DXMATRIX m_mtxWorld;   // ワールドマトリックス

	float m_fRotation;    // ローテーション
	D3DXVECTOR3 m_size;	  // 大きさ
	DEBRIS m_type;
	D3DXVECTOR3 m_vtxMin; // モデルの最小値
	D3DXVECTOR3 m_vtxMax; // モデルの最大値
};

#endif