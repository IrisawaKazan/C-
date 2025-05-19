//==============================================================
//
// [background.h]
// Author: Irisawa Kazan
//
//==============================================================
#include"background.h"
#include"manager.h"

//----------------------------------------
// ��������
//----------------------------------------
CBackground* CBackground::Create(void)
{
	CBackground* pCBackground;

	// �I�u�W�F�N�g2D�̐���
	pCBackground = new CBackground;

	// ����������
	pCBackground->Init();

	return pCBackground;
}

//----------------------------------------
// �o�b�N�O���E���h�̃R���X�g���N�^
//----------------------------------------
CBackground::CBackground()
{

}

//----------------------------------------
// �o�b�N�O���E���h�̃f�X�g���N�^
//----------------------------------------
CBackground::~CBackground()
{

}

//----------------------------------------
// �o�b�N�O���E���h�̏���������
//----------------------------------------
HRESULT CBackground::Init(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �e�N�X�`���̏���������
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\background100.jpg",
		&m_pTexture);

	// ���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_2D* pVtx; // ���_���ւ̃|�C���^

	// ���_�o�b�t�@�����b�N��,���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// ���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDTH, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f);

	// rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	// ���_�J���[�̐ݒ�
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	// �e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	// ���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

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

}

//----------------------------------------
// �o�b�N�O���E���h�̕`�揈��
//----------------------------------------
void CBackground::Draw(void)
{
	CObject2D::Draw();
}