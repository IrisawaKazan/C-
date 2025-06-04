////==============================================================
////
//// [effect.cpp]
//// Author: Irisawa Kazan
////
////==============================================================
//#include"effect.h"
//#include"manager.h"
//#include"renderer.h"
//
//// �ÓI�����o�ϐ��錾
//LPDIRECT3DTEXTURE9 CEffect::m_pTexture = 0;
//
////----------------------------------------
//// �G�t�F�N�g�̃R���X�g���N�^
////----------------------------------------
//CEffect::CEffect(int nPriority) : CObject2D(nPriority)
//{
//
//}
//
////----------------------------------------
//// �G�t�F�N�g�̃f�X�g���N�^
////----------------------------------------
//CEffect::~CEffect()
//{
//
//}
//
////----------------------------------------
//// �e�N�X�`���̐���(�ǂݍ���)
////----------------------------------------
//HRESULT CEffect::Load(void)
//{
//	// �f�o�C�X�̎擾
//	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
//
//	// �e�N�X�`���̏���������
//	D3DXCreateTextureFromFile(pDevice,
//		"data\\TEXTURE\\effect000.jpg",
//		&m_pTexture);
//
//	return S_OK;
//}
//
////----------------------------------------
//// �e�N�X�`���̔j��
////----------------------------------------
//void CEffect::Unload(void)
//{
//	// �e�N�X�`���̔j��
//	if (m_pTexture != NULL)
//	{
//		m_pTexture->Release();
//		m_pTexture = NULL;
//	}
//}
//
////----------------------------------------
//// �G�t�F�N�g�̐�������
////----------------------------------------
//CEffect* CEffect::Create(D3DXVECTOR3 pos, float xsize, float ysize)
//{
//	CEffect* pEffect;
//
//	int nNumAll = CObject::GetNumAll();
//
//	if (nNumAll <= MAX_OBJ)
//	{
//		// �I�u�W�F�N�g2D�̐���
//		pEffect = new CEffect;
//
//		// ����������
//		pEffect->Init(pos);
//
//		// �T�C�Y�̐ݒ�
//		pEffect->SetSize(xsize, ysize);
//
//		// �e�N�X�`���̊��蓖��
//		pEffect->BindTexture(m_pTexture);
//
//		return pEffect;
//	}
//
//	return NULL;
//}
//
////----------------------------------------
//// �G�t�F�N�g�̏���������
////----------------------------------------
//HRESULT CEffect::Init(D3DXVECTOR3 pos)
//{
//	// �e�N�X�`���̐ݒ�
//	CObject2D::SetUV(1.0f, 1.0f);
//
//	SetPosition(pos);
//
//	CObject2D::Init(pos);
//
//	// ��ނ̐ݒ菈��
//	CObject::SetType(TYPE_BULLET);
//
//	return S_OK;
//}
//
////----------------------------------------
//// �G�t�F�N�g�̏I������
////----------------------------------------
//void CEffect::Uninit(void)
//{
//	CObject2D::Uninit();
//}
//
////----------------------------------------
//// �G�t�F�N�g�̍X�V����
////----------------------------------------
//void CEffect::Update(void)
//{
//
//
//	CObject2D::Update();
//}
//
////----------------------------------------
//// �G�t�F�N�g�̕`�揈��
////----------------------------------------
//void CEffect::Draw(void)
//{
//	CObject2D::Draw();
//}
//
////----------------------------------------
//// �G�t�F�N�g�̈ʒu�̐ݒ菈��
////----------------------------------------
//void CEffect::SetPosition(D3DXVECTOR3 pos)
//{
//	CObject2D::SetPosition(pos);
//}
//
////----------------------------------------
//// �G�t�F�N�g�̃T�C�Y�̐ݒ菈��
////----------------------------------------
//void CEffect::SetSize(float xsize, float ysize)
//{
//	CObject2D::SetSize(xsize, ysize);
//}