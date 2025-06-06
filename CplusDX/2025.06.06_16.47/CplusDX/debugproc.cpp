//==============================================================
//
// [debugproc.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"debugproc.h"
#include"manager.h"
#include"renderer.h"

// �ÓI�����o�ϐ��錾
LPD3DXFONT CDebugProc::m_pFont = nullptr;
char CDebugProc::m_aStr[MAX_CHARACTER] = {};

//----------------------------------------
// �R���X�g���N�^
//----------------------------------------
CDebugProc::CDebugProc()
{

}

//----------------------------------------
// �f�X�g���N�^
//----------------------------------------
CDebugProc::~CDebugProc()
{

}

//----------------------------------------
// ����������
//----------------------------------------
void CDebugProc::Init(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �f�o�b�O�\���p�t�H���g�̐���
	D3DXCreateFont(pDevice, 18, 0, 0, 0,
		FALSE, SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH,
		"Terminal", &m_pFont);

	// �o�b�t�@�̃N���A
	pDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER), D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
}

//----------------------------------------
// �I������
//----------------------------------------
void CDebugProc::Uninit(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �f�o�b�O�\���p�t�H���g�̔j��
	if (m_pFont != NULL)
	{
		m_pFont->Release();
		m_pFont = NULL;
	}

	// Direct3D�f�o�C�X�̔j��
	if (pDevice != NULL)
	{
		pDevice->Release();
		pDevice = NULL;
	}
}

//----------------------------------------
// printf
//----------------------------------------
void CDebugProc::Print(const char* fint, ...)
{
	va_list args;

	va_start(args, fint);

	while (*fint)
	{
		if (*fint == '%')
		{
			fint++;
			switch (*fint)
			{
			case 'd':
				printf("%d", va_arg(args, int));
				break;
			}
		}
		else
		{
			putchar(*fint);
		}

		fint++;
	}

	va_end(args);

	// ���o�����l(����)���o�b�t�@�ɘA������
	va_copy(args, m_aStr);
}

//----------------------------------------
// �`�揈��
//----------------------------------------
void CDebugProc::Draw(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };

	m_pFont->DrawText(NULL, &m_aStr[0], -1, &rect, DT_LEFT, D3DCOLOR_RGBA(255, 255, 255, 255));

	// �o�b�t�@�̃N���A
	pDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER), D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
}