//==============================================================
//
// [player.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _PLAYER_H_ // ���̃}�N����`������ĂȂ�������
#define _PLAYER_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"object.h"
#include"object2D.h"

// �}�N����`
#define PLAYER_SPEED (0.1f) // �v���C���[�̑���

// �v���C���[�N���X
class CPlayer : public CObject2D
{
public:
	CPlayer();
	~CPlayer();

	static CPlayer* Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetPosition(D3DXVECTOR3 pos);

private:
	int m_nCounterAnim; // �A�j���[�V�����J�E���^�[
	int m_nPatternAnim; // �A�j���[�V�����p�^�[��No.
	D3DXVECTOR3 m_move;
};

#endif