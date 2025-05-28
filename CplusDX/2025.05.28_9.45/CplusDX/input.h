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

	virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);
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

//// �}�E�X�N���X
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