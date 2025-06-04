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
#include"sound.h"
#include"score.h"

// �ÓI�����o�ϐ��錾
CRenderer* CManager::m_pRenderer = 0;
CInputKeyboard* CManager::m_pInputKeyboard = 0;
CPlayer* CManager::m_pPlayer = 0;
CBackground* CManager::m_pBackground = 0;
CEnemy* CManager::m_pEnemy = 0;
//CSound* CManager::m_pSound = 0;
CScore* CManager::m_pScore = 0;

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
HRESULT CManager::Init(HINSTANCE nInstance, HWND hWnd)
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

	// �T�E���h�̐���
	//m_pSound = new CSound;

	// �T�E���h�̏���������
	//m_pSound->Init(hWnd);

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

	// �X�R�A�̃e�N�X�`���̓ǂݍ���
	CScore::Load();

	// �I�u�W�F�N�g�̐���(�����z�u)
	CBackground::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), SCREEN_WIDTH, SCREEN_HEIGHT); // �w�i
	CEnemy::Create(D3DXVECTOR3(SCREEN_WIDTH - 100.0f, SCREEN_HEIGHT / 3.0f, 0.0f), ENEMY_SIZEX, ENEMY_SIZEY, CEnemy::ETYPE_000); // �G000
	CEnemy::Create(D3DXVECTOR3(SCREEN_WIDTH - 100.0f, SCREEN_HEIGHT / 2.0f, 0.0f), ENEMY_SIZEX, ENEMY_SIZEY, CEnemy::ETYPE_001); // �G001
	CPlayer::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), 100.0f, 100.0f); // �v���C���[

	CScore::Create(D3DXVECTOR3(50.0f, 75.0f, 0.0f), D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f), 50.0f, 100.0f);

	// BGM
	//m_pSound->PlaySound(CSound::SOUND_LABEL_MAINBGM);

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

	// �G�l�~�[�̃e�N�X�`���̔j��
	CEnemy::Unload();

	// �X�R�A�̃e�N�X�`���̔j��
	CScore::Unload();

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

	//// �T�E���h�̔j��
	//if (m_pSound != NULL)
	//{
	//	// �I������
	//	m_pSound->Uninit();

	//	delete m_pSound;

	//	m_pSound = NULL;
	//}
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

	CInputKeyboard* pInputKeyboard;

	// �L�[�{�[�h�̎擾
	pInputKeyboard = CManager::GetInputKeyboard();

	float fPosX = (float)(rand() % SCREEN_WIDTH);
	float fPosY = (float)(rand() % SCREEN_HEIGHT);
	
	// R�œG000�̐���
	if (pInputKeyboard->GetTrigger(DIK_R) == true)
	{
		CEnemy::Create(D3DXVECTOR3(fPosX, fPosY, 0.0f), ENEMY_SIZEX, ENEMY_SIZEY, CEnemy::ETYPE_000); // �G
	}
	// T�œG001�̐���
	if (pInputKeyboard->GetTrigger(DIK_T) == true)
	{
		CEnemy::Create(D3DXVECTOR3(fPosX, fPosY, 0.0f), ENEMY_SIZEX, ENEMY_SIZEY, CEnemy::ETYPE_001); // �G
	}
	// Y�œG002�̐���
	if (pInputKeyboard->GetTrigger(DIK_Y) == true)
	{
		CEnemy::Create(D3DXVECTOR3(fPosX, fPosY, 0.0f), ENEMY_SIZEX, ENEMY_SIZEY, CEnemy::ETYPE_002); // �G
	}
	// U�œG003�̐���
	if (pInputKeyboard->GetTrigger(DIK_U) == true)
	{
		CEnemy::Create(D3DXVECTOR3(fPosX, fPosY, 0.0f), ENEMY_SIZEX, ENEMY_SIZEY, CEnemy::ETYPE_003); // �G
	}

	// �G���^�[�L�[��2�̖ڈȍ~�̃v���C���[����
	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
	{
		m_pPlayer = CPlayer::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), 100.0f, 100.0f); // �v���C���[
	}
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

//----------------------------------------
// �T�E���h�̎擾����
//----------------------------------------
//CSound* CManager::GetSound(void)
//{
//	return m_pSound;
//}

//----------------------------------------
// �X�R�A�̎擾����
//----------------------------------------
CScore* CManager::GetScore(void)
{
	return m_pScore;
}