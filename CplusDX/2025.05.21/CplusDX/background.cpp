//==============================================================
//
// [background.h]
// Author: Irisawa Kazan
//
//==============================================================
#include"background.h"
#include"manager.h"
#include"renderer.h"

// �ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CBackground::m_pTexture = {};

//----------------------------------------
// �o�b�N�O���E���h�̃R���X�g���N�^
//----------------------------------------
CBackground::CBackground()
{

}

//----------------------------------------
// �o�b�N�O���E���h�̃f�X�g���N�^
//----------------------------------------
CBackground::~CBackground()
{

}

//----------------------------------------
// �e�N�X�`���̐���(�ǂݍ���)
//----------------------------------------
HRESULT CBackground::Load(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �e�N�X�`���̏���������
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\background100.jpg",
		&m_pTexture);

	return S_OK;
}

//----------------------------------------
// �e�N�X�`���̐���(�ǂݍ���)
//----------------------------------------
void CBackground::Unload(void)
{
	// �e�N�X�`���̔j��
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//----------------------------------------
// ��������
//----------------------------------------
CBackground* CBackground::Create(D3DXVECTOR3 pos)
{
	CBackground* pBackground;

	// �I�u�W�F�N�g2D�̐���
	pBackground = new CBackground;

	// ����������
	pBackground->Init(pos);

	pBackground->SetPosition(pos);

	// �e�N�X�`���̊��蓖��
	pBackground->BindTexture(m_pTexture);

	return pBackground;
}

//----------------------------------------
// �o�b�N�O���E���h�̏���������
//----------------------------------------
HRESULT CBackground::Init(D3DXVECTOR3 pos)
{
	CObject2D::Init(pos);

	return S_OK;
}

//----------------------------------------
// �o�b�N�O���E���h�̏I������
//----------------------------------------
void CBackground::Uninit(void)
{
	CObject2D::Uninit();
}

//----------------------------------------
// �o�b�N�O���E���h�̍X�V����
//----------------------------------------
void CBackground::Update(void)
{
	CObject2D::Update();
}

//----------------------------------------
// �o�b�N�O���E���h�̕`�揈��
//----------------------------------------
void CBackground::Draw(void)
{
	CObject2D::Draw();
}