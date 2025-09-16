//==============================================================
//
// [gameoverX.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _GAMEOVERX_H_ // このマクロ定義がされてなかったら
#define _GAMEOVERX_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object.h"

// ゲームオーバーXクラス
class CGameoverX : public CObject
{
public:
	CGameoverX(int nPriority = 3);
	~CGameoverX();

	static CGameoverX* Create(D3DXVECTOR3 pos);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);

	D3DXVECTOR3 GetPos(void);

private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	LPD3DXMESH m_pMesh;      // メッシュ(頂点座標)へのポインタ
	LPD3DXBUFFER m_pBuffMat; // マテリアルへのポインタ
	DWORD m_dwNumMat;        // マテリアルの数
	D3DXVECTOR3 m_pos;       // 位置
	D3DXVECTOR3 m_rot;       // 向き
	D3DXMATRIX m_mtxWorld;   // ワールドマトリックス

	int m_nCounter;          // 移動方向変換用のカウンター
};

#endif