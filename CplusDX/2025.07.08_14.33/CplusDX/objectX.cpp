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
#include"debrisX.h"

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
	m_posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_mtxWorld = D3DXMATRIX();

	m_fRotation = 0.0f;
	m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_vtxMin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_vtxMax = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	m_bUse = true;

	m_bRetention = false;

	m_nCounter = NULL;
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
	// ��ނ̐ݒ菈��
	CObject::SetType(TYPE_MODEL);

	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// X�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX("data\\MODEL\\sphere.x",
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

		if (vtx.x >= m_vtxMax.x)
		{
			m_vtxMax.x = vtx.x;
		}

		if (vtx.y >= m_vtxMax.y)
		{
			m_vtxMax.y = vtx.y;
		}

		if (vtx.z >= m_vtxMax.z)
		{
			m_vtxMax.z = vtx.z;
		}

		// ���_�t�H�[�}�b�g�̃T�C�Y���|�C���^��i�߂�
		pVtxBuff += sizeFVF;
	}

	m_size = D3DXVECTOR3(m_vtxMax.x - m_vtxMin.x, m_vtxMax.y - m_vtxMin.y, m_vtxMax.z - m_vtxMin.z);

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
void CObjectX::Uninit(void)
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

	CObject::Release();
	//this->Release();
}

//----------------------------------------
// �X�V����
//----------------------------------------
void CObjectX::Update(void)
{
	if (m_bUse == true)
	{
		CInputKeyboard* pInputKeyboard;

		// �L�[�{�[�h�̎擾
		pInputKeyboard = CManager::GetInputKeyboard();

		CInputMouse* pInputMouse;

		// �}�E�X�̎擾
		pInputMouse = CManager::GetInputMouse();

		CInputJoypad* pInputJoypad;

		// �p�b�h�̎擾
		pInputJoypad = CManager::GetInputJoypad();

		// �^�C�}�[���̃X�R�A�J�E���^�[
		m_nCounter++;

		// 1�b���ƂɃX�R�A���Z(+1)
		if (m_nCounter >= 60)
		{
			// �X�R�A���Z
			CScore::AddScore(1);

			m_nCounter = 0;
		}

		// �O��̈ʒu��ۑ�
		m_posOld = m_pos;

		// �v���C���[�ړ�
		// ��ɐi�� + �����ƃ|�C���g�����܂�₷���V�X�e��
		if (pInputKeyboard->GetPress(DIK_SPACE) || pInputJoypad->GetJoypadPress(pInputJoypad->JOYKEY_A) || pInputMouse->Press(pInputMouse->MOUSE_LEFTBUTTON) == true)
		{// ��
			m_pos.z += MAX_PMOVE * 3.5f;

			// 1/6�b���ƂɃX�R�A���Z(+1)
			if (m_nCounter >= 10)
			{
				// �X�R�A���Z
				CScore::AddScore(1);

				m_nCounter = 0;
			}
		}

		// �㕔�̃G���A�ɂ���ƃX�R�A���L�т₷���Ȃ�V�X�e��
		if (m_pos.z >= 32.5f && m_pos.z <= 132.5f)
		{
			// 1/10�b���ƂɃX�R�A���Z(+1)
			if (m_nCounter >= 6)
			{
				// �X�R�A���Z
				CScore::AddScore(1);

				m_nCounter = 0;
			}
		}

		if (m_pos.z >= -132.5f)
		{// ���ւ̈ړ�����
			// ��Ɍ�ނ���
			m_pos.z -= MAX_PMOVE;
		}

		// ���[�e�[�V����
		m_fRotation += 1.0f;

		m_rot = D3DXVECTOR3(0.0f, m_fRotation / 200.0f/* ��鑬�x */, 0.0f);

		// �A�C�e���ێ����̏���
		if (m_bRetention == true)
		{
			/* �����ڂł킩�鉽�� */

			// �A�C�e���g�p
			if (pInputKeyboard->GetTrigger(DIK_B) == true)
			{
				m_bRetention = false; // TODO: ���̊֐��ɌĂяo�����ق�����������

				/* �G�ɓ���������|���鏈��(10�b��) or ��ʓ��̓G��|(�G��bUse = false�ɂȂ������ɂ�10�`50, 100�X�R�A) (�֐��Ăяo��) */
			}
		}
	}
}

//----------------------------------------
// �`�揈��
//----------------------------------------
void CObjectX::Draw(void)
{
	if (m_bUse == true)
	{
		//LPDIRECT3DSURFACE9 pRenderDef, pZBuffDef;
		//D3DVIEWPORT9 viewportDef;
		//D3DXMATRIX mtxViewDef, mtxProjectionDef;

		// �f�o�C�X�̎擾
		LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

		//// ���݂̃����_�����O�^�[�Q�b�g���擾(�ۑ�)
		//pDevice->GetRenderTarget(0, &pRenderDef);

		//// ���݂�Z�o�b�t�@���擾(�ۑ�)
		//pDevice->GetDepthStencilSurface(&pZBuffDef);

		//// ���݂̃r���[�|�[�g���擾(�ۑ�)
		//pDevice->GetViewport(&viewportDef);

		//// ���݂̃r���[�}�g���b�N�X���擾(�ۑ�)
		//pDevice->GetTransform(D3DTS_VIEW, &mtxViewDef);

		//// ���݂̃v���W�F�N�V�����}�g���b�N�X���擾(�ۑ�)
		//pDevice->GetTransform(D3DTS_PROJECTION, &mtxProjectionDef);

		//// �����_�����O�^�[�Q�b�g�̕ύX
		//CManager::GetRenderer()->ChangeTarget(D3DXVECTOR3(0.0f, 375.0f, -1.0f), D3DXVECTOR3(0.0f, -120.0f, 0.0f), D3DXVECTOR3(0.0f, 1.0f, 0.0f));

		//// �����_�����O�^�[�Q�b�g�p�e�N�X�`���̃N���A
		//pDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER), D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);

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

		//// �����_�����O�^�[�Q�b�g�����ɖ߂�
		//pDevice->SetRenderTarget(0, pRenderDef);

		//// Z�o�b�t�@�����ɖ߂�
		//pDevice->SetDepthStencilSurface(pZBuffDef);
	}
}

//----------------------------------------
// �ʒu�̐ݒ菈��
//----------------------------------------
void CObjectX::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//----------------------------------------
// �O��̈ʒu�̐ݒ菈��
//----------------------------------------
void CObjectX::SetPositionOld(D3DXVECTOR3 posOld)
{
	m_posOld = posOld;
}

//----------------------------------------
// �����̐ݒ菈��
//----------------------------------------
void CObjectX::SetRotation(D3DXVECTOR3 rot)
{
	m_rot = rot;
}

//----------------------------------------
// �T�C�Y�̐ݒ菈��
//----------------------------------------
void CObjectX::SetSize(D3DXVECTOR3 size)
{
	m_size = size;
}

//----------------------------------------
// �g�p�L���̐ݒ菈��
//----------------------------------------
void CObjectX::SetEnable(bool enable)
{
	m_bUse = enable;
}

//----------------------------------------
// �A�C�e���ێ��L���̐ݒ菈��
//----------------------------------------
void CObjectX::SetSigns(bool signs)
{
	m_bRetention = signs;
}

//----------------------------------------
// �ʒu�̎擾����
//----------------------------------------
D3DXVECTOR3 CObjectX::GetPos(void)
{
	return m_pos;
}

//----------------------------------------
// �O��̈ʒu�̎擾����
//----------------------------------------
D3DXVECTOR3 CObjectX::GetPosOld(void)
{
	return m_posOld;
}

//----------------------------------------
// �����̎擾����
//----------------------------------------
D3DXVECTOR3 CObjectX::GetRot(void)
{
	return m_rot;
}

//----------------------------------------
// �T�C�Y�̎擾����
//----------------------------------------
D3DXVECTOR3 CObjectX::GetSize(void)
{
	return m_size;
}

//----------------------------------------
// �g�p�L���̎擾����
//----------------------------------------
bool CObjectX::GetEnable(void)
{
	return m_bUse;
}

//----------------------------------------
// �A�C�e���ێ��L���̎擾����
//----------------------------------------
bool CObjectX::GetSigns(void)
{
	return m_bRetention;
}