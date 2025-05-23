//==============================================================
//
// [object.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _OBJECT_H_ // このマクロ定義がされてなかったら
#define _OBJECT_H_ // 2重インクルード防止のマクロ定義

#include"main.h"

// マクロ定義
#define MAX_OBJ (256)

// オブジェクトクラス
class CObject
{
public:
	// オブジェクトの種類
	typedef enum
	{
		TYPE_NONE = 0,
		TYPE_PLAYER,     // プレイヤー
		TYPE_ENEMY,      // 敵
		TYPE_BULLET,     // 弾
		TYPE_EXPLOSION,  // 爆発
		TYPE_BACKGROUND, // 背景

		TYPE_MAX
	}TYPE;

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

	virtual D3DXVECTOR3 GetPos(void) = 0;

	void SetType(TYPE type);
	TYPE GetType(void);
	static CObject* GetObj(int nIdx);

protected:
	void Release(void);

private:
	static CObject* m_apObject[MAX_OBJ];
	static int m_nNumAll; // オブジェクトの総数
	int m_nID;            // 自分自身のID
	TYPE m_type;
};

#endif