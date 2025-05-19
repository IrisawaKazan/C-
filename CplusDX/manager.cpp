//==============================================================
//
// [manager.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"manager.h"
#include"object2D.h"

// �ÓI�����o�ϐ��錾
CRenderer* CManager::m_pRenderer = {};
CInputKeyboard* CManager::m_pInputKeyboard = {};

//----------------------------------------
// �R���X�g���N�^
//----------------------------------------
CManager::CManager()
{
	m_pRenderer = NULL;
}

//----------------------------------------
// �f�X�g���N�^
//----------------------------------------
CManager::~CManager()
{

}

//----------------------------------------
// ����������
//----------------------------------------
HRESULT CManager::Init(HINSTANCE nInstance, HWND hWnd, BOOL bWindow)
{
	// �����_���[�̐���
	m_pRenderer = new CRenderer;

	// �����_���[�̏���������
	if (FAILED(m_pRenderer->Init(hWnd, TRUE)))
	{// ���������������s�����ꍇ
		return -1;
	}

	// �L�[�{�[�h�̐���
	m_pInputKeyboard = new CInputKeyboard;

	// �L�[�{�[�h�̏���������
	if (FAILED(m_pInputKeyboard->Init(nInstance, hWnd)))
	{// ���������������s�����ꍇ
		return -1;
	}

	// �I�u�W�F�N�g�̐���
	CObject2D::Create()->SetPosition(D3DXVECTOR3(100.0f, 100.0f, 0.0f));
	//CObject2D::Create()->SetPosition(D3DXVECTOR3(500.0f, 500.0f, 0.0f));
	//CObject2D::Create()->SetPosition(D3DXVECTOR3(800.0f, 250.0f, 0.0f));
	CPlayer::Create()->SetPosition(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f)); // �����j���O�}��
}
//----------------------------------------
// �I������
//----------------------------------------
void CManager::Uninit(void)
{
	// �S�ẴI�u�W�F�N�g�̔j��
	CObject::ReleaseAll;

	// �L�[�{�[�h�̔j��
	if (m_pInputKeyboard != NULL)
	{
		// �I������
		m_pInputKeyboard->Uninit();

		delete m_pInputKeyboard;

		m_pInputKeyboard = NULL;
	}

	// �����_���[�̔j��
	if (m_pRenderer != NULL)
	{
		// �I������
		m_pRenderer->Uninit();

		delete m_pRenderer;

		m_pRenderer = NULL;
	}
}

//----------------------------------------
// �X�V����
//----------------------------------------
void CManager::Update(void)
{
	// �L�[�{�[�h�̍X�V����
	m_pInputKeyboard->Update();

	// �����_���[�̍X�V����
	m_pRenderer->Update();
}

//----------------------------------------
// �`�揈��
//----------------------------------------
void CManager::Draw(void)
{
	m_pRenderer->Draw();
}

//----------------------------------------
// �����_���[�̎擾����
//----------------------------------------
CRenderer* CManager::GetRenderer(void)
{
	return m_pRenderer;
}

//----------------------------------------
// �L�[�{�[�h�̎擾����
//----------------------------------------
CInputKeyboard* CManager::GetInputKeyboard(void)
{
	return m_pInputKeyboard;
}