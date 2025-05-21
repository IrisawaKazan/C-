//==============================================================
//
// [renderer.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _RENDERER_H_ // ���̃}�N����`������ĂȂ�������
#define _RENDERER_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"

// �����_���[�N���X
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