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
//LPDIRECT3DTEXTURE9 CSpereX::m_pTexture = nullptr;
//LPD3DXMESH CSpereX::m_pMesh = nullptr;
//LPD3DXBUFFER CSpereX::m_pBuffMat = nullptr;
//
////----------------------------------------
//// �R���X�g���N�^
////----------------------------------------
//CSpereX::CSpereX(int nPriority)
//{
//	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//}
//
////----------------------------------------
//// �f�X�g���N�^
////----------------------------------------
//CSpereX::~CSpereX()
//{
//
//}
//
////----------------------------------------
//// X�t�@�C���̐���(�ǂݍ���)
////----------------------------------------
//HRESULT CSpereX::Load(void)
//{
//	// �f�o�C�X�̎擾
//	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
//
//	// X�t�@�C���̓ǂݍ���
//	D3DXLoadMeshFromX("data\\MODEL\\BOX.x",
//		D3DXMESH_SYSTEMMEM,
//		pDevice,
//		NULL,
//		&m_pBuffMat,
//		NULL,
//		&m_dwNumMat,
//		&m_pMesh);
//
//	return S_OK;
//}
//
////----------------------------------------
//// X�t�@�C���̔j��
////----------------------------------------
//void CSpereX::Unload(void)
//{
//
//}
//
////----------------------------------------
//// ��������
////----------------------------------------
//CSpereX* CSpereX::Create(D3DXVECTOR3 pos, float xsize, float ysize)
//{
//	return nullptr;
//}
//
////----------------------------------------
//// ����������
////----------------------------------------
//HRESULT CSpereX::Init(D3DXVECTOR3 pos)
//{
//	return S_OK;
//}
//
////----------------------------------------
//// �X�V����
////----------------------------------------
//void CSpereX::Uninit(void)
//{
//	CObjectX::Uninit();
//}
//
////----------------------------------------
//// �X�V����
////----------------------------------------
//void CSpereX::Update(void)
//{
//
//}
//
////----------------------------------------
//// �`�揈��
////----------------------------------------
//void CSpereX::Draw(void)
//{
//	CObjectX::Draw();
//}
//
////----------------------------------------
//// �ʒu�̐ݒ菈��
////----------------------------------------
//void CSpereX::SetPosition(D3DXVECTOR3 pos)
//{
//	CObjectX::SetPosition(pos);
//}