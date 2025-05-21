//==============================================================
//
// [renderer.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _RENDERER_H_ // このマクロ定義がされてなかったら
#define _RENDERER_H_ // 2重インクルード防止のマクロ定義

#include"main.h"

// レンダラークラス
class CRenderer
{
public:
	CRenderer();
	~CRenderer();

	HRESULT Init(HWND hWnd, BOOL bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	LPDIRECT3DDEVICE9 GetDevice(void);

private:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pD3DDevice;
};

#endif