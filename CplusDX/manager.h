//==============================================================
//
// [manager.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _MANAGER_H_ // ���̃}�N����`������ĂȂ�������
#define _MANAGER_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"renderer.h"
#include"input.h"

// �}�l�[�W���N���X
class CManager
{
public:
	CManager();
	~CManager();

	HRESULT Init(HINSTANCE nInstance, HWND hWnd, BOOL bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static CRenderer* GetRenderer(void);
	static CInputKeyboard* GetInputKeyboard(void);

private:
	static CRenderer* m_pRenderer;
	static CInputKeyboard* m_pInputKeyboard;
};

#endif