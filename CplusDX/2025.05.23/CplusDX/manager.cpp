//==============================================================
//
// [manager.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"manager.h"
#include"object2D.h"
#include"player.h"
#include"background.h"
#include"renderer.h"
#include"input.h"
#include"bullet.h"
#include"explosion.h"
#include"enemy.h"

// �ÓI�����o�ϐ��錾
CRenderer* CManager::m_pRenderer = {};
CInputKeyboard* CManager::m_pInputKeyboard = {};
CPlayer* CManager::m_pPlayer = {};
CBackground* CManager::m_pBackground = {};
CEnemy* CManager::m_pEnemy = {};

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

	// �o�b�N�O���E���h�̃e�N�X�`���̓ǂݍ���
	CBackground::Load();

	// �o���b�g�̃e�N�X�`���̓ǂݍ���
	CBullet::Load();

	// �G�N�X�v���[�W�����̃e�N�X�`���̓ǂݍ���
	CExplosion::Load();

	// �v���C���[�̃e�N�X�`���̓ǂݍ���
	CPlayer::Load();

	// �G�l�~�[�̃e�N�X�`���̓ǂݍ���
	CEnemy::Load();

	// �I�u�W�F�N�g�̐���
	m_pBackground = CBackground::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), SCREEN_WIDTH, SCREEN_HEIGHT); // �w�i

	m_pEnemy = CEnemy::Create(D3DXVECTOR3(SCREEN_WIDTH - 100.0f, SCREEN_HEIGHT / 3.0f, 0.0f), 150.0f, 100.0f); // �G
	m_pEnemy = CEnemy::Create(D3DXVECTOR3(SCREEN_WIDTH - 100.0f, SCREEN_HEIGHT / 2.0f, 0.0f), 150.0f, 100.0f); // �G
	m_pPlayer = CPlayer::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), 100.0f, 100.0f); // �v���C���[(�����j���O�}������)

	return S_OK;
}

//----------------------------------------
// �I������
//----------------------------------------
void CManager::Uninit(void)
{
	// �S�ẴI�u�W�F�N�g�̔j��
	CObject::ReleaseAll();

	// �o�b�N�O���E���h�̃e�N�X�`���̔j��
	CBackground::Unload();

	// �o���b�g�̃e�N�X�`���̔j��
	CBullet::Unload();

	// �G�N�X�v���[�W�����̃e�N�X�`���̔j��
	CExplosion::Unload();

	// �v���C���[�̃e�N�X�`���̔j��
	CPlayer::Unload();

	// �G�l�~�[�̃e�N�X�`���̓ǂݍ���
	CPlayer::Unload();

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

//----------------------------------------
// �v���C���[�̎擾����
//----------------------------------------
CPlayer* CManager::GetPlayer(void)
{
	return m_pPlayer;
}

//----------------------------------------
// �o�b�N�O���E���h�̎擾����
//----------------------------------------
CBackground* CManager::GetBackground(void)
{
	return m_pBackground;
}

//----------------------------------------
// �G�l�~�[�̎擾����
//----------------------------------------
CEnemy* CManager::GetEnemy(void)
{
	return m_pEnemy;
}