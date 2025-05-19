//==============================================================
//
// [background.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _BACKGROUND_H_ // このマクロ定義がされてなかったら
#define _BACKGROUND_H_ // 2重インクルード防止のマクロ定義

#include"main.h"
#include"object2D.h"

// バックグラウンドクラス
class CBackground : public CObject2D
{
public:
	CBackground();
	~CBackground();

	static CBackground* Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
};

#endif