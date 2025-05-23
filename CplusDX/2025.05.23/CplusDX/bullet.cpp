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
#include"explosion.h"

// �ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CBullet::m_pTexture = 0;

//----------------------------------------
// �o���b�g�̃R���X�g���N�^
//----------------------------------------
CBullet::CBullet()
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = 0;
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
CBullet* CBullet::Create(D3DXVECTOR3 pos, float xsize, float ysize)
{
	CBullet* pBullet;

	// �e�N�X�`���̐ݒ�
	CObject2D::SetUV(1.0f, 1.0f);

	// �I�u�W�F�N�g2D�̐���
	pBullet = new CBullet;

	// ����������
	pBullet->Init(pos);
	
	pBullet->SetPosition(pos);

	// �T�C�Y�̐ݒ�
	pBullet->SetSize(xsize, ysize);

	// �e�N�X�`���̊��蓖��
	pBullet->BindTexture(m_pTexture);

	return pBullet;
}

//----------------------------------------
// �o���b�g�̏���������
//----------------------------------------
HRESULT CBullet::Init(D3DXVECTOR3 pos)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = 120;

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
	// �ʒu�̎擾
	D3DXVECTOR3 pos = CBullet::GetPos();

	// �����̃J�E���g�_�E��
	m_nLife--;

	m_move.x += BULLET_SPEED;

	// �ʒu���X�V
	pos.x += m_move.x;
	pos.y += m_move.y;

	CBullet::SetPosition(pos);

	CObject2D::Update();

	// �O�ɏo��, ���C�t���Ȃ��Ȃ�Ə���
	if (pos.x < 0.0f || pos.x > SCREEN_WIDTH || pos.y < 0.0f || pos.y > SCREEN_HEIGHT || m_nLife < 0)
	{
		CExplosion::Create(pos, 50.0f, 50.0f);

		CBullet::Release();
	}
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

//----------------------------------------
// �o���b�g�̃T�C�Y�̐ݒ菈��
//----------------------------------------
void CBullet::SetSize(float xsize, float ysize)
{
	CObject2D::SetSize(xsize, ysize);
}