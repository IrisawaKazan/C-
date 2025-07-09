////==============================================================
////
//// [titlemanager.cpp]
//// Author: Irisawa Kazan
////
////==============================================================
//#include"titlemanager.h"
//#include"renderer.h"
//
//// �ÓI�����o�ϐ��錾
//CRenderer* CTitle::m_pRenderer = nullptr;
//CInputKeyboard* CTitle::m_pInputKeyboard = nullptr;
//CSound* CTitle::m_pSound = nullptr;
//CCamera* CTitle::m_pCamera = nullptr;
//CLight* CTitle::m_pLight = nullptr;
//CDebugProc* CTitle::m_pDebugProc = nullptr;
//
//CPlayer* CTitle::m_pPlayer = nullptr;
//CBackground* CTitle::m_pBackground = nullptr;
//CEnemy* CTitle::m_pEnemy = nullptr;
//CScore* CTitle::m_pScore = nullptr;
//CEffect* CTitle::m_pEffect = nullptr;
//
////----------------------------------------
//// �R���X�g���N�^
////----------------------------------------
//CTitle::CTitle()
//{
//
//}
//
////----------------------------------------
//// �f�X�g���N�^
////----------------------------------------
//CTitle::~CTitle()
//{
//
//}
//
////----------------------------------------
//// ����������
////----------------------------------------
//HRESULT CTitle::Init(HINSTANCE nInstance, HWND hWnd)
//{
//	// �����_���[�̐���
//	m_pRenderer = new CRenderer;
//
//	// �����_���[�̏���������
//	if (FAILED(m_pRenderer->Init(hWnd, TRUE)))
//	{// ���������������s�����ꍇ
//		return -1;
//	}
//
//	// �L�[�{�[�h�̐���
//	m_pInputKeyboard = new CInputKeyboard;
//
//	// �L�[�{�[�h�̏���������
//	if (FAILED(m_pInputKeyboard->Init(nInstance, hWnd)))
//	{// ���������������s�����ꍇ
//		return -1;
//	}
//
//	// �T�E���h�̐���
//	m_pSound = new CSound;
//
//	// �T�E���h�̏���������
//	m_pSound->Init(hWnd);
//
//	// �J�����̐���
//	m_pCamera = new CCamera;
//	m_pCamera->Init();
//
//	// ���C�g�̐���
//	m_pLight = new CLight;
//	m_pLight->Init();
//
//	// �f�o�b�O�̐���
//	m_pDebugProc = new CDebugProc;
//	m_pDebugProc->Init();
//
//	// �o�b�N�O���E���h�̃e�N�X�`���̓ǂݍ���
//	CBackground::Load();
//
//	// �o���b�g�̃e�N�X�`���̓ǂݍ���
//	CBullet::Load();
//
//	// �G�N�X�v���[�W�����̃e�N�X�`���̓ǂݍ���
//	CExplosion::Load();
//
//	// �v���C���[�̃e�N�X�`���̓ǂݍ���
//	CPlayer::Load();
//
//	// �G�l�~�[�̃e�N�X�`���̓ǂݍ���
//	CEnemy::Load();
//
//	// �G�t�F�N�g�̃e�N�X�`���̓ǂݍ���
//	CEffect::Load();
//
//	// �X�R�A�̃e�N�X�`���̓ǂݍ���
//	CScore::Load();
//
//	// �I�u�W�F�N�gX(BOX)�̐���(�����z�u)
//	CObjectX::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
//
//	// �X�R�A
//	CScore::Create(D3DXVECTOR3(50.0f, 50.0f, 0.0f), D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f), 30.0f, 90.0f);
//
//	// BGM
//	m_pSound->PlaySoundA(CSound::SOUND_LABEL_MAINBGM);
//
//	return S_OK;
//}
//
////----------------------------------------
//// �I������
////----------------------------------------
//void CTitle::Uninit(void)
//{
//	// �S�ẴI�u�W�F�N�g�̔j��
//	CObject::ReleaseAll();
//
//	// �o�b�N�O���E���h�̃e�N�X�`���̔j��
//	CBackground::Unload();
//
//	// �o���b�g�̃e�N�X�`���̔j��
//	CBullet::Unload();
//
//	// �G�N�X�v���[�W�����̃e�N�X�`���̔j��
//	CExplosion::Unload();
//
//	// �v���C���[�̃e�N�X�`���̔j��
//	CPlayer::Unload();
//
//	// �G�l�~�[�̃e�N�X�`���̔j��
//	CEnemy::Unload();
//
//	// �G�t�F�N�g�̃e�N�X�`���̔j��
//	CEffect::Unload();
//
//	// �X�R�A�̃e�N�X�`���̔j��
//	CScore::Unload();
//
//	// �L�[�{�[�h�̔j��
//	if (m_pInputKeyboard != nullptr)
//	{
//		// �I������
//		m_pInputKeyboard->Uninit();
//
//		delete m_pInputKeyboard;
//
//		m_pInputKeyboard = nullptr;
//	}
//
//	// �����_���[�̔j��
//	if (m_pRenderer != nullptr)
//	{
//		// �I������
//		m_pRenderer->Uninit();
//
//		delete m_pRenderer;
//
//		m_pRenderer = nullptr;
//	}
//
//	// �T�E���h�̔j��
//	if (m_pSound != nullptr)
//	{
//		// �I������
//		m_pSound->Uninit();
//
//		delete m_pSound;
//
//		m_pSound = nullptr;
//	}
//
//	// �J�����̔j��
//	if (m_pCamera != nullptr)
//	{
//		// �I������
//		m_pCamera->Uninit();
//
//		delete m_pCamera;
//
//		m_pCamera = nullptr;
//	}
//
//	// ���C�g�̔j��
//	if (m_pLight != nullptr)
//	{
//		// �I������
//		m_pLight->Uninit();
//
//		delete m_pLight;
//
//		m_pLight = nullptr;
//	}
//
//	// �f�o�b�O�̔j��
//	if (m_pDebugProc != nullptr)
//	{
//		// �I������
//		m_pDebugProc->Uninit();
//
//		delete m_pDebugProc;
//
//		m_pDebugProc = nullptr;
//	}
//}
//
////----------------------------------------
//// �X�V����
////----------------------------------------
//void CTitle::Update(void)
//{
//	CInputKeyboard* pInputKeyboard;
//
//	// �L�[�{�[�h�̎擾
//	pInputKeyboard = CTitle::GetInputKeyboard();
//
//	// �L�[�{�[�h�̍X�V����
//	m_pInputKeyboard->Update();
//
//	CRenderer* pRenderer = nullptr;
//
//	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
//	{// ����L�[(ENTER�L�[)�������ꂽ
//		// ���[�h�ݒ�(�Q�[����ʂɈڍs)
//		pRenderer->SetMode(pRenderer->MODE_GAME);
//	}
//}
//
////----------------------------------------
//// �`�揈��
////----------------------------------------
//void CTitle::Draw(void)
//{
//	m_pRenderer->Draw();
//}
//
////----------------------------------------
//// �����_���[�̎擾����
////----------------------------------------
//CRenderer* CTitle::GetRenderer(void)
//{
//	return m_pRenderer;
//}
//
////----------------------------------------
//// �L�[�{�[�h�̎擾����
////----------------------------------------
//CInputKeyboard* CTitle::GetInputKeyboard(void)
//{
//	return m_pInputKeyboard;
//}
//
////----------------------------------------
//// �J�����̎擾����
////----------------------------------------
//CCamera* CTitle::GetCamera(void)
//{
//	return m_pCamera;
//}
//
////----------------------------------------
//// ���C�g�̎擾����
////----------------------------------------
//CLight* CTitle::GetLight(void)
//{
//	return m_pLight;
//}
//
////----------------------------------------
//// �f�o�b�O�̎擾����
////----------------------------------------
//CDebugProc* CTitle::GetDebugProc(void)
//{
//	return m_pDebugProc;
//}
//
////----------------------------------------
//// �T�E���h�̎擾����
////----------------------------------------
//CSound* CTitle::GetSound(void)
//{
//	return m_pSound;
//}
//
////----------------------------------------
//// �v���C���[�̎擾����
////----------------------------------------
//CPlayer* CTitle::GetPlayer(void)
//{
//	return m_pPlayer;
//}
//
////----------------------------------------
//// �o�b�N�O���E���h�̎擾����
////----------------------------------------
//CBackground* CTitle::GetBackground(void)
//{
//	return m_pBackground;
//}
//
////----------------------------------------
//// �G�l�~�[�̎擾����
////----------------------------------------
//CEnemy* CTitle::GetEnemy(void)
//{
//	return m_pEnemy;
//}
//
////----------------------------------------
//// �X�R�A�̎擾����
////----------------------------------------
//CScore* CTitle::GetScore(void)
//{
//	return m_pScore;
//}
//
////----------------------------------------
//// �G�t�F�N�g�̎擾����
////----------------------------------------
//CEffect* CTitle::GetEffect(void)
//{
//	return m_pEffect;
//}