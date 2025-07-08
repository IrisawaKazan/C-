//==============================================================
//
// [manager.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"manager.h"

// �ÓI�����o�ϐ��錾
CRenderer* CManager::m_pRenderer = nullptr;
CInputKeyboard* CManager::m_pInputKeyboard = nullptr;
CInputMouse* CManager::m_pInputMouse = nullptr;
CInputJoypad* CManager::m_pInputJoypad = nullptr;
CSound* CManager::m_pSound = nullptr;
CCamera* CManager::m_pCamera = nullptr;
CLight* CManager::m_pLight = nullptr;
CDebugProc* CManager::m_pDebugProc = nullptr;

CPlayer* CManager::m_pPlayer = nullptr;
CBackground* CManager::m_pBackground = nullptr;
CEnemy* CManager::m_pEnemy = nullptr;
CScore* CManager::m_pScore = nullptr;
CTimer* CManager::m_pTimer = nullptr;
CEffect* CManager::m_pEffect = nullptr;
CPause* CManager::m_pPause = nullptr;

CObjectX* CManager::m_pObjectX = nullptr;

//----------------------------------------
// �R���X�g���N�^
//----------------------------------------
CManager::CManager()
{
	m_bPause = NULL;
	m_nDebrisSpawn = NULL;

	for (int nCnt = 0; nCnt < MAX_FRAMECOUNTER; nCnt++)
	{
		m_nFrameCounter[nCnt] = NULL;
	}
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

	// �}�E�X�̐���
	m_pInputMouse = new CInputMouse;

	// �}�E�X�̏���������
	if (FAILED(m_pInputMouse->Init(nInstance, hWnd)))
	{// ���������������s�����ꍇ
		return -1;
	}

	// �p�b�h�̐���
	m_pInputJoypad = new CInputJoypad;

	// �p�b�h�̏���������
	if (FAILED(m_pInputJoypad->Init(nInstance, hWnd)))
	{// ���������������s�����ꍇ
		return -1;
	}

	// �T�E���h�̐���
	m_pSound = new CSound;

	// �T�E���h�̏���������
	m_pSound->Init(hWnd);

	// �J�����̐���
	m_pCamera = new CCamera;
	m_pCamera->Init();

	// ���C�g�̐���
	m_pLight = new CLight;
	m_pLight->Init();

	// �f�o�b�O�̐���
	m_pDebugProc = new CDebugProc;
	m_pDebugProc->Init();

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

	// �G�t�F�N�g�̃e�N�X�`���̓ǂݍ���
	CEffect::Load();

	// �X�R�A�̃e�N�X�`���̓ǂݍ���
	CScore::Load();

	// �^�C�}�[�̃e�N�X�`���̓ǂݍ���
	CTimer::Load();
	
	// �|�[�Y�̃e�N�X�`���̓ǂݍ���
	CPause::Load();

	// �I�u�W�F�N�g�̐���(�����z�u)
	//CBackground::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), SCREEN_WIDTH, SCREEN_HEIGHT); // �w�i
	//CEnemy::Create(D3DXVECTOR3(SCREEN_WIDTH - 100.0f, SCREEN_HEIGHT / 3.0f, 0.0f), ENEMY_SIZEX, ENEMY_SIZEY, CEnemy::ETYPE_000); // �G000
	//CEnemy::Create(D3DXVECTOR3(SCREEN_WIDTH - 100.0f, SCREEN_HEIGHT / 2.0f, 0.0f), ENEMY_SIZEX, ENEMY_SIZEY, CEnemy::ETYPE_001); // �G001
	//CPlayer::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), 100.0f, 100.0f); // �v���C���[

	// �I�u�W�F�N�g3D(���|���S��)�̐���(�����z�u)
	//CObject3D::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// bgX�̐���
	CBackgroundX::Create(D3DXVECTOR3(0.0f, -325.0f, 0.0f));

	// �I�u�W�F�N�gX�̐���(�����z�u)
	m_pObjectX = CObjectX::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// �I�u�W�F�N�g�r���{�[�h(��)�̐���(�����z�u)
	//CObjectBillboard::Create(D3DXVECTOR3(75.0f, 50.0f, 0.0f)/*, 50.0f, 50.0f*/);

	// �F���S�~�̐���(�����z�u)
	CStardustX::Create(D3DXVECTOR3(-150.0f, 0.0f, 100.0f), CStardustX::STARDUST_000_A);

	// �f�b�h�]�[���̐���(�����z�u)
	CDeadzoneX::Create(D3DXVECTOR3(0.0f, 0.0f, 147.5f));

	// �X�R�A
	CScore::Create(D3DXVECTOR3(1100.0f, 50.0f, 0.0f), D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f), 30.0f, 90.0f);

	// �^�C�}�[
	//CTimer::Create(D3DXVECTOR3(1100.0f, 50.0f, 0.0f), D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f), 30.0f, 90.0f);

	// BGM
	m_pSound->PlaySoundA(CSound::SOUND_LABEL_MAINBGM);

	m_bPause = false; // �|�[�Y����

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

	// �G�t�F�N�g�̃e�N�X�`���̔j��
	CEffect::Unload();

	// �X�R�A�̃e�N�X�`���̔j��
	CScore::Unload();

	// �^�C�}�[�̃e�N�X�`���̔j��
	CTimer::Unload();

	// �|�[�Y�̃e�N�X�`���̔j��
	CPause::Unload();

	// �L�[�{�[�h�̔j��
	if (m_pInputKeyboard != nullptr)
	{
		// �I������
		m_pInputKeyboard->Uninit();

		delete m_pInputKeyboard;

		m_pInputKeyboard = nullptr;
	}

	// �}�E�X�̔j��
	if (m_pInputMouse != nullptr)
	{
		// �I������
		m_pInputMouse->Uninit();

		delete m_pInputMouse;

		m_pInputMouse = nullptr;
	}

	// �p�b�h�̔j��
	if (m_pInputJoypad != nullptr)
	{
		// �I������
		m_pInputJoypad->Uninit();

		delete m_pInputJoypad;

		m_pInputJoypad = nullptr;
	}

	// �����_���[�̔j��
	if (m_pRenderer != nullptr)
	{
		// �I������
		m_pRenderer->Uninit();

		delete m_pRenderer;

		m_pRenderer = nullptr;
	}

	// �T�E���h�̔j��
	if (m_pSound != nullptr)
	{
		// �I������
		m_pSound->Uninit();

		delete m_pSound;

		m_pSound = nullptr;
	}

	// �J�����̔j��
	if (m_pCamera != nullptr)
	{
		// �I������
		m_pCamera->Uninit();

		delete m_pCamera;

		m_pCamera = nullptr;
	}

	// ���C�g�̔j��
	if (m_pLight != nullptr)
	{
		// �I������
		m_pLight->Uninit();

		delete m_pLight;

		m_pLight = nullptr;
	}

	// �f�o�b�O�̔j��
	if (m_pDebugProc != nullptr)
	{
		// �I������
		m_pDebugProc->Uninit();

		delete m_pDebugProc;

		m_pDebugProc = nullptr;
	}

	// �I�u�W�F�N�gX�̔j��
	m_pObjectX = nullptr;
}

//----------------------------------------
// �X�V����
//----------------------------------------
void CManager::Update(void)
{
	CInputKeyboard* pInputKeyboard;

	// �L�[�{�[�h�̎擾
	pInputKeyboard = CManager::GetInputKeyboard();

	// �L�[�{�[�h�̍X�V����
	m_pInputKeyboard->Update();

	// �}�E�X�̍X�V����
	m_pInputMouse->Update();

	// �p�b�h�̍X�V����
	m_pInputJoypad->Update();

	if (pInputKeyboard->GetTrigger(DIK_TAB) || pInputKeyboard->GetTrigger(DIK_P) == true)
	{// �|�[�Y�L�[�������ꂽ
		m_bPause = m_bPause ? false : true;
	}

	if (m_bPause == true)
	{// �|�[�Y��
		//CPause::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), SCREEN_WIDTH, SCREEN_HEIGHT);

		//m_pPause->Update();
	}

	if (m_bPause == false)
	{// �|�[�Y���łȂ����
		// �����_���[�̍X�V����
		m_pRenderer->Update();

		// �J�����̍X�V����
		m_pCamera->Update();

		// ���C�g�̍X�V
		m_pLight->Update();

		// �G�̃����_������
		m_nDebrisSpawn++;

		float fPosZ = (float)(rand() % 130/* �o�Ă���͈� */);

		// ���݂̎�������Ƃ��Đݒ�
		srand(time(NULL));

		// ���i�ŏo�Ȃ��悤�ɐ�������J�E���^�[
		for (int nCnt = 0; nCnt < MAX_FRAMECOUNTER; nCnt++)
		{
			m_nFrameCounter[nCnt]++;
		}

		// �g�Q�g�Q��
		if (m_nDebrisSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[0] >= NUM_FRAME_CNT)
		{
			CDebrisX::Create(D3DXVECTOR3(-DEBRIS_000_POS_X, 0.0f, fPosZ), CDebrisX::DEBRIS_000_A);

			m_nDebrisSpawn = 0;
			m_nFrameCounter[0] = 0;
		}
		if (m_nDebrisSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[1] >= NUM_FRAME_CNT)
		{
			CDebrisX::Create(D3DXVECTOR3(-DEBRIS_000_POS_X, 0.0f, -fPosZ), CDebrisX::DEBRIS_000_A);

			m_nDebrisSpawn = 0;
			m_nFrameCounter[1] = 0;
		}

		// ���g�Q�g�Q
		if (m_nDebrisSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[2] >= NUM_FRAME_CNT)
		{
			CDebrisX::Create(D3DXVECTOR3(DEBRIS_000_POS_X, 0.0f, fPosZ), CDebrisX::DEBRIS_000_B);

			m_nDebrisSpawn = 0;
			m_nFrameCounter[2] = 0;
		}
		if (m_nDebrisSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[3] >= NUM_FRAME_CNT)
		{
			CDebrisX::Create(D3DXVECTOR3(DEBRIS_000_POS_X, 0.0f, -fPosZ), CDebrisX::DEBRIS_000_B);

			m_nDebrisSpawn = 0;
			m_nFrameCounter[3] = 0;
		}

		// �X�N���b�v��
		if (m_nDebrisSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[4] >= NUM_FRAME_CNT)
		{
			CScrap::Create(D3DXVECTOR3(-SCRAP_000_POS_X, 0.0f, fPosZ), CScrap::SCRAP_000_A);

			m_nDebrisSpawn = 0;
			m_nFrameCounter[4] = 0;
		}
		if (m_nDebrisSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[5] >= NUM_FRAME_CNT)
		{
			CScrap::Create(D3DXVECTOR3(-SCRAP_000_POS_X, 0.0f, -fPosZ), CScrap::SCRAP_000_A);

			m_nDebrisSpawn = 0;
			m_nFrameCounter[5] = 0;
		}

		// ���X�N���b�v
		if (m_nDebrisSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[6] >= NUM_FRAME_CNT)
		{
			CScrap::Create(D3DXVECTOR3(SCRAP_000_POS_X, 0.0f, fPosZ), CScrap::SCRAP_000_B);

			m_nDebrisSpawn = 0;
			m_nFrameCounter[6] = 0;
		}
		if (m_nDebrisSpawn >= rand() / MAX_SPAWN && m_nFrameCounter[7] >= NUM_FRAME_CNT)
		{
			CScrap::Create(D3DXVECTOR3(SCRAP_000_POS_X, 0.0f, -fPosZ), CScrap::SCRAP_000_B);

			m_nDebrisSpawn = 0;
			m_nFrameCounter[7] = 0;
		}

		// �m�F�p
		// �X�R�A���Z(+1)
		if (pInputKeyboard->GetTrigger(DIK_1) == true)
		{
			// �X�R�A���Z
			CScore::AddScore(1);

			// SE
			m_pSound->PlaySoundA(CSound::SOUND_LABEL_SAMPLESE);
		}
		// �X�R�A���Z(-1)
		if (pInputKeyboard->GetTrigger(DIK_0) == true)
		{
			// �X�R�A���Z
			CScore::AddScore(-1);

			// SE
			m_pSound->PlaySoundA(CSound::SOUND_LABEL_SAMPLESE);
		}
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
// �}�E�X�̎擾����
//----------------------------------------
CInputMouse* CManager::GetInputMouse(void)
{
	return m_pInputMouse;
}

//----------------------------------------
// �p�b�h�̎擾����
//----------------------------------------
CInputJoypad* CManager::GetInputJoypad(void)
{
	return m_pInputJoypad;
}

//----------------------------------------
// �J�����̎擾����
//----------------------------------------
CCamera* CManager::GetCamera(void)
{
	return m_pCamera;
}

//----------------------------------------
// ���C�g�̎擾����
//----------------------------------------
CLight* CManager::GetLight(void)
{
	return m_pLight;
}

//----------------------------------------
// �f�o�b�O�̎擾����
//----------------------------------------
CDebugProc* CManager::GetDebugProc(void)
{
	return m_pDebugProc;
}

//----------------------------------------
// �T�E���h�̎擾����
//----------------------------------------
CSound* CManager::GetSound(void)
{
	return m_pSound;
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
// �X�R�A�̎擾����
//----------------------------------------
CScore* CManager::GetScore(void)
{
	return m_pScore;
}

//----------------------------------------
// �^�C�}�[�̎擾����
//----------------------------------------
CTimer* CManager::GetTimer(void)
{
	return m_pTimer;
}

//----------------------------------------
// �G�t�F�N�g�̎擾����
//----------------------------------------
CEffect* CManager::GetEffect(void)
{
	return m_pEffect;
}

//----------------------------------------
// �|�[�Y�̎擾����
//----------------------------------------
CPause* CManager::GetPause(void)
{
	return m_pPause;
}

//----------------------------------------
// �I�u�W�F�N�gX�̎擾����
//----------------------------------------
CObjectX* CManager::GetObjectX(void)
{
	return m_pObjectX;
}