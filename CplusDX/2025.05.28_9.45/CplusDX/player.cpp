//==============================================================
//
// [player.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"player.h"
#include"renderer.h"
#include"manager.h"
#include"input.h"
#include"bullet.h"
#include"enemy.h"

// �ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CPlayer::m_pTexture = 0;

//----------------------------------------
// �v���C���[�̃R���X�g���N�^
//----------------------------------------
CPlayer::CPlayer()
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//----------------------------------------
// �v���C���[�̃f�X�g���N�^
//----------------------------------------
CPlayer::~CPlayer()
{

}

//----------------------------------------
// �e�N�X�`���̐���(�ǂݍ���)
//----------------------------------------
HRESULT CPlayer::Load(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �e�N�X�`���̏���������
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\runningman000.png",
		&m_pTexture);

	return S_OK;
}

//----------------------------------------
// �e�N�X�`���̐���(�ǂݍ���)
//----------------------------------------
void CPlayer::Unload(void)
{
	// �e�N�X�`���̔j��
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//----------------------------------------
// �v���C���[�̐�������
//----------------------------------------
CPlayer* CPlayer::Create(D3DXVECTOR3 pos, float xsize, float ysize)
{
	CPlayer* pPlayer;

	// �I�u�W�F�N�g2D�̐���
	pPlayer = new CPlayer;

	// �e�N�X�`���̐ݒ�
	pPlayer->SetUV(0.125f, 1.0f);

	// ����������
	pPlayer->Init(pos);

	pPlayer->SetPosition(pos);

	// �T�C�Y�̐ݒ�
	pPlayer->SetSize(xsize, ysize);

	// �e�N�X�`���̊��蓖��
	pPlayer->BindTexture(m_pTexture);

	return pPlayer;
}

//----------------------------------------
// �v���C���[�̏���������
//----------------------------------------
HRESULT CPlayer::Init(D3DXVECTOR3 pos)
{
	CObject2D::Init(pos);

	return S_OK;
}

//----------------------------------------
// �v���C���[�̏I������
//----------------------------------------
void CPlayer::Uninit(void)
{
	CObject2D::Uninit();
}

//----------------------------------------
// �v���C���[�̍X�V����
//----------------------------------------
void CPlayer::Update(void)
{
	CInputKeyboard* pInputKeyboard;

	// �L�[�{�[�h�̎擾
	pInputKeyboard = CManager::GetInputKeyboard();

	// �ʒu�̎擾
	D3DXVECTOR3 pos = GetPos();

	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	VERTEX_2D* pVtx = NULL; // ���_���ւ̃|�C���^

	if (pos.y >= 40.0f)
	{// ��ւ̈ړ�����

		if (pos.x >= 40.0f)
		{// ���ւ̈ړ�����

			if (pos.x <= SCREEN_WIDTH - 40.0f)
			{// �E�ւ̈ړ�����

				if (pos.y <= SCREEN_HEIGHT - 40.0f)
				{// ���ւ̈ړ�����

					// ��ֈړ�
					if (pInputKeyboard->GetPress(DIK_W) == true)
					{
						m_move.y -= PLAYER_SPEED;
					}
					// ���ֈړ�
					if (pInputKeyboard->GetPress(DIK_A) == true)
					{
						m_move.x -= PLAYER_SPEED;
					}
					// ���ֈړ�
					if (pInputKeyboard->GetPress(DIK_S) == true)
					{
						m_move.y += PLAYER_SPEED;
					}
					// �E�ֈړ�
					if (pInputKeyboard->GetPress(DIK_D) == true)
					{
						m_move.x += PLAYER_SPEED;
					}

					// �ʒu���X�V
					pos.x += m_move.x;
					pos.y += m_move.y;
					//m_move.y += 0.05f; // �d�͉��Z

					// �ړ��ʂ��X�V(����������)
					m_move.x += (0.0f - m_move.x) * 0.085f;
					m_move.y += (0.0f - m_move.y) * 0.085f;
				}
				else
				{// ���ւ̈ړ�����(��։����Ԃ�)
					pos.y -= 1.0f;
				}
			}
			else
			{// �E�ւ̈ړ�����(���։����Ԃ�)
				pos.x -= 1.0f;
			}
		}
		else
		{// ���ւ̈ړ�����(�E�։����Ԃ�)
			pos.x += 1.0f;
		}
	}
	else
	{// ��ւ̈ړ�����(���։����Ԃ�)
		pos.y += 1.0f;
	}
	// �ړ�����ƃA�j���[�V��������
	if (pInputKeyboard->GetPress(DIK_W) || pInputKeyboard->GetPress(DIK_A) || pInputKeyboard->GetPress(DIK_S) || pInputKeyboard->GetPress(DIK_D) == true)
	{
		CObject2D::TextureAnimation(8, 1, 15);
	}
	// �e�𔭎�
	if (pInputKeyboard->GetTrigger(DIK_SPACE) == true)
	{
		CBullet::Create(pos, 50.0f, 50.0f);
	}
	// �G�̍Đ�
	if (pInputKeyboard->GetTrigger(DIK_R) == true)
	{
		CEnemy::Create(D3DXVECTOR3(SCREEN_WIDTH - 100.0f, SCREEN_HEIGHT / 3.0f, 0.0f), 150.0f, 100.0f); // �G
		CEnemy::Create(D3DXVECTOR3(SCREEN_WIDTH - 100.0f, SCREEN_HEIGHT / 2.0f, 0.0f), 150.0f, 100.0f); // �G
	}

	CPlayer::SetPosition(pos);

	CObject2D::Update();
}

//----------------------------------------
// �v���C���[�̕`�揈��
//----------------------------------------
void CPlayer::Draw(void)
{
	CObject2D::Draw();
}

//----------------------------------------
// �v���C���[�̈ʒu�̐ݒ菈��
//----------------------------------------
void CPlayer::SetPosition(D3DXVECTOR3 pos)
{
	CObject2D::SetPosition(pos);
}

//----------------------------------------
// �v���C���[�̃T�C�Y�̐ݒ菈��
//----------------------------------------
void CPlayer::SetSize(float xsize, float ysize)
{
	CObject2D::SetSize(xsize, ysize);
}