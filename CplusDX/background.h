//==============================================================
//
// [background.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _BACKGROUND_H_ // ���̃}�N����`������ĂȂ�������
#define _BACKGROUND_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"
#include"object2D.h"

// �o�b�N�O���E���h�N���X
class CBackground : public CObject2D
{
public:
	CBackground();
	~CBackground();

	static CBackground* Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
};

#endif