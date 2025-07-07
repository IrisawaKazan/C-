//==============================================================
//
// [input.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _INPUT_H_ // ���̃}�N����`������ĂȂ�������
#define _INPUT_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"

// �}�N����`
#define NUM_KEY_MAX (256) // �L�[�̍ő吔

// ���̓N���X
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

// �L�[�{�[�h�N���X
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

// �}�E�X�N���X
class CInputMouse : public CInput
{
public:
	// �}�E�X�̎��
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

//// �W���C�p�b�h�N���X
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