//==============================================================
//
// [bullet.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"bullet.h"
#include"renderer.h"
#include"manager.h"
#include"input.h"

// �ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CBullet::m_pTexture = {};

//----------------------------------------
// �o���b�g�̃R���X�g���N�^
//----------------------------------------
CBullet::CBullet()
{
	m_move = {};
}

//----------------------------------------
// �o���b�g�̃f�X�g���N�^
//----------------------------------------
CBullet::~CBullet()
{

}

//----------------------------------------
// �e�N�X�`���̐���(�ǂݍ���)
//----------------------------------------
HRESULT CBullet::Load(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �e�N�X�`���̏���������
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\bullet000.png",
		&m_pTexture);

	return S_OK;
}

//----------------------------------------
// �e�N�X�`���̐���(�ǂݍ���)
//----------------------------------------
void CBullet::Unload(void)
{
	// �e�N�X�`���̔j��
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//----------------------------------------
// �o���b�g�̐�������
//----------------------------------------
CBullet* CBullet::Create(D3DXVECTOR3 pos)
{
	CBullet* pBullet;

	// �I�u�W�F�N�g2D�̐���
	pBullet = new CBullet;

	// ����������
	pBullet->Init(pos);

	pBullet->SetPosition(pos);

	// �e�N�X�`���̊��蓖��
	pBullet->BindTexture(m_pTexture);

	return pBullet;
}

//----------------------------------------
// �o���b�g�̏���������
//----------------------------------------
HRESULT CBullet::Init(D3DXVECTOR3 pos)
{
	CObject2D::Init(pos);

	return S_OK;
}

//----------------------------------------
// �o���b�g�̏I������
//----------------------------------------
void CBullet::Uninit(void)
{
	CObject2D::Uninit();
}

//----------------------------------------
// �o���b�g�̍X�V����
//----------------------------------------
void CBullet::Update(void)
{
	CObject2D::Update();
}

//----------------------------------------
// �o���b�g�̕`�揈��
//----------------------------------------
void CBullet::Draw(void)
{
	CObject2D::Draw();
}

//----------------------------------------
// �o���b�g�̈ʒu�̐ݒ菈��
//----------------------------------------
void CBullet::SetPosition(D3DXVECTOR3 pos)
{
	CObject2D::SetPosition(pos);
}