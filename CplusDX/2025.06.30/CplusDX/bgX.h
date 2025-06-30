//==============================================================
//
// [bgX.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _BGX_H_ // このマクロ定義がされてなかったら
#define _BGX_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object.h"

// オブジェクトXクラス
class CBackgroundX : public CObject
{
public:
	CBackgroundX(int nPriority = 3);
	~CBackgroundX();

	static CBackgroundX* Create(D3DXVECTOR3 pos);

	HRESULT Init(D3DXVECTOR3 pos);
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

	float m_fRotation; // ローテーション
};

#endif