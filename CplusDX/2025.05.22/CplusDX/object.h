//==============================================================
//
// [object.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _OBJECT_H_ // ���̃}�N����`������ĂȂ�������
#define _OBJECT_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"

#define MAX_OBJ (128)

// �I�u�W�F�N�g�N���X
class CObject
{
public:
	CObject();
	virtual	~CObject();

	static void ReleaseAll(void);
	static void UpdateAll(void);
	static void DrawAll(void);

	virtual HRESULT Init(D3DXVECTOR3 pos) = 0;
	virtual void Uninit(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;
	virtual void SetPosition(D3DXVECTOR3 pos) = 0;
	//virtual void SetRotation(D3DXVECTOR3 rot) = 0;

protected:
	void Release(void);

private:
	static CObject* m_apObject[MAX_OBJ];
	static int m_nNumAll; // �I�u�W�F�N�g�̑���
	int m_nID;            // �������g��ID
};

#endif