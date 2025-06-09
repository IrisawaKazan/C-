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
#include"score.h"

// �ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CBullet::m_pTexture[ETYPE_MAX] = {};

//----------------------------------------
// �o���b�g�̃R���X�g���N�^
//----------------------------------------
CBullet::CBullet(int nPriority) : CObject2D(nPriority)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = NULL;
	m_type = BTYPE_NONE;
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
		&m_pTexture[BTYPE_PLAYER]);

	// �e�N�X�`���̏���������
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\bullet001.png",
		&m_pTexture[BTYPE_ENEMY]);

	return S_OK;
}

//----------------------------------------
// �e�N�X�`���̔j��
//----------------------------------------
void CBullet::Unload(void)
{
	for (int nCount = 0; nCount < ETYPE_MAX; nCount++)
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
// �o���b�g�̐�������
//----------------------------------------
CBullet* CBullet::Create(D3DXVECTOR3 pos, float xsize, float ysize, BTYPE type)
{
	CBullet* pBullet;

	int nNumAll = CObject::GetNumAll();

	if (nNumAll <= MAX_OBJ)
	{
		// �I�u�W�F�N�g2D�̐���
		pBullet = new CBullet;

		pBullet->m_type = type;

		// ����������
		pBullet->Init(pos);

		// �T�C�Y�̐ݒ�
		pBullet->SetSize(xsize, ysize);

		// �e�N�X�`���̊��蓖��
		pBullet->BindTexture(m_pTexture[type]);

		return pBullet;
	}

	return NULL;
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
	CObject::SetType(TYPE_BULLET);

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
	D3DXVECTOR3 pos = GetPos();

	// �����̃J�E���g�_�E��
	m_nLife--;

	switch (m_type)
	{
	case BTYPE_PLAYER:
		m_move.x = PBULLET_SPEED;
		// �O�ɏo��, ���C�t���Ȃ��Ȃ�Ə���
		if (pos.x < 0.0f || pos.x > SCREEN_WIDTH || pos.y < 0.0f || pos.y > SCREEN_HEIGHT || m_nLife < 0)
		{
			CExplosion::Create(pos, 50.0f, 50.0f, CExplosion::EXPLOTYPE_000);

			Uninit();
			return;
		}
		break;

	case BTYPE_ENEMY:
		m_move.x = -EBULLET_SPEED;
		// �O�ɏo��, ���C�t���Ȃ��Ȃ�Ə���
		if (pos.x < 0.0f || pos.x > SCREEN_WIDTH || pos.y < 0.0f || pos.y > SCREEN_HEIGHT || m_nLife < 0)
		{
			CExplosion::Create(pos, 50.0f, 50.0f, CExplosion::EXPLOTYPE_003);

			Uninit();
			return;
		}
		break;

	default:
		break;
	}

	// �ʒu���X�V
	pos.x += m_move.x;
	pos.y += m_move.y;

	SetPosition(pos);

	/*// �O�ɏo��, ���C�t���Ȃ��Ȃ�Ə���
	if (pos.x < 0.0f || pos.x > SCREEN_WIDTH || pos.y < 0.0f || pos.y > SCREEN_HEIGHT || m_nLife < 0)
	{
		CExplosion::Create(pos, 50.0f, 50.0f, CExplosion::EXPLOTYPE_000);

		//CBullet::Release();
		Uninit();
		return;
	}*/

	CObject2D::Update();

	Collision(pos);
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
// �o���b�g�̃^�C�v�̐ݒ菈��
//----------------------------------------
void CBullet::SetType(BTYPE type)
{
	m_type = type;
}

//----------------------------------------
// �o���b�g�̃^�C�v�̎擾����
//----------------------------------------
CBullet::BTYPE CBullet::GetType(void)
{
	return m_type;
}

//----------------------------------------
// �����蔻��
//----------------------------------------
bool CBullet::Collision(D3DXVECTOR3 pos)
{
	for (int nCntPri = 0; nCntPri < MAX_PRI; nCntPri++)
	{
		for (int nCntObj = 0; nCntObj < MAX_OBJ; nCntObj++)
		{
			CObject* pObj; // �I�u�W�F�N�g�̏��ւ̃|�C���^

			// �I�u�W�F�N�g���擾
			pObj = GetObj(nCntPri, nCntObj);

			if (pObj != NULL)
			{
				TYPE type;

				// ��ނ��擾
				type = pObj->GetType();

				if (type == TYPE_ENEMY)
				{// ��ނ��G�̏ꍇ

					BTYPE btype;

					btype = GetType();

					if (btype == BTYPE_PLAYER)
					{
						D3DXVECTOR3 EnemyPos;

						EnemyPos = pObj->GetPos();

						if (pos.x <= EnemyPos.x + 40.0f
							&& pos.x >= EnemyPos.x - 40.0f
							&& pos.y >= EnemyPos.y - 55.0f
							&& pos.y <= EnemyPos.y + 55.0f)
						{
							// �����𐶐�
							CExplosion::Create(EnemyPos, 50.0f, 50.0f, CExplosion::EXPLOTYPE_002);

							// �X�R�A���Z
							CScore::AddScore(1);

							// �G�̏I������
							pObj->Uninit();

							// �������g�̏I������
							Uninit();

							return true;
						}
					}
				}
				if (type == TYPE_PLAYER)
				{// ��ނ��v���C���[�̏ꍇ

					BTYPE btype;

					btype = GetType();

					if (btype == BTYPE_ENEMY)
					{
						D3DXVECTOR3 PlayerPos;

						PlayerPos = pObj->GetPos();

						if (pos.x <= PlayerPos.x + 40.0f
							&& pos.x >= PlayerPos.x - 40.0f
							&& pos.y >= PlayerPos.y - 55.0f
							&& pos.y <= PlayerPos.y + 55.0f)
						{
							// �����𐶐�
							CExplosion::Create(PlayerPos, 50.0f, 50.0f, CExplosion::EXPLOTYPE_001);

							// �G�̏I������
							pObj->Uninit();

							// �������g�̏I������
							Uninit();

							return true;
						}
					}
				}
			}
		}
	}

	return false;
}