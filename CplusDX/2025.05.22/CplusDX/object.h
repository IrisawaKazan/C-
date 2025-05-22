//==============================================================
//
// [object.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _OBJECT_H_ // このマクロ定義がされてなかったら
#define _OBJECT_H_ // 2重インクルード防止のマクロ定義

#include"main.h"

#define MAX_OBJ (128)

// オブジェクトクラス
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
	static int m_nNumAll; // オブジェクトの総数
	int m_nID;            // 自分自身のID
};

#endif