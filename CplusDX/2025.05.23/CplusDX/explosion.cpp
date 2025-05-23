//==============================================================
//
// [explosion.h]
// Author: Irisawa Kazan
//
//==============================================================
#include"explosion.h"
#include"manager.h"
#include"renderer.h"

// �ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CExplosion::m_pTexture = 0;

//----------------------------------------
// �G�N�X�v���[�W�����̃R���X�g���N�^
//----------------------------------------
CExplosion::CExplosion()
{

}

//----------------------------------------
// �G�N�X�v���[�W�����̃f�X�g���N�^
//----------------------------------------
CExplosion::~CExplosion()
{

}

//----------------------------------------
// �e�N�X�`���̐���(�ǂݍ���)
//----------------------------------------
HRESULT CExplosion::Load(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �e�N�X�`���̏���������
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\explosion000.png",
		&m_pTexture);

	return S_OK;
}

//----------------------------------------
// �e�N�X�`���̐���(�ǂݍ���)
//----------------------------------------
void CExplosion::Unload(void)
{
	// �e�N�X�`���̔j��
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//----------------------------------------
// �G�N�X�v���[�W�����̐�������
//----------------------------------------
CExplosion* CExplosion::Create(D3DXVECTOR3 pos)
{
	CExplosion* pExplosion;

	// �e�N�X�`���̐ݒ�
	CObject2D::SetUV(0.125f, 1.0f);

	// �T�C�Y�̐ݒ�
	//CObject2D::SetSize(0.0f, 0.0f);

	// �I�u�W�F�N�g2D�̐���
	pExplosion = new CExplosion;

	// ����������
	pExplosion->Init(pos);

	pExplosion->SetPosition(pos);

	// �e�N�X�`���̊��蓖��
	pExplosion->BindTexture(m_pTexture);

	return pExplosion;
}

//----------------------------------------
// �G�N�X�v���[�W�����̏���������
//----------------------------------------
HRESULT CExplosion::Init(D3DXVECTOR3 pos)
{
	CObject2D::Init(pos);

	return S_OK;
}

//----------------------------------------
// �G�N�X�v���[�W�����̏I������
//----------------------------------------
void CExplosion::Uninit(void)
{
	CObject2D::Uninit();
}

//----------------------------------------
// �G�N�X�v���[�W�����̍X�V����
//----------------------------------------
void CExplosion::Update(void)
{
	// �ʒu�̎擾
	D3DXVECTOR3 pos = CExplosion::GetPos();

	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	VERTEX_2D* pVtx = NULL; // ���_���ւ̃|�C���^

	CObject2D::TextureAnimation(8, 1, 5);

	CExplosion::SetPosition(pos);

	CObject2D::Update();

	//CExplosion::Release();
}

//----------------------------------------
// �G�N�X�v���[�W�����̕`�揈��
//----------------------------------------
void CExplosion::Draw(void)
{
	CObject2D::Draw();
}

//----------------------------------------
// �G�N�X�v���[�W�����̈ʒu�̐ݒ菈��
//----------------------------------------
void CExplosion::SetPosition(D3DXVECTOR3 pos)
{
	CObject2D::SetPosition(pos);
}