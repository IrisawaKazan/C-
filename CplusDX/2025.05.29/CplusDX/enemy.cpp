//==============================================================
//
// [enemy.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"enemy.h"
#include"renderer.h"
#include"manager.h"
#include"input.h"
#include"explosion.h"
#include"bullet.h"

// �ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CEnemy::m_pTexture[MAX_ENEMYTEX] = {};

//----------------------------------------
// �G�l�~�[�̃R���X�g���N�^
//----------------------------------------
CEnemy::CEnemy(int nPriority) : CObject2D(nPriority)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = 0;
	m_type = ETYPE_NONE;
	m_nCntTimer = 0;
}

//----------------------------------------
// �G�l�~�[�̃f�X�g���N�^
//----------------------------------------
CEnemy::~CEnemy()
{

}

//----------------------------------------
// �e�N�X�`���̐���(�ǂݍ���)
//----------------------------------------
HRESULT CEnemy::Load(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �e�N�X�`���̏���������
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\enemy000.png",
		&m_pTexture[ETYPE_000]);

	// �e�N�X�`���̏���������
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\enemy001.png",
		&m_pTexture[ETYPE_001]);

	// �e�N�X�`���̏���������
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\enemy002.png",
		&m_pTexture[ETYPE_002]);

	// �e�N�X�`���̏���������
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\enemy003.png",
		&m_pTexture[ETYPE_003]);

	return S_OK;
}

//----------------------------------------
// �e�N�X�`���̔j��
//----------------------------------------
void CEnemy::Unload(void)
{
	for (int nCount = 0; nCount < MAX_ENEMYTEX; nCount++)
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
// �G�l�~�[�̐�������
//----------------------------------------
CEnemy* CEnemy::Create(D3DXVECTOR3 pos, float xsize, float ysize, ETYPE type)
{
	CEnemy* pEnemy;

	int nNumAll = CObject::GetNumAll();

	if (nNumAll <= MAX_OBJ)
	{
		// �I�u�W�F�N�g2D�̐���
		pEnemy = new CEnemy;

		// �e�N�X�`���̐ݒ�
		pEnemy->SetUV(1.0f, 1.0f);

		// ����������
		pEnemy->Init(pos);

		pEnemy->SetPosition(pos);

		// �T�C�Y�̐ݒ�
		pEnemy->SetSize(xsize, ysize);

		// �e�N�X�`���̊��蓖��
		pEnemy->BindTexture(m_pTexture[type]);

		return pEnemy;
	}

	return NULL;
}

//----------------------------------------
// �G�l�~�[�̏���������
//----------------------------------------
HRESULT CEnemy::Init(D3DXVECTOR3 pos)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = 3;
	m_nCntTimer = 180;

	CObject2D::Init(pos);

	// ��ނ̐ݒ菈��
	CObject::SetType(TYPE_ENEMY);

	return S_OK;
}

//----------------------------------------
// �G�l�~�[�̏I������
//----------------------------------------
void CEnemy::Uninit(void)
{
	CObject2D::Uninit();
}

//----------------------------------------
// �G�l�~�[�̍X�V����
//----------------------------------------
void CEnemy::Update(void)
{
	// �ʒu�̎擾
	D3DXVECTOR3 pos = CEnemy::GetPos();

	// �ʒu���X�V
	pos.x += m_move.x;
	pos.y += m_move.y;

	// �e�̐���
	//CBullet::Create(pos, 50.0f, 50.0f, CBullet::BTYPE_ENEMY);

	CEnemy::SetPosition(pos);

	CObject2D::Update();
}

//----------------------------------------
// �G�l�~�[�̕`�揈��
//----------------------------------------
void CEnemy::Draw(void)
{
	CObject2D::Draw();
}

//----------------------------------------
// �G�l�~�[�̈ʒu�̐ݒ菈��
//----------------------------------------
void CEnemy::SetPosition(D3DXVECTOR3 pos)
{
	CObject2D::SetPosition(pos);
}

//----------------------------------------
// �G�l�~�[�̃T�C�Y�̐ݒ菈��
//----------------------------------------
void CEnemy::SetSize(float xsize, float ysize)
{
	CObject2D::SetSize(xsize, ysize);
}

//----------------------------------------
// �G�l�~�[�̃^�C�v�̐ݒ菈��
//----------------------------------------
void CEnemy::SetType(ETYPE type)
{
	m_type = type;
}

//----------------------------------------
// �G�l�~�[�̃^�C�v�̎擾����
//----------------------------------------
CEnemy::ETYPE CEnemy::GetType(void)
{
	return m_type;
}