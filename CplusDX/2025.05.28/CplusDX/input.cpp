//==============================================================
//
// [input.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"input.h"

// �ÓI�����o�ϐ��錾
LPDIRECTINPUT8 CInput::m_pInput = NULL;

//----------------------------------------
// �R���X�g���N�^
//----------------------------------------
CInput::CInput()
{
	m_pInput = NULL;
	m_pDevice = NULL;
}

//----------------------------------------
// �f�X�g���N�^
//----------------------------------------
CInput::~CInput()
{

}

//----------------------------------------
// ����������
//----------------------------------------
HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
	if (m_pInput == NULL)
	{
		// DirectInput�I�u�W�F�N�g�̐���
		if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInput, NULL)))
		{
			return E_FAIL;
		}
	}

	return S_OK;
}

//----------------------------------------
// �I������
//----------------------------------------
void CInput::Uninit(void)
{
	// ���̓f�o�C�X�̔j��
	if (m_pDevice != NULL)
	{
		m_pDevice->Unacquire(); // �A�N�Z�X����j��
		m_pDevice->Release();
		m_pDevice = NULL;
	}

	// DirectInput�I�u�W�F�N�g�̔j��
	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}
}

//----------------------------------------
// �L�[�{�[�h�̃R���X�g���N�^
//----------------------------------------
CInputKeyboard::CInputKeyboard()
{
	for (int nCount = 0; nCount < NUM_KEY_MAX; nCount++)
	{
		m_aKeyStatePress[nCount] = NULL;
		m_aKeyStateTrigger[nCount] = NULL;
	}
}

//----------------------------------------
// �L�[�{�[�h�̃f�X�g���N�^
//----------------------------------------
CInputKeyboard::~CInputKeyboard()
{

}

//----------------------------------------
// �L�[�{�[�h�̏���������
//----------------------------------------
HRESULT CInputKeyboard::Init(HINSTANCE hInstance, HWND hWnd)
{
	CInput::Init(hInstance, hWnd);

	// �f�o�C�X�̐���
	if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}

	// �f�[�^�t�H�[�}�b�g��ݒ�
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	// �������[�h��ݒ�
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	return S_OK;
}

//----------------------------------------
// �L�[�{�[�h�̏I������
//----------------------------------------
void CInputKeyboard::Uninit(void)
{
	CInput::Uninit();
}

//----------------------------------------
// �L�[�{�[�h�̍X�V����
//----------------------------------------
void CInputKeyboard::Update(void)
{
	BYTE aKeyState[NUM_KEY_MAX]; // �L�[�{�[�h�̓��͏��

	// ���̓f�o�C�X����f�[�^���擾
	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (int nCount = 0; nCount < NUM_KEY_MAX; nCount++)
		{
			m_aKeyStateTrigger[nCount] = (m_aKeyStatePress[nCount] ^ aKeyState[nCount]) & aKeyState[nCount];
			m_aKeyStatePress[nCount] = aKeyState[nCount]; // �L�[�{�[�h�̃v���X����ۑ�
		}
	}
	else
	{
		m_pDevice->Acquire(); // �L�[�{�[�h�ւ̃A�N�Z�X�����l��
	}
}

//----------------------------------------
// �L�[�{�[�h�̃v���X���擾����
//----------------------------------------
bool CInputKeyboard::GetPress(int nKey)
{
	return (m_aKeyStatePress[nKey] & 0x80) ? true : false;
}

//----------------------------------------
// �L�[�{�[�h�̃g���K�[���擾����
//----------------------------------------
bool CInputKeyboard::GetTrigger(int nKey)
{
	return (m_aKeyStateTrigger[nKey] & 0x80) ? true : false;
}