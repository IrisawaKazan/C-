//==============================================================
//
// [background.h]
// Author: Irisawa Kazan
//
//==============================================================
#include"background.h"
#include"manager.h"
#include"renderer.h"
#include"object.h"

// �ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CBackground::m_pTexture = nullptr;

//----------------------------------------
// �o�b�N�O���E���h�̃R���X�g���N�^
//----------------------------------------
CBackground::CBackground(int nPriority) : CObject2D(nPriority)
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
		"data\\TEXTURE\\background000.jpg",
		&m_pTexture);

	return S_OK;
}

//----------------------------------------
// �e�N�X�`���̔j��
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
CBackground* CBackground::Create(D3DXVECTOR3 pos, float xsize, float ysize)
{
	CBackground* pBackground;

	int nNumAll = CObject::GetNumAll();

	if (nNumAll <= MAX_OBJ)
	{
		// �I�u�W�F�N�g2D�̐���
		pBackground = new CBackground;

		// �e�N�X�`���̐ݒ�
		pBackground->SetUV(1.0f, 1.0f);

		// ����������
		pBackground->Init(pos);

		pBackground->SetPosition(pos);

		// �T�C�Y�̐ݒ�
		pBackground->SetSize(xsize, ysize);

		// �e�N�X�`���̊��蓖��
		pBackground->BindTexture(m_pTexture);

		return pBackground;
	}

	return NULL;
}

//----------------------------------------
// �o�b�N�O���E���h�̏���������
//----------------------------------------
HRESULT CBackground::Init(D3DXVECTOR3 pos)
{
	CObject2D::Init(pos);

	// ��ނ̐ݒ菈��
	CObject::SetType(TYPE_BACKGROUND);

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

//----------------------------------------
// �o�b�N�O���E���h�̈ʒu�̐ݒ菈��
//----------------------------------------
void CBackground::SetPosition(D3DXVECTOR3 pos)
{
	CObject2D::SetPosition(pos);
}

//----------------------------------------
// �o�b�N�O���E���h�̃T�C�Y�̐ݒ菈��
//----------------------------------------
void CBackground::SetSize(float xsize, float ysize)
{
	CObject2D::SetSize(xsize, ysize);
}