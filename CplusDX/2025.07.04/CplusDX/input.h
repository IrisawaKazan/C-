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

	virtual HRESULT Init(HINSTANCE hInstance);
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

// マウスクラス
class CInputMouse : public CInput
{
public:
	// マウスの種類
	typedef enum
	{
		MOUSE_LEFTBUTTON = 0,
		MOUSE_RIGHTBUTTON,

		MOUSE_MAX
	}MOUSE;

	CInputMouse();
	~CInputMouse();

	HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	void Uninit(void);
	void Update(void);
	bool GetPress(int nKey);
	bool GetTrigger(int nKey);

private:

};

//// ジョイパッドクラス
//class CInputJoypad : public CInput
//{
//public:
//	typedef enum
//	{
//		JOYKEY_UP = 0,
//		JOYKEY_DOWN,
//		JOYKEY_LEFT,
//		JOYKEY_RIGHT,
//		JOYKEY_START,
//		JOYKEY_BACK,
//		JOYKEY_LS,
//		JOYKEY_RS,
//		JOYKEY_LEFT_B,
//		JOYKEY_RIGHT_B,
//		JOYKEY_LEFT_TRIGGER,
//		JOYKEY_RIGHT_TRIGGER,
//		JOYKEY_A,
//		JOYKEY_B,
//		JOYKEY_X,
//		JOYKEY_Y,
//
//		JOYKEY_MAX
//	}JOYKEY;
//
//	CInputJoypad();
//	~CInputJoypad();
//
//	HRESULT Init(HINSTANCE hInstance, HWND hWnd);
//	void Uninit(void);
//	void Update(void);
//
//	bool GetPress(JOYKEY nKey);
//	bool GetTrigger(JOYKEY nKey);
//
//private:
//
//};

#endif