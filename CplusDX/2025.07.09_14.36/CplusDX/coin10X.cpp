//==============================================================
//
// [coin10X.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"coin10X.h"
#include"renderer.h"
#include"input.h"
#include"objectX.h"

//----------------------------------------
// �R���X�g���N�^
//----------------------------------------
CCoin10X::CCoin10X(int nPriority) : CObject(nPriority)
{
	m_pTexture = nullptr;
	m_pMesh = nullptr;
	m_pBuffMat = nullptr;
	m_dwNumMat = NULL;

	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_mtxWorld = D3DXMATRIX();

	m_fRotation = 0.0f;
	m_type = COIN10_NONE;
	m_vtxMin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_vtxMax = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//----------------------------------------
// �f�X�g���N�^
//----------------------------------------
CCoin10X::~CCoin10X()
{

}

//----------------------------------------
// ��������
//----------------------------------------
CCoin10X* CCoin10X::Create(D3DXVECTOR3 pos, COIN10 type)
{
	CCoin10X* pCoin10X;

	int nNumAll = CObject::GetNumAll();

	if (nNumAll <= MAX_OBJ)
	{
		// �I�u�W�F�N�gX�̐���
		pCoin10X = new CCoin10X;

		// ����������
		pCoin10X->Init(pos);

		// �^�C�v�̐ݒ�
		pCoin10X->SetType(type);

		// �ʒu�̐ݒ�
		pCoin10X->SetPosition(pos);

		return pCoin10X;
	}

	return NULL;
}

//----------------------------------------
// ����������
//----------------------------------------
HRESULT CCoin10X::Init(D3DXVECTOR3 pos)
{
	// ��ނ̐ݒ菈��
	CObject::SetType(TYPE_COIN10);

	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// X�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX("data\\MODEL\\score_coin10.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&m_pBuffMat,
		NULL,
		&m_dwNumMat,
		&m_pMesh);

	int nNumVtx;    // ���_��
	DWORD sizeFVF;  // ���_�t�H�[�}�b�g�̃T�C�Y
	BYTE* pVtxBuff; // ���_�o�b�t�@�̃|�C���^

	// ���_���̎擾
	nNumVtx = m_pMesh->GetNumVertices();

	// ���_�t�H�[�}�b�g�̃T�C�Y���擾
	sizeFVF = D3DXGetFVFVertexSize(m_pMesh->GetFVF());

	// ���_�o�b�t�@�̃��b�N
	m_pMesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBuff);

	for (int nCntVtx = 0; nCntVtx < nNumVtx; nCntVtx++)
	{
		// ���_���W�̑��
		D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVtxBuff;

		// ���_���W���r���ă��f���̍ŏ��l,�ő�l���擾
		if (vtx.x <= m_vtxMin.x)
		{
			m_vtxMin.x = vtx.x;
		}

		if (vtx.y <= m_vtxMin.y)
		{
			m_vtxMin.y = vtx.y;
		}

		if (vtx.z <= m_vtxMin.z)
		{
			m_vtxMin.z = vtx.z;
		}

		if (vtx.x <= m_vtxMax.x)
		{
			m_vtxMax.x = vtx.x;
		}

		if (vtx.y <= m_vtxMax.y)
		{
			m_vtxMax.y = vtx.y;
		}

		if (vtx.z <= m_vtxMax.z)
		{
			m_vtxMax.z = vtx.z;
		}

		// ���_�t�H�[�}�b�g�̃T�C�Y���|�C���^��i�߂�
		pVtxBuff += sizeFVF;
	}

	// ���_�o�b�t�@�̃A�����b�N
	m_pMesh->UnlockVertexBuffer();

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
void CCoin10X::Uninit(void)
{
	// �e�N�X�`���̔j��
	if (m_pTexture != nullptr)
	{
		m_pTexture = nullptr;
	}

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

	this->Release();
}

//----------------------------------------
// �X�V����
//----------------------------------------
void CCoin10X::Update(void)
{
	CObjectX* pObjectX = CManager::GetObjectX();

	if (pObjectX->GetEnable() == true)
	{
		switch (m_type)
		{
		case COIN10_000_A:
			m_pos.x += 1.5f;
			// ���[�e�[�V����
			m_fRotation += 1.0f;

			m_rot = D3DXVECTOR3(0.0f, 0.0f, m_fRotation / 17.5f/* ��鑬�x */);
			break;

		case COIN10_000_B:
			m_pos.x -= 1.5f;
			// ���[�e�[�V����
			m_fRotation -= 1.0f;

			m_rot = D3DXVECTOR3(0.0f, 0.0f, m_fRotation / 17.5f/* ��鑬�x */);
			break;

		default:
			break;
		}

		// �O�ɏo��Ə���
		if (m_pos.x < -COIN10_UNINIT_POS || m_pos.x > COIN10_UNINIT_POS)
		{
			Uninit();

			return;
		}

		// �����蔻��
		Collision();
	}
}

//----------------------------------------
// �`�揈��
//----------------------------------------
void CCoin10X::Draw(void)
{
	CObjectX* pObjectX = CManager::GetObjectX();

	if (pObjectX->GetEnable() == true)
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
}

//----------------------------------------
// �ʒu�̐ݒ菈��
//----------------------------------------
void CCoin10X::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//----------------------------------------
// �����̐ݒ菈��
//----------------------------------------
void CCoin10X::SetRotation(D3DXVECTOR3 rot)
{
	m_rot = rot;
}

//----------------------------------------
// �ʒu�̎擾����
//----------------------------------------
D3DXVECTOR3 CCoin10X::GetPos(void)
{
	return m_pos;
}

//----------------------------------------
// �����̎擾����
//----------------------------------------
D3DXVECTOR3 CCoin10X::GetRot(void)
{
	return m_rot;
}

//----------------------------------------
// �^�C�v�̐ݒ菈��
//----------------------------------------
void CCoin10X::SetType(COIN10 type)
{
	m_type = type;
}

//----------------------------------------
// �^�C�v�̎擾����
//----------------------------------------
CCoin10X::COIN10 CCoin10X::GetType(void)
{
	return m_type;
}

//----------------------------------------
// �����蔻��̏���
//----------------------------------------
void CCoin10X::Collision(void)
{
	CObjectX* pObjectX = CManager::GetObjectX();

	// ���E�̔���̍L��
	float fNum = 2.0f;

	if (pObjectX->GetEnable() == true)
	{
		// �v���C���[�̈ʒu�̎擾
		D3DXVECTOR3 pos = pObjectX->GetPos();

		// �v���C���[�̑O��̈ʒu�̎擾
		D3DXVECTOR3 posOld = pObjectX->GetPosOld();

		// �v���C���[�̃T�C�Y�̎擾
		D3DXVECTOR3 size = pObjectX->GetSize();

		// ���E�̂߂荞�ݔ���
		if (pos.z + size.z / fNum > m_pos.z + m_vtxMax.z &&
			pos.z + size.z / fNum < m_pos.z - m_vtxMin.z * 2.0f)
		{
			// ������E��
			if (posOld.x + size.x / fNum > m_pos.x + m_vtxMin.x &&
				pos.x + size.x / fNum < m_pos.x - m_vtxMin.x)
			{
				// �X�R�A���Z
				CScore::AddScore(10);

				Uninit();

				return;
			}
			// �E���獶��
			if (posOld.x - size.x / fNum < m_pos.x - m_vtxMax.x &&
				pos.x - size.x / fNum > m_pos.x + m_vtxMax.x)
			{
				// �X�R�A���Z
				CScore::AddScore(10);

				Uninit();

				return;
			}
		}
	}
}