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
#include"enemy.h"

// �ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CBullet::m_pTexture = 0;

//----------------------------------------
// �o���b�g�̃R���X�g���N�^
//----------------------------------------
CBullet::CBullet(/*int nPriority) : CObject2D(nPriority*/)
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

	// �I�u�W�F�N�g2D�̐���
	pBullet = new CBullet;

	// ����������
	pBullet->Init(pos);
	
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
	// �e�N�X�`���̐ݒ�
	CObject2D::SetUV(1.0f, 1.0f);

	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = 120;

	SetPosition(pos);

	CObject2D::Init(pos);

	// ��ނ̐ݒ菈��
	SetType(TYPE_BULLET);

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

	// �ʒu�̎擾
	D3DXVECTOR3 pos = GetPos();

	// �����̃J�E���g�_�E��
	m_nLife--;

	m_move.x = BULLET_SPEED;

	// �ʒu���X�V
	pos.x += m_move.x;
	pos.y += m_move.y;

	SetPosition(pos);

	 // �O�ɏo��, ���C�t���Ȃ��Ȃ�Ə���
	if (pos.x < 0.0f || pos.x > SCREEN_WIDTH || pos.y < 0.0f || pos.y > SCREEN_HEIGHT || m_nLife < 0)
	{
		CExplosion::Create(pos, 50.0f, 50.0f);

		//CBullet::Release();
		Uninit();
	}

	// �G�Ƃ̓����蔻��
	CollisionEnemy(pos);
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

//----------------------------------------
// �G�Ƃ̓����蔻��
//----------------------------------------
bool CBullet::CollisionEnemy(D3DXVECTOR3 pos)
{
	//for (int nCntPri = 0; nCntPri < MAX_PRI; nCntPri++)
	{
		for (int nCntObj = 0; nCntObj < MAX_OBJ; nCntObj++)
		{
			CObject* pObj; // �I�u�W�F�N�g�̏��ւ̃|�C���^

			// �I�u�W�F�N�g���擾
			pObj = GetObj(/*nCntPri, */nCntObj);

			if (pObj != NULL)
			{
				TYPE type;

				// ��ނ��擾
				type = pObj->GetType();

				if (type == TYPE_ENEMY)
				{// ��ނ��G�̏ꍇ

					D3DXVECTOR3 EnemyPos;

					EnemyPos = pObj->GetPos();

					if (pos.x <= EnemyPos.x + 40.0f
						&& pos.x >= EnemyPos.x - 40.0f
						&& pos.y >= EnemyPos.y - 55.0f
						&& pos.y <= EnemyPos.y + 55.0f)
					{
						// �����𐶐�
						CExplosion::Create(EnemyPos, 50.0f, 50.0f);

						// �G�̏I������
						pObj->Uninit();

						// �������g�̏I������
						CBullet::Release();

						return true;
					}
				}
			}
		}
	}

	return false;
}