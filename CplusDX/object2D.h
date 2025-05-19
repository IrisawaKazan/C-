//==============================================================
//
// [object2D.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _OBJECT2D_H_ // このマクロ定義がされてなかったら
#define _OBJECT2D_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object.h"

// マクロ定義
#define PLAYER_SPEED (0.1f) // プレイヤーの速さ

// オブジェクト2Dクラス
class CObject2D : public CObject
{
public:
	CObject2D();
	~CObject2D();

	static CObject2D* Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetPosition(D3DXVECTOR3 pos);
	//void SetRotation(D3DXVECTOR3 rot);
protected:
	LPDIRECT3DTEXTURE9 m_pTexture;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;
	D3DXVECTOR3 m_pos;
private:
	//LPDIRECT3DTEXTURE9 m_pTexture;
	//LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;
	//D3DXVECTOR3 m_pos;
	//D3DXVECTOR3 m_rot;
};

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

//// バックグラウンドクラス
//class CBackground : public CObject2D
//{
//public:
//	CBackground();
//	~CBackground();
//
//	static CBackground* Create(void);
//	HRESULT Init(void);
//	void Uninit(void);
//	void Update(void);
//	void Draw(void);
//	void SetPosition(D3DXVECTOR3 pos);
//
//private:
//};

#endif