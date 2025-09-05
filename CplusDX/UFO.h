//==============================================================
//
// [UFO.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _UFO_H_ // このマクロ定義がされてなかったら
#define _UFO_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object.h"

// UFOクラス
class CUfo : public CObject
{
public:
	// エネミーXの種類
	typedef enum
	{
		UFO_NONE = 0,
		UFO_000_A, // UFO↑
		UFO_000_B, // UFO↓

		UFO_MAX
	}UFO;

	CUfo(int nPriority = 3);
	~CUfo();

	static CUfo* Create(D3DXVECTOR3 pos, UFO type);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);

	D3DXVECTOR3 GetPos(void);

	void SetType(UFO type);
	UFO GetType(void);

private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	LPD3DXMESH m_pMesh;      // メッシュ(頂点座標)へのポインタ
	LPD3DXBUFFER m_pBuffMat; // マテリアルへのポインタ
	DWORD m_dwNumMat;        // マテリアルの数
	D3DXVECTOR3 m_pos;       // 位置
	D3DXVECTOR3 m_posOld;    // 前回の位置
	D3DXVECTOR3 m_rot;       // 向き
	D3DXMATRIX m_mtxWorld;   // ワールドマトリックス

	float m_fRotation; // ローテーション

	float m_fDiagonal; // 斜め移動

	UFO m_type;
};

#endif