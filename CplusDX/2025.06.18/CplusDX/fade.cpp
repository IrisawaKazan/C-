//==============================================================
//
// [fade.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"fade.h"
#include"manager.h"

//----------------------------------------
// �R���X�g���N�^
//----------------------------------------
CFade::CFade()
{
	m_pVtxBuff = nullptr;
	m_fade = FADE_NONE;
	m_modeNext = CRenderer::MODE_TITLE;
	m_color = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
}

//----------------------------------------
// �f�X�g���N�^
//----------------------------------------
CFade::~CFade()
{

}

//----------------------------------------
// ����������
//----------------------------------------
void CFade::Init(CRenderer::MODE modeNext)
{
	m_fade = FADE_IN;                                // �t�F�[�h�C����Ԃ�
	m_modeNext = modeNext;                           // ���̉��(���[�h)�ɂ��Ă���
	m_color = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f); // �����|���S��(�s����)�ɂ��Ă���

	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// ���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D),
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_2D* pVtx;

	// ���_�o�b�t�@�����b�N��,���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// ���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

	// rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	// ���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	// �e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	// ���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	//// ���[�h�̐ݒ�
	//SetMode(m_modeNext);
}

//----------------------------------------
// �I������
//----------------------------------------
void CFade::Uninit(void)
{
	// ���_�o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
}

//----------------------------------------
// �X�V����
//----------------------------------------
void CFade::Update(void)
{
	if (m_fade != FADE_NONE)
	{
		if (m_fade == FADE_IN)
		{// �t�F�[�h�C�����
			m_color.a -= 0.05f; // �|���S���𓧖��ɂ��Ă���

			if (m_color.a <= 0.0f)
			{
				m_color.a = 0.0f;
				m_fade = FADE_NONE; // �������Ă��Ȃ���Ԃ�
			}
		}
		else if (m_fade == FADE_OUT)
		{//�t�F�[�h�A�E�g���
			m_color.a += 0.05f; // �|���S����s�����ɂ��Ă���

			if (m_color.a >= 1.0f)
			{
				m_color.a = 1.0f;
				m_fade = FADE_IN; // �t�F�[�h�C����Ԃ�

				//// ���[�h�ݒ�(���̉�ʂɈڍs)
				//SetMode(m_modeNext);
			}
		}

		VERTEX_2D* pVtx;

		// ���_�o�b�t�@�����b�N��,���_�f�[�^�ւ̃|�C���^���擾
		m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

		// ���_�J���[�̐ݒ�
		pVtx[0].col = m_color;
		pVtx[1].col = m_color;
		pVtx[2].col = m_color;
		pVtx[3].col = m_color;

		//���_�o�b�t�@���A�����b�N����
		m_pVtxBuff->Unlock();
	}
}

//----------------------------------------
// �`�揈��
//----------------------------------------
void CFade::Draw(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// ���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	// �e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, NULL);

	// �|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,
		0,
		2);
}

//----------------------------------------
// �ݒ菈��
//----------------------------------------
void CFade::Set(CRenderer::MODE modeNext)
{
	m_fade = FADE_OUT;                           // �t�F�[�h�A�E�g��Ԃ�
	m_modeNext = modeNext;                       // ���̉��(���[�h)��ݒ�
	m_color = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f); // �����|���S��(����)�ɂ��Ă���
}

//----------------------------------------
// �擾����
//----------------------------------------
CFade::FADE CFade::Get(void)
{
	return m_fade;
}