//========================================
//
// �N���X�E�t�@�C������[main.cpp]
// Author: Irisawa Kazan	
//
//========================================
#include"main.h"
#include"process.h"

//----------------------------
// ���C���֐�
//----------------------------
int main(void)
{
	CProcess process; // �v���Z�X�I�u�W�F�N�g�𐶐�

	// ����������
	process.Init();

	// �I������
	process.SelectMode();

	// �I������
	process.Uninit();

	// �L�[���͑҂�
	printf("\n--- �G���^�[�L�[�ŏI�� ---");
	rewind(stdin);
	getchar();
	return 0;
}