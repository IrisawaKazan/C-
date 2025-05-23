//==============================================================
//
// [input.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _INPUT_H_ // このマクロ定義がされてなかったら
#define _INPUT_H_ // 2重インクルード防止のマクロ定義

#include"main.h"

// マクロ定義
#define NUM_KEY_MAX (256) // キーの最大数

// 入力クラス
class CInput
{
public:
	CInput();
	virtual ~CInput();

	virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	virtual void Uninit(void);
	virtual void Update(void) = 0;

protected:
	static LPDIRECTINPUT8 m_pInput;
	LPDIRECTINPUTDEVICE8 m_pDevice;

private:

};

// キーボードクラス
class CInputKeyboard : public CInput
{
public:
	CInputKeyboard();
	~CInputKeyboard();

	HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	void Uninit(void);
	void Update(void);

	bool GetPress(int nKey);
	bool GetTrigger(int nKey);

private:
	BYTE m_aKeyStatePress[NUM_KEY_MAX];
	BYTE m_aKeyStateTrigger[NUM_KEY_MAX];
};

//// マウスクラス
//class CInputMouse : public CInput
//{
//public:
//	CInputMouse();
//	~CInputMouse();
//
//	HRESULT Init(HINSTANCE hInstance, HWND hWnd);
//	void Uninit(void);
//	void Update(void);
//	bool GetPress(int nKey);
//	bool GetTrigger(int nKey);
//
//private:
//
//};

#endif