//==============================================================
//
// [playerX.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"playerX.h"
#include"model.h"
#include"manager.h"
#include"renderer.h"

//----------------------------------------
// �R���X�g���N�^
//----------------------------------------
CPlayerX::CPlayerX()
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_mtxWorld = D3DXMATRIX();

	for (int nCnt = 0; nCnt < MAX_PARTS; nCnt++)
	{
		m_apModel[nCnt] = nullptr;
	}

	m_nNumModel = NULL;
}

//----------------------------------------
// �f�X�g���N�^
//----------------------------------------
CPlayerX::~CPlayerX()
{

}

//----------------------------------------
// ��������
//----------------------------------------
CPlayerX* CPlayerX::Create(D3DXVECTOR3 pos)
{
	CPlayerX* pPlayerX;

	// �I�u�W�F�N�gX�̐���
	pPlayerX = new CPlayerX;

	// ����������
	pPlayerX->Init(pos);

	// �ʒu�̐ݒ�
	pPlayerX->SetPosition(pos);

	return pPlayerX;
}

//----------------------------------------
// ����������
//----------------------------------------
HRESULT CPlayerX::Init(D3DXVECTOR3 pos)
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	CModel* pModel;

	// ���f���̐���(�S�p�[�c��)
	m_apModel[0] = pModel->Create(pos);


	// �e���f���̐ݒ�(�S�p�[�c��)
	m_apModel[0]->SetParent(m_apModel[0]);


	return S_OK;
}

//----------------------------------------
// �I������
//----------------------------------------
void CPlayerX::Uninit(void)
{
	// �I�u�W�F�N�g(�������g)�̔j��
	this->Release();
}

//----------------------------------------
// �X�V����
//----------------------------------------
void CPlayerX::Update(void)
{

}

//----------------------------------------
// �`�揈��
//----------------------------------------
void CPlayerX::Draw(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �v�Z�p�̃}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;

	D3DMATERIAL9 matDef; // ���݂̃}�e���A���ۑ��p

	// ���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	// �����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// �ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// ���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);



	// �ۑ����Ă����}�e���A�������ɖ߂�
	pDevice->SetMaterial(&matDef);
}

//----------------------------------------
// �ʒu�̐ݒ菈��
//----------------------------------------
void CPlayerX::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//----------------------------------------
// �ʒu�̎擾����
//----------------------------------------
D3DXVECTOR3 CPlayerX::GetPos(void)
{
	return m_pos;
}