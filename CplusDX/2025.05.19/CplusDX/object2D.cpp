//==============================================================
//
// [object2D.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"object2D.h"
#include"renderer.h"
#include"manager.h"
#include"input.h"

//// �ÓI�����o�ϐ��錾
//LPDIRECT3DTEXTURE9 m_pTexture = {};
//LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff = {};
//D3DXVECTOR3 m_pos = {};

//----------------------------------------
// �R���X�g���N�^
//----------------------------------------
CObject2D::CObject2D()
{
	m_pTexture = NULL;
	m_pVtxBuff = NULL;
	m_pos = D3DXVECTOR3(NULL, NULL, NULL);
	//m_rot = D3DXVECTOR3(NULL, NULL, NULL);
}

//----------------------------------------
// �f�X�g���N�^
//----------------------------------------
CObject2D::~CObject2D()
{

}

//----------------------------------------
// ��������
//----------------------------------------
CObject2D* CObject2D::Create(void)
{
	CObject2D* pObject2D;

	// �I�u�W�F�N�g2D�̐���
	pObject2D = new CObject2D;

	// ����������
	pObject2D->Init();

	return pObject2D;
}

//----------------------------------------
// ����������
//----------------------------------------
HRESULT CObject2D::Init(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �e�N�X�`���̏���������
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\sample.png",
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
	pVtx[0].pos.x = m_pos.x - 50.0f;
	pVtx[0].pos.y = m_pos.y;
	pVtx[0].pos.z = 0.0f;
	pVtx[1].pos.x = m_pos.x + 50.0f;
	pVtx[1].pos.y = m_pos.y;
	pVtx[1].pos.z = 0.0f;
	pVtx[2].pos.x = m_pos.x - 50.0f;
	pVtx[2].pos.y = m_pos.y + 80.0f;
	pVtx[2].pos.z = 0.0f;
	pVtx[3].pos.x = m_pos.x + 50.0f;
	pVtx[3].pos.y = m_pos.y + 80.0f;
	pVtx[3].pos.z = 0.0f;
	//pVtx[0].pos = D3DXVECTOR3(450.0f, 150.0f, 0.0f);
	//pVtx[1].pos = D3DXVECTOR3(850.0f, 150.0f, 0.0f);
	//pVtx[2].pos = D3DXVECTOR3(450.0f, 550.0f, 0.0f);
	//pVtx[3].pos = D3DXVECTOR3(850.0f, 550.0f, 0.0f);

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
// �I������
//----------------------------------------
void CObject2D::Uninit(void)
{
	// �e�N�X�`���̔j��
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}

	// �I�u�W�F�N�g(�������g)�̔j��
	CObject::Release();
}

//----------------------------------------
// �X�V����
//----------------------------------------
void CObject2D::Update(void)
{
	CInputKeyboard* pInputKeyboard;

	// �L�[�{�[�h�̎擾
	pInputKeyboard = CManager::GetInputKeyboard();

	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	VERTEX_2D* pVtx = NULL; // ���_���ւ̃|�C���^

	// ���_�o�b�t�@�����b�N��,���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	int nSurprise = NULL;

	// ��ֈړ�
	if (pInputKeyboard->GetTrigger(DIK_UP) == true)
	{
		m_pos.y -= 50.0f;
	}
	// ���ֈړ�
	if (pInputKeyboard->GetTrigger(DIK_LEFT) == true)
	{
		m_pos.x -= 50.0f;
	}
	// ���ֈړ�
	if (pInputKeyboard->GetTrigger(DIK_DOWN) == true)
	{
		m_pos.y += 50.0f;
	}
	// �E�ֈړ�
	if (pInputKeyboard->GetTrigger(DIK_RIGHT) == true)
	{
		m_pos.x += 50.0f;
	}
	if (pInputKeyboard->GetPress(DIK_SPACE) == true)
	{
		nSurprise += 25.0f;
	}

	// ���_���W�̐ݒ�
	pVtx[0].pos.x = m_pos.x - 50.0f - nSurprise;
	pVtx[0].pos.y = m_pos.y - nSurprise;
	pVtx[0].pos.z = 0.0f;
	pVtx[1].pos.x = m_pos.x + 50.0f + nSurprise;
	pVtx[1].pos.y = m_pos.y - nSurprise;
	pVtx[1].pos.z = 0.0f;
	pVtx[2].pos.x = m_pos.x - 50.0f - nSurprise;
	pVtx[2].pos.y = m_pos.y + 80.0f + nSurprise;
	pVtx[2].pos.z = 0.0f;
	pVtx[3].pos.x = m_pos.x + 50.0f + nSurprise;
	pVtx[3].pos.y = m_pos.y + 80.0f + nSurprise;
	pVtx[3].pos.z = 0.0f;

	// ���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//----------------------------------------
// �`�揈��
//----------------------------------------
void CObject2D::Draw(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// ���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	// �e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_pTexture);

	// �v���C���[�̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

//----------------------------------------
// �ʒu�̐ݒ菈��
//----------------------------------------
void CObject2D::SetPosition(D3DXVECTOR3 pos)
{
	VERTEX_2D* pVtx; // ���_���ւ̃|�C���^

	// ���_�o�b�t�@�����b�N��,���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	m_pos = pos;

	pVtx[0].pos.x = m_pos.x - 50.0f;
	pVtx[0].pos.y = m_pos.y;
	pVtx[0].pos.z = 0.0f;
	pVtx[1].pos.x = m_pos.x + 50.0f;
	pVtx[1].pos.y = m_pos.y;
	pVtx[1].pos.z = 0.0f;
	pVtx[2].pos.x = m_pos.x - 50.0f;
	pVtx[2].pos.y = m_pos.y + 80.0f;
	pVtx[2].pos.z = 0.0f;
	pVtx[3].pos.x = m_pos.x + 50.0f;
	pVtx[3].pos.y = m_pos.y + 80.0f;
	pVtx[3].pos.z = 0.0f;

	// ���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}