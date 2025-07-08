//==============================================================
//
// [pause.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"pause.h"
#include"manager.h"
#include"renderer.h"
#include"input.h"

// �ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CPause::m_pTexture = nullptr;

//----------------------------------------
// �|�[�Y�̃R���X�g���N�^
//----------------------------------------
CPause::CPause(int nPriority)
{

}

//----------------------------------------
// �|�[�Y�̃f�X�g���N�^
//----------------------------------------
CPause::~CPause()
{
}

//----------------------------------------
// �e�N�X�`���̐���(�ǂݍ���)
//----------------------------------------
HRESULT CPause::Load(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �e�N�X�`���̏���������
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\pause001.png",
		&m_pTexture);

	return S_OK;
}

//----------------------------------------
// �e�N�X�`���̔j��
//----------------------------------------
void CPause::Unload(void)
{
	// �e�N�X�`���̔j��
	if (m_pTexture != nullptr)
	{
		m_pTexture->Release();
		m_pTexture = nullptr;
	}
}

//----------------------------------------
// ��������
//----------------------------------------
CPause* CPause::Create(D3DXVECTOR3 pos, float xsize, float ysize)
{
	CPause* pPause;

	int nNumAll = CObject::GetNumAll();

	if (nNumAll <= MAX_OBJ)
	{
		// �I�u�W�F�N�g2D�̐���
		pPause = new CPause;

		// �e�N�X�`���̐ݒ�
		pPause->SetUV(1.0f, 1.0f);

		// ����������
		pPause->Init(pos);

		pPause->SetPosition(pos);

		// �T�C�Y�̐ݒ�
		pPause->SetSize(xsize, ysize);

		// �e�N�X�`���̊��蓖��
		pPause->BindTexture(m_pTexture);

		return pPause;
	}

	return NULL;
}

//----------------------------------------
// �|�[�Y�̏���������
//----------------------------------------
HRESULT CPause::Init(D3DXVECTOR3 pos)
{
	CObject2D::Init(pos);

	// ��ނ̐ݒ菈��
	CObject::SetType(TYPE_PAUSE);

	return S_OK;
}

//----------------------------------------
// �|�[�Y�̏I������
//----------------------------------------
void CPause::Uninit(void)
{
	CObject2D::Uninit();
}

//----------------------------------------
// �|�[�Y�̍X�V����
//----------------------------------------
void CPause::Update(void)
{
	CObject2D::Update();
}

//----------------------------------------
// �|�[�Y�̕`�揈��
//----------------------------------------
void CPause::Draw(void)
{
	CObject2D::Draw();
}

//----------------------------------------
// �|�[�Y�̈ʒu�̐ݒ菈��
//----------------------------------------
void CPause::SetPosition(D3DXVECTOR3 pos)
{
	CObject2D::SetPosition(pos);
}

//----------------------------------------
// �|�[�Y�̃T�C�Y�̐ݒ菈��
//----------------------------------------
void CPause::SetSize(float xsize, float ysize)
{
	CObject2D::SetSize(xsize, ysize);
}