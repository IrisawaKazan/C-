//==============================================================
//
// [score.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _SCORE_H_ // このマクロ定義がされてなかったら
#define _SCORE_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object.h"

// 前方宣言
class CNumber;

// マクロ定義
#define MAX_SCORE (8)

// スコアクラス
class CScore : public CObject
{
public:
	CScore(int nPriority = 7);
	~CScore();

	static HRESULT Load(void);
	static void Unload(void);

	static CScore* Create(D3DXVECTOR3 pos, D3DXCOLOR col, float xsize, float ysize);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPosition(D3DXVECTOR3 pos);
	D3DXVECTOR3 GetPos(void);

	void AddScore(int nScore);

private:
	static LPDIRECT3DTEXTURE9 m_pTexture;
	D3DXVECTOR3 m_pos;
	float m_fxSize;
	float m_fySize;
	CNumber* m_apNumber[MAX_SCORE];
};

#endif