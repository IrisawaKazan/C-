////==============================================================
////
//// [sphereX.cpp]
//// Author: Irisawa Kazan
////
////==============================================================
//#include"sphereX.h"
//#include"manager.h"
//
//// �ÓI�����o�ϐ��錾
//LPDIRECT3DTEXTURE9 CSphereX::m_pTexture = nullptr;
//LPD3DXMESH CSphereX::m_pMesh = nullptr;
//LPD3DXBUFFER CSphereX::m_pBuffMat = nullptr;
//DWORD CSphereX::m_dwNumMat = 0.0f;
//
////----------------------------------------
//// �R���X�g���N�^
////----------------------------------------
//CSphereX::CSphereX(int nPriority)
//{
//	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//	m_fRotation = 0.0f;
//}
//
////----------------------------------------
//// �f�X�g���N�^
////----------------------------------------
//CSphereX::~CSphereX()
//{
//
//}
//
////----------------------------------------
//// X�t�@�C���̐���(�ǂݍ���)
////----------------------------------------
//HRESULT CSphereX::Load(void)
//{
//	// �f�o�C�X�̎擾
//	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
//
//	// X�t�@�C���̓ǂݍ���
//	D3DXLoadMeshFromX("data\\MODEL\\sphere.x",
//		D3DXMESH_SYSTEMMEM,
//		pDevice,
//		NULL,
//		&m_pBuffMat,
//		NULL,
//		&m_dwNumMat,
//		&m_pMesh);
//
//	D3DXMATERIAL* pMat = nullptr; // �}�e���A���ւ̃|�C���^
//
//	// �}�e���A���̃f�[�^�ւ̃|�C���^���擾
//	pMat = (D3DXMATERIAL*)m_pBuffMat->GetBufferPointer();
//
//	for (int nCntMat = 0; nCntMat < (int)m_dwNumMat; nCntMat++)
//	{
//		if (pMat[nCntMat].pTextureFilename != nullptr)
//		{
//			// ���̃t�@�C�������g�p���ăe�N�X�`����ǂݍ���
//
//
//			// �e�N�X�`���̓ǂݍ���
//
//
//			D3DXCreateTextureFromFile(pDevice, pMat[nCntMat].pTextureFilename, &m_pTexture);
//		}
//	}
//
//	return S_OK;
//}
//
////----------------------------------------
//// X�t�@�C���̔j��
////----------------------------------------
//void CSphereX::Unload(void)
//{
//	// �e�N�X�`���̔j��
//	if (m_pTexture != nullptr)
//	{
//		m_pTexture->Release();
//		m_pTexture = nullptr;
//	}
//
//	// ���b�V��(���_���W)�ւ̃|�C���^�̔j��
//	if (m_pMesh != nullptr)
//	{
//		m_pMesh->Release();
//		m_pMesh = nullptr;
//	}
//
//	// �}�e���A���ւ̃|�C���^�̔j��
//	if (m_pBuffMat != nullptr)
//	{
//		m_pBuffMat->Release();
//		m_pBuffMat = nullptr;
//	}
//
//	// �}�e���A���̐��j��
//	if (m_dwNumMat != NULL)
//	{
//		m_dwNumMat = NULL;
//	}
//}
//
////----------------------------------------
//// ��������
////----------------------------------------
//CSphereX* CSphereX::Create(D3DXVECTOR3 pos)
//{
//	CSphereX* pSphere;
//
//	int nNumAll = CObject::GetNumAll();
//
//	if (nNumAll <= MAX_OBJ)
//	{
//		// �I�u�W�F�N�g2D�̐���
//		pSphere = new CSphereX;
//
//		// ����������
//		pSphere->Init(pos);
//
//		pSphere->SetPosition(pos);
//
//		return pSphere;
//	}
//
//	return nullptr;
//}
//
////----------------------------------------
//// ����������
////----------------------------------------
//HRESULT CSphereX::Init(D3DXVECTOR3 pos)
//{
//	CObjectX::Init(pos);
//
//	// ��ނ̐ݒ菈��
//	CObject::SetType(TYPE_SPHEREX);
//
//	return S_OK;
//}
//
////----------------------------------------
//// �X�V����
////----------------------------------------
//void CSphereX::Uninit(void)
//{
//	CObjectX::Uninit();
//}
//
////----------------------------------------
//// �X�V����
////----------------------------------------
//void CSphereX::Update(void)
//{
//	CInputKeyboard* pInputKeyboard;
//
//	// �L�[�{�[�h�̎擾
//	pInputKeyboard = CManager::GetInputKeyboard();
//
//	// �ʒu�̎擾
//	D3DXVECTOR3 pos = GetPos();
//
//	// �����̎擾
//	D3DXVECTOR3 rot = GetRot();
//
//	// ��ɐi��
//	if (pInputKeyboard->GetPress(DIK_SPACE) == true)
//	{// ��
//		pos.z += MAX_PMOVE * 3.5f;
//	}
//
//	if (pos.z >= -132.5f)
//	{// ���ւ̈ړ�����
//		// ��Ɍ�ނ���
//		pos.z -= MAX_PMOVE;
//	}
//
//	// ���[�e�[�V����
//	m_fRotation += 1.0f;
//
//	rot = D3DXVECTOR3(0.0f, m_fRotation / 200.0f/* ��鑬�x */, 0.0f);
//
//	CSphereX::SetPosition(pos);
//
//	CSphereX::SetRotation(rot);
//
//	CObjectX::Update();
//}
//
////----------------------------------------
//// �`�揈��
////----------------------------------------
//void CSphereX::Draw(void)
//{
//	CObjectX::Draw();
//}
//
////----------------------------------------
//// �ʒu�̐ݒ菈��
////----------------------------------------
//void CSphereX::SetPosition(D3DXVECTOR3 pos)
//{
//	CObjectX::SetPosition(pos);
//}
//
////----------------------------------------
//// �ʒu�̐ݒ菈��
////----------------------------------------
//void CSphereX::SetRotation(D3DXVECTOR3 rot)
//{
//	CObjectX::SetRotation(rot);
//}