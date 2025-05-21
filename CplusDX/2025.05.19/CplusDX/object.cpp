//==============================================================
//
// [object.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"object.h"
#include"renderer.h"
#include"object2D.h"

// �ÓI�����o�ϐ��錾
int CObject::m_nNumAll = 0;
CObject* CObject::m_apObject[MAX_OBJ] = {}; // �I�u�W�F�N�g�ւ̃|�C���^

//----------------------------------------
// �R���X�g���N�^
//----------------------------------------
CObject::CObject()
{
	m_nID = 0;

	for (int nCntObj = 0; nCntObj < MAX_OBJ; nCntObj++)
	{
		if (m_apObject[nCntObj] == NULL)
		{
			m_apObject[nCntObj] = this; // �������g����
			m_nID = nCntObj;            // �������g��ID��ۑ�
			m_nNumAll++;                // �������J�E���g�A�b�v
			break;
		}
	}
}

//----------------------------------------
// �f�X�g���N�^
//----------------------------------------
CObject::~CObject()
{

}

//----------------------------------------
// �S�ẴI�u�W�F�N�g�̔j��
//----------------------------------------
void CObject::ReleaseAll(void)
{
	for (int nCntObj = 0; nCntObj < MAX_OBJ; nCntObj++)
	{
		if (m_apObject[nCntObj] != NULL)
		{
			// �I������
			m_apObject[nCntObj]->Uninit();
		}
	}
}

//----------------------------------------
// �S�ẴI�u�W�F�N�g�̍X�V����
//----------------------------------------
void CObject::UpdateAll(void)
{
	for (int nCntObj = 0; nCntObj < MAX_OBJ; nCntObj++)
	{
		if (m_apObject[nCntObj] != NULL)
		{
			// �X�V����
			m_apObject[nCntObj]->Update();
		}
	}
}

//----------------------------------------
// �S�ẴI�u�W�F�N�g�̕`�揈��
//----------------------------------------
void CObject::DrawAll(void)
{
	for (int nCntObj = 0; nCntObj < MAX_OBJ; nCntObj++)
	{
		if (m_apObject[nCntObj] != NULL)
		{
			// �`�揈��
			m_apObject[nCntObj]->Draw();
		}
	}
}

//----------------------------------------
// �I�u�W�F�N�g�̔j��
//----------------------------------------
void CObject::Release(void)
{
	for (int nCntObj = 0; nCntObj < MAX_OBJ; nCntObj++)
	{
		if (m_apObject[nCntObj] != NULL)
		{
			delete m_apObject[nCntObj];
			m_apObject[nCntObj] = NULL;
			
			m_nNumAll--; // �������J�E���g�_�E��
		}
	}
}