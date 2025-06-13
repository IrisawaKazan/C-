//==============================================================
//
// [objectX.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"objectX.h"
#include"manager.h"
#include"renderer.h"
#include"input.h"

//----------------------------------------
// �R���X�g���N�^
//----------------------------------------
CObjectX::CObjectX(int nPriority) : CObject(nPriority)
{
	m_pTexture = nullptr;
	m_pMesh = nullptr;
	m_pBuffMat = nullptr;
	m_dwNumMat = NULL;
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_mtxWorld = D3DXMATRIX();
}

//----------------------------------------
// �f�X�g���N�^
//----------------------------------------
CObjectX::~CObjectX()
{

}

//----------------------------------------
// ��������
//----------------------------------------
CObjectX* CObjectX::Create(D3DXVECTOR3 pos)
{
	CObjectX* pObjectX;

	// �I�u�W�F�N�gX�̐���
	pObjectX = new CObjectX;

	// ����������
	pObjectX->Init(pos);

	// �ʒu�̐ݒ�
	pObjectX->SetPosition(pos);

	return pObjectX;
}

//----------------------------------------
// ����������
//----------------------------------------
HRESULT CObjectX::Init(D3DXVECTOR3 pos)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// X�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX("data\\MODEL\\BOX.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&m_pBuffMat,
		NULL,
		&m_dwNumMat,
		&m_pMesh);

	D3DXMATERIAL* pMat = nullptr; // �}�e���A���ւ̃|�C���^

	// �}�e���A���̃f�[�^�ւ̃|�C���^���擾
	pMat = (D3DXMATERIAL*)m_pBuffMat->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)m_dwNumMat; nCntMat++)
	{
		if (pMat[nCntMat].pTextureFilename != nullptr)
		{
			// ���̃t�@�C�������g�p���ăe�N�X�`����ǂݍ���


			// �e�N�X�`���̓ǂݍ���


			D3DXCreateTextureFromFile(pDevice, pMat[nCntMat].pTextureFilename, &m_pTexture);
		}
	}

	return S_OK;
}

//----------------------------------------
// �I������
//----------------------------------------
void CObjectX::Uninit(void)
{
	// ���b�V���̔j��
	if (m_pMesh != nullptr)
	{
		m_pMesh->Release();
		m_pMesh = nullptr;
	}

	// �}�e���A���̔j��
	if (m_pBuffMat != nullptr)
	{
		m_pBuffMat->Release();
		m_pBuffMat = nullptr;
	}

	CObject::Release();
}

//----------------------------------------
// �X�V����
//----------------------------------------
void CObjectX::Update(void)
{
	CInputKeyboard* pInputKeyboard;

	// �L�[�{�[�h�̎擾
	pInputKeyboard = CManager::GetInputKeyboard();

	// �v���C���[�ړ�
	if (pInputKeyboard->GetPress(DIK_A) == true)
	{// ��
		if (pInputKeyboard->GetPress(DIK_W) == true)
		{// �����Ɉړ�
			// ��
			m_pos.x -= MAX_PMOVE / sqrtf(4.0f);
			m_rot.y = m_rot.y;

			// ��
			m_pos.z += MAX_PMOVE / sqrtf(4.0f);
			m_rot.y = m_rot.y;
		}
		else if (pInputKeyboard->GetPress(DIK_S) == true)
		{// ����O�Ɉړ�
			// ��
			m_pos.x -= MAX_PMOVE / sqrtf(4.0f);
			m_rot.y = m_rot.y;

			// ��O
			m_pos.z -= MAX_PMOVE / sqrtf(4.0f);
			m_rot.y = m_rot.y;
		}
		else
		{// ���Ɉړ�
			m_pos.x -= MAX_PMOVE;
			m_rot.y = m_rot.y;
		}
	}
	if (pInputKeyboard->GetPress(DIK_D) == true)
	{// �E
		if (pInputKeyboard->GetPress(DIK_W) == true)
		{// �E�Ɉړ�
			// �E
			m_pos.x += MAX_PMOVE / sqrtf(4.0f);
			m_rot.y = m_rot.y;

			// ��
			m_pos.z += MAX_PMOVE / sqrtf(4.0f);
			m_rot.y = m_rot.y;
		}
		else if (pInputKeyboard->GetPress(DIK_S) == true)
		{// �E��O�Ɉړ�
			// �E
			m_pos.x += MAX_PMOVE / sqrtf(4.0f);
			m_rot.y = m_rot.y;

			// ��O
			m_pos.z -= MAX_PMOVE / sqrtf(4.0f);
			m_rot.y = m_rot.y;
		}
		else
		{// �E�Ɉړ�
			m_pos.x += MAX_PMOVE;
			m_rot.y = m_rot.y;
		}
	}
	if (pInputKeyboard->GetPress(DIK_W) == true)
	{// ��
		m_pos.z += MAX_PMOVE;
		m_rot.y = m_rot.y;
	}
	if (pInputKeyboard->GetPress(DIK_S) == true)
	{// ��O
		m_pos.z -= MAX_PMOVE;
		m_rot.y = m_rot.y;
	}

	// ��Ɍ�ނ���
	//m_pos.z -= 0.5f;
}

//----------------------------------------
// �`�揈��
//----------------------------------------
void CObjectX::Draw(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �v�Z�p�̃}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;

	D3DMATERIAL9 matDef; // ���݂̃}�e���A���ۑ��p

	D3DXMATERIAL* pMat; // �}�e���A���f�[�^�ւ̃|�C���^

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

	// ���݂̃}�e���A�����擾
	pDevice->GetMaterial(&matDef);

	// �}�e���A���̃f�[�^�ւ̃|�C���^���擾
	pMat = (D3DXMATERIAL*)m_pBuffMat->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)m_dwNumMat; nCntMat++)
	{
		// �}�e���A���̐ݒ�
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		// �e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, m_pTexture); // ����NULL

		// ���f��(�p�[�c)�̕`��
		m_pMesh->DrawSubset(nCntMat);
	}

	// �ۑ����Ă����}�e���A�������ɖ߂�
	pDevice->SetMaterial(&matDef);
}

//----------------------------------------
// �ʒu�̐ݒ菈��
//----------------------------------------
void CObjectX::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//----------------------------------------
// �ʒu�̎擾����
//----------------------------------------
D3DXVECTOR3 CObjectX::GetPos(void)
{
	return m_pos;
}