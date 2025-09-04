//==============================================================
//
// [effect3D.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _EFFECT3D_H_ // このマクロ定義がされてなかったら
#define _EFFECT3D_H_ // 2重インクルード防止のマクロ定義

#include"object.h"
#include"objectBillboard.h"

// 3Dエフェクトクラス
class CEffect3D : public CObjectBillboard
{
public:
    CEffect3D(int nPriority = 7);
    ~CEffect3D();

    static HRESULT Load(void);
    static void Unload(void);

    static CEffect3D* Create(D3DXVECTOR3 pos, D3DXCOLOR col, float fRedius, int nLife, float sizeX, float sizeY);

    HRESULT Init(D3DXVECTOR3 pos, D3DXCOLOR col, float fRedius, int nLife);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    void SetPosition(D3DXVECTOR3 pos);
    void SetSize(float sizeX, float sizeY);

private:
    static LPDIRECT3DTEXTURE9 m_pTexture;
    D3DXVECTOR3 m_pos; // 位置
    D3DXCOLOR m_col;   // 色
    float m_fRedius;   // 半径(大きさ)
    int m_nLife;       // 寿命
};

#endif