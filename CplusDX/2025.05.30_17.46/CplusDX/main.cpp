//==============================================================
//
// [main.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"main.h"
#include"renderer.h"
#include"object.h"
#include"object2D.h"
#include"manager.h"

// �v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam);

//----------------------------------------
// ���C���֐�
//----------------------------------------
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hinstancePrev, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	CManager* pManager = NULL;

	//DWORD dwCurrentTime;
	//DWORD dwExecLastTime;

	WNDCLASSEX wcex
	{
		sizeof(WNDCLASSEX),             // WINDCLASSEX�̃������T�C�Y
		CS_CLASSDC,                     // �E�B���h�E�̃X�^�C��
		WindowProc,                     // �E�B���h�E�v���V�[�W��
		0,                              // 0�ɂ���(�ʏ�͎g�p���Ȃ�)
		0,                              // 0�ɂ���(�ʏ�͎g�p���Ȃ�)
		hInstance,                      // �C���X�^���X�n���h��
		LoadIcon(NULL,IDI_APPLICATION), // �^�X�N�o�[�̃A�C�R��
		LoadCursor(NULL,IDC_ARROW),     // �}�E�X�J�[�\��
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,
		CLASS_NAME,
		LoadIcon(NULL,IDI_APPLICATION)
	};

	HWND hWnd;                                      // �E�B���h�E�n���h��
	MSG msg;                                        // ���b�Z�[�W���i�[����ϐ�
	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT }; // ��ʃT�C�Y�̍\����

	// �E�B���h�E�N���X�̓o�^
	RegisterClassEx(&wcex);

	// �N���C�A���g�̈���w��̃T�C�Y�ɒ���
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	// �E�B���h�E�𐶐�
	hWnd = CreateWindowEx(0,
		CLASS_NAME,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		(rect.right - rect.left), // �E�B���h�E�̕�
		(rect.bottom - rect.top), // �E�B���h�E�̍���
		NULL,
		NULL,
		hInstance,
		NULL);

	// �}�l�[�W���̐���
	pManager = new CManager;

	// �}�l�[�W���̏���������
	pManager->Init(hInstance, hWnd);

	//// �I�u�W�F�N�g�̐���
	//CObject2D::Create()->SetPosition(D3DXVECTOR3(100.0f, 100.0f, 0.0f));
	//CObject2D::Create()->SetPosition(D3DXVECTOR3(500.0f, 500.0f, 0.0f));
	//CObject2D::Create()->SetPosition(D3DXVECTOR3(800.0f, 250.0f, 0.0f));

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, nCmdShow); // �E�B���h�E�̕\����Ԃ�ݒ�
	UpdateWindow(hWnd);         // �N���C�A���g�̈���X�V

	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
		{// windows�̏���
			if (msg.message == WM_QUIT)
			{// WM_QUIT���b�Z�[�W���󂯎�����烁�b�Z�[�W���[�v�𔲂���
				break;
			}
			else
			{
				// ���b�Z�[�W�̐ݒ�
				TranslateMessage(&msg); // ���z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�
				DispatchMessage(&msg);  // �E�B���h�E�v���V�[�W���փ��b�Z�[�W�𑗏o
			}
		}
		else
		{
			// �}�l�[�W���̍X�V����
			pManager->Update();

			// �}�l�[�W���̕`�揈��
			pManager->Draw();
		}
	}
	
	//// �I�u�W�F�N�g�̔j��
	//CObject::ReleaseAll();

	//// �����_���[�̔j��
	//if (pManager != NULL)
	//{
	//	// �I������
	//	pManager->Uninit();

	//	delete pManager;

	//	pManager = NULL;
	//}

	// �E�B���h�E�N���X�̓o�^������
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	return (int)msg.wParam;
}

//----------------------------------------
// �E�B���h�E�v���V�[�W��
//----------------------------------------
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		// WM_QUIT���b�Z�[�W�𑗂�
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			// �E�B���h�E��j������
			DestroyWindow(hWnd);
			break;
		}
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, IParam);
}