//==============================================================
//
// [object2D.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _OBJECT2D_H_ // ���̃}�N����`������ĂȂ�������
#define _OBJECT2D_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"object.h"

// �}�N����`
#define PLAYER_SPEED (0.1f) // �v���C���[�̑���

// �I�u�W�F�N�g2D�N���X
class CObject2D : public CObject
{
public:
	CObject2D();
	~CObject2D();

	static CObject2D* Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetPosition(D3DXVECTOR3 pos);
	//void SetRotation(D3DXVECTOR3 rot);
protected:
	LPDIRECT3DTEXTURE9 m_pTexture;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;
	D3DXVECTOR3 m_pos;
private:
	//LPDIRECT3DTEXTURE9 m_pTexture;
	//LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;
	//D3DXVECTOR3 m_pos;
	//D3DXVECTOR3 m_rot;
};

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

//// �o�b�N�O���E���h�N���X
//class CBackground : public CObject2D
//{
//public:
//	CBackground();
//	~CBackground();
//
//	static CBackground* Create(void);
//	HRESULT Init(void);
//	void Uninit(void);
//	void Update(void);
//	void Draw(void);
//	void SetPosition(D3DXVECTOR3 pos);
//
//private:
//};

#endif