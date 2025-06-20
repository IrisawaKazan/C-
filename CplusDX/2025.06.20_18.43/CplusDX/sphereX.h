////==============================================================
////
//// [sphereX.h]
//// Author: Irisawa Kazan
////
////==============================================================
//#ifndef _SPHEREX_H_ // このマクロ定義がされてなかったら
//#define _SPHEREX_H_ // 2重インクルード防止のマクロ定義
//
//#include"main.h"
//#include"objectX.h"
//
//// スフィアXクラス
//class CSphereX : public CObjectX
//{
//public:
//	CSphereX(int nPriority = 5);
//	~CSphereX();
//
//	static HRESULT Load(void);
//	static void Unload(void);
//
//	static CSphereX* Create(D3DXVECTOR3 pos);
//
//	HRESULT Init(D3DXVECTOR3 pos);
//	void Uninit(void);
//	void Update(void);
//	void Draw(void);
//
//	void SetPosition(/*const */D3DXVECTOR3 pos);
//	void SetRotation(/*const */D3DXVECTOR3 rot);
//
//private:
//	static LPDIRECT3DTEXTURE9 m_pTexture;
//	static LPD3DXMESH m_pMesh;      // メッシュ(頂点座標)へのポインタ
//	static LPD3DXBUFFER m_pBuffMat; // マテリアルへのポインタ
//	static DWORD m_dwNumMat;        // マテリアルの数
//
//	D3DXVECTOR3 m_move;
//	float m_fRotation; // ローテーション
//};
//
//#endif