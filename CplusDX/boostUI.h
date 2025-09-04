//==============================================================
//
// [boostUI.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _BOOSTUI_H_ // このマクロ定義がされてなかったら
#define _BOOSTUI_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object2D.h"

// ブーストUIクラス
class CBoost : public CObject2D
{
public:
	typedef enum
	{
		BOOST_NONE = 0,
		BOOST_NORMAL,   // 通常
		BOOST_SUPER,    // スーパー

		BOOST_MAX
	}BOOST;

	CBoost(int nPriority = 7);
	~CBoost();

	static HRESULT Load(void);
	static void Unload(void);

	static CBoost* Create(D3DXVECTOR3 pos, float sizeX, float sizeY, BOOST type);

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetType(BOOST type);
	BOOST GetType(void);

private:
	static LPDIRECT3DTEXTURE9 m_pTexture[BOOST_MAX];

	BOOST m_type;
};

#endif