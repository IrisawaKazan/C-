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
LPDIRECT3DTEXTURE9 CExplosion::m_pTexture[MAX_PLOTEX] = {};

//----------------------------------------
// �G�N�X�v���[�W�����̃R���X�g���N�^
//----------------------------------------
CExplosion::CExplosion(int nPriority) : CObject2D(nPriority)
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
		&m_pTexture[EXPLOTYPE_000]);

	// �e�N�X�`���̏���������
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\explosion001.png",
		&m_pTexture[EXPLOTYPE_001]);

	// �e�N�X�`���̏���������
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\explosion002.png",
		&m_pTexture[EXPLOTYPE_002]);

	return S_OK;
}

//----------------------------------------
// �e�N�X�`���̐���(�ǂݍ���)
//----------------------------------------
void CExplosion::Unload(void)
{
	for (int nCount = 0; nCount < MAX_PLOTEX; nCount++)
	{
		// �e�N�X�`���̔j��
		if (m_pTexture[nCount] != NULL)
		{
			m_pTexture[nCount]->Release();
			m_pTexture[nCount] = NULL;
		}
	}
}

//----------------------------------------
// �G�N�X�v���[�W�����̐�������
//----------------------------------------
CExplosion* CExplosion::Create(D3DXVECTOR3 pos, float xsize, float ysize, EXPLOTYPE type)
{
	CExplosion* pExplosion;

	int nNumAll = CObject::GetNumAll();

	if (nNumAll <= MAX_OBJ)
	{
		// �I�u�W�F�N�g2D�̐���
		pExplosion = new CExplosion;

		// ����������
		pExplosion->Init(pos);

		// �e�N�X�`���̊��蓖��
		pExplosion->BindTexture(m_pTexture[type]);

		// �T�C�Y�̐ݒ�
		pExplosion->SetSize(xsize, ysize);

		// �e�N�X�`���̐ݒ�
		pExplosion->SetUV(0.125f, 1.0f);

		return pExplosion;
	}

	return NULL;
}

//----------------------------------------
// �G�N�X�v���[�W�����̏���������
//----------------------------------------
HRESULT CExplosion::Init(D3DXVECTOR3 pos)
{
	CObject2D::Init(pos);

	SetPosition(pos);

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
	CObject2D::Update();

	// �ʒu�̎擾
	D3DXVECTOR3 pos = GetPos();

	CObject2D::SetPosition(pos);

	// �e�N�X�`���̐ݒ�
	CObject2D::SetUV(0.125f, 1.0f);

	CObject2D::TextureAnimation(8, 1, 12);

	int nCntAnim = CObject2D::GetCntAnim();
	int nPtAnim = CObject2D::GetPtAnim();

	if (nCntAnim == 0 && nPtAnim == 0)
	{
		Uninit();
	}
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

//----------------------------------------
// �v���C���[�̃T�C�Y�̐ݒ菈��
//----------------------------------------
void CExplosion::SetSize(float xsize, float ysize)
{
	CObject2D::SetSize(xsize, ysize);
}