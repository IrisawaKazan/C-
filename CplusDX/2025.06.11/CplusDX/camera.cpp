//==============================================================
//
// [camera.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"camera.h"
#include"manager.h"
#include"renderer.h"
#include"input.h"

//----------------------------------------
// �R���X�g���N�^
//----------------------------------------
CCamera::CCamera()
{
	m_mtxView = D3DXMATRIX(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	m_mtxProjection = D3DXMATRIX(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	m_posV = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_vecU = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_fDistance = 0.0f;
}

//----------------------------------------
// �f�X�g���N�^
//----------------------------------------
CCamera::~CCamera()
{

}

//----------------------------------------
// �J�����̏���������
//----------------------------------------
HRESULT CCamera::Init(void)
{
	// ���_,�����_,�������ݒ肷��
	m_posV = D3DXVECTOR3(0.0f, 100.0f, -300.0f);
	m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_fDistance = sqrtf((m_posR.x - m_posV.x) * (m_posR.x - m_posV.x) +
		(m_posR.y - m_posV.y) * (m_posR.y - m_posV.y) +
		(m_posR.z - m_posV.z) * (m_posR.z - m_posV.z));

	return S_OK;
}

//----------------------------------------
// �J�����̏I������
//----------------------------------------
void CCamera::Uninit(void)
{

}

//----------------------------------------
// �J�����̍X�V����
//----------------------------------------
void CCamera::Update(void)
{
	CInputKeyboard* pInputKeyboard;

	// �L�[�{�[�h�̎擾
	pInputKeyboard = CManager::GetInputKeyboard();

	// �����_�̐���
	if (pInputKeyboard->GetPress(DIK_Q) == true)
	{
		m_rot.y -= 0.02f;

		// �p�x�̐��K��
		if (-D3DX_PI > m_rot.y)
		{
			m_rot.y = m_rot.y + D3DX_PI * 2.0f;
		}

		m_posR.x = m_posV.x + sinf(m_rot.y) * m_fDistance;
		m_posR.z = m_posV.z + cosf(m_rot.y) * m_fDistance;
	}
	else if (pInputKeyboard->GetPress(DIK_E) == true)
	{
		m_rot.y += 0.02f;

		// �p�x�̐��K��
		if (D3DX_PI < m_rot.y)
		{
			m_rot.y = m_rot.y - D3DX_PI * 2.0f;
		}

		m_posR.x =m_posV.x + sinf(m_rot.y) * m_fDistance;
		m_posR.z =m_posV.z + cosf(m_rot.y) * m_fDistance;
	}

	// ���_�̐���
	if (pInputKeyboard->GetPress(DIK_Z) == true)
	{
		m_rot.y -= 0.02f;

		// �p�x�̐��K��
		if (-D3DX_PI > m_rot.y)
		{
			m_rot.y = m_rot.y + D3DX_PI * 2.0f;
		}

		m_posV.x = m_posR.x - sinf(m_rot.y) * m_fDistance;
		m_posV.z = m_posR.z - cosf(m_rot.y) * m_fDistance;
	}
	else if (pInputKeyboard->GetPress(DIK_C) == true)
	{
		m_rot.y += 0.02f;

		// �p�x�̐��K��
		if (D3DX_PI < m_rot.y)
		{
			m_rot.y = m_rot.y - D3DX_PI * 2.0f;
		}

		m_posV.x = m_posR.x - sinf(m_rot.y) * m_fDistance;
		m_posV.z = m_posR.z - cosf(m_rot.y) * m_fDistance;
	}

	// �J�����̈ړ�
	if (pInputKeyboard->GetPress(DIK_LEFT) == true)
	{// ��
		if (pInputKeyboard->GetPress(DIK_UP) == true)
		{// ����Ɉړ�
			// ��
			m_posV.x -= cosf(m_rot.y) * 1.0f;
			m_posV.z += sinf(m_rot.y) * 1.0f;

			m_posR.x = m_posV.x + sinf(m_rot.y) * m_fDistance;
			m_posR.z = m_posV.z + cosf(m_rot.y) * m_fDistance;

			// ��
			m_posV.x += sinf(m_rot.y) * 1.0f;
			m_posV.z += cosf(m_rot.y) * 1.0f;

			m_posR.x = m_posV.x + sinf(m_rot.y) * m_fDistance;
			m_posR.z = m_posV.z + cosf(m_rot.y) * m_fDistance;
		}
		else if (pInputKeyboard->GetPress(DIK_DOWN) == true)
		{// �����Ɉړ�
			// ��
			m_posV.x -= cosf(m_rot.y) * 1.0f;
			m_posV.z += sinf(m_rot.y) * 1.0f;

			m_posR.x = m_posV.x + sinf(m_rot.y) * m_fDistance;
			m_posR.z = m_posV.z + cosf(m_rot.y) * m_fDistance;

			// ��
			m_posV.x -= sinf(m_rot.y) * 1.0f;
			m_posV.z -= cosf(m_rot.y) * 1.0f;

			m_posR.x = m_posV.x + sinf(m_rot.y) * m_fDistance;
			m_posR.z = m_posV.z + cosf(m_rot.y) * m_fDistance;
		}
		else
		{// ���Ɉړ�
			m_posV.x -= cosf(m_rot.y) * 1.0f;
			m_posV.z += sinf(m_rot.y) * 1.0f;

			m_posR.x = m_posV.x + sinf(m_rot.y) * m_fDistance;
			m_posR.z = m_posV.z + cosf(m_rot.y) * m_fDistance;
		}
	}
	else if (pInputKeyboard->GetPress(DIK_RIGHT) == true)
	{// �E
		if (pInputKeyboard->GetPress(DIK_UP) == true)
		{// �E��Ɉړ�
			// �E
			m_posV.x += cosf(m_rot.y) * 1.0f;
			m_posV.z -= sinf(m_rot.y) * 1.0f;

			m_posR.x = m_posV.x + sinf(m_rot.y) * m_fDistance;
			m_posR.z = m_posV.z + cosf(m_rot.y) * m_fDistance;

			// ��
			m_posV.x += sinf(m_rot.y) * 1.0f;
			m_posV.z += cosf(m_rot.y) * 1.0f;

			m_posR.x = m_posV.x + sinf(m_rot.y) * m_fDistance;
			m_posR.z = m_posV.z + cosf(m_rot.y) * m_fDistance;
		}
		else if (pInputKeyboard->GetPress(DIK_DOWN) == true)
		{// �E���Ɉړ�
			// �E
			m_posV.x += cosf(m_rot.y) * 1.0f;
			m_posV.z -= sinf(m_rot.y) * 1.0f;

			m_posR.x = m_posV.x + sinf(m_rot.y) * m_fDistance;
			m_posR.z = m_posV.z + cosf(m_rot.y) * m_fDistance;

			// ��
			m_posV.x -= sinf(m_rot.y) * 1.0f;
			m_posV.z -= cosf(m_rot.y) * 1.0f;

			m_posR.x = m_posV.x + sinf(m_rot.y) * m_fDistance;
			m_posR.z = m_posV.z + cosf(m_rot.y) * m_fDistance;
		}
		else
		{// �E�Ɉړ�
			m_posV.x += cosf(m_rot.y) * 1.0f;
			m_posV.z -= sinf(m_rot.y) * 1.0f;

			m_posR.x = m_posV.x + sinf(m_rot.y) * m_fDistance;
			m_posR.z = m_posV.z + cosf(m_rot.y) * m_fDistance;
		}
	}
	else if (pInputKeyboard->GetPress(DIK_UP) == true)
	{// ��
		m_posV.x += sinf(m_rot.y) * 1.0f;
		m_posV.z += cosf(m_rot.y) * 1.0f;

		m_posR.x = m_posV.x + sinf(m_rot.y) * m_fDistance;
		m_posR.z = m_posV.z + cosf(m_rot.y) * m_fDistance;
	}
	else if (pInputKeyboard->GetPress(DIK_DOWN) == true)
	{// ��
		m_posV.x -= sinf(m_rot.y) * 1.0f;
		m_posV.z -= cosf(m_rot.y) * 1.0f;

		m_posR.x = m_posV.x + sinf(m_rot.y) * m_fDistance;
		m_posR.z = m_posV.z + cosf(m_rot.y) * m_fDistance;
	}

	//// ���~�ړ�
	//if (pInputKeyboard->GetPress(DIK_NUMPAD8) == true)
	//{// �㏸
	//	m_posV.y -= sinf(m_rot.y) * 1.0f;

	//	m_posR.y = m_posV.y - sinf(m_rot.y) * m_fDistance;
	//}
	//if (pInputKeyboard->GetPress(DIK_NUMPAD2) == true)
	//{// ���~
	//	m_posV.y += sinf(m_rot.y) * 1.0f;

	//	m_posR.y = m_posV.y + sinf(m_rot.y) * m_fDistance;
	//}
}

//----------------------------------------
// �J�����̐ݒ菈��
//----------------------------------------
void CCamera::SetCamera(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxView);

	D3DXMatrixLookAtLH(&m_mtxView,
		&m_posV,
		&m_posR,
		&m_vecU);

	// �r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);

	// �v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxProjection);

	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,
		D3DXToRadian(45.0f),
		(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,
		10.0f,
		1000.0f);

	// �v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);
}