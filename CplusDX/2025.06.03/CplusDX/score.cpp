//==============================================================
//
// [score.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"score.h"
#include"manager.h"
#include"renderer.h"
#include"number.h"

// �ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CScore::m_pTexture = {};

//----------------------------------------
// �R���X�g���N�^
//----------------------------------------
CScore::CScore(int nPriority) : CObject(nPriority)
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	for (int nCnt = 0; nCnt < MAX_SCORE; nCnt++)
	{
		m_apScore[nCnt] = NULL;
	}
}

//----------------------------------------
// �f�X�g���N�^
//----------------------------------------
CScore::~CScore()
{

}

//----------------------------------------
// �e�N�X�`���̐���(�ǂݍ���)
//----------------------------------------
HRESULT CScore::Load(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �e�N�X�`���̏���������
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\number000.png",
		&m_pTexture);

	return S_OK;
}

//----------------------------------------
// �e�N�X�`���̔j��
//----------------------------------------
void CScore::Unload(void)
{
	// �e�N�X�`���̔j��
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//----------------------------------------
// �X�R�A�̐�������
//----------------------------------------
CScore* CScore::Create(D3DXVECTOR3 pos, float xsize, float ysize)
{


	return NULL;
}

//----------------------------------------
// �X�R�A�̏���������
//----------------------------------------
HRESULT CScore::Init(D3DXVECTOR3 pos)
{


	return S_OK;
}

//----------------------------------------
// �X�R�A�̏I������
//----------------------------------------
void CScore::Uninit(void)
{

}

//----------------------------------------
// �X�R�A�̍X�V����
//----------------------------------------
void CScore::Update(void)
{

}

//----------------------------------------
// �X�R�A�̕`�揈��
//----------------------------------------
void CScore::Draw(void)
{

}

void CScore::SetPosition(D3DXVECTOR3 pos)
{
}

D3DXVECTOR3 CScore::GetPos(void)
{
	return D3DXVECTOR3();
}
