//==============================================================
//
// [playerX.cpp]
// Author: Irisawa Kazan
//
//==============================================================
#include"playerX.h"
#include"model.h"
#include"manager.h"
#include"renderer.h"

//----------------------------------------
// コンストラクタ
//----------------------------------------
CPlayerX::CPlayerX()
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_mtxWorld = D3DXMATRIX();

	for (int nCnt = 0; nCnt < MAX_PARTS; nCnt++)
	{
		m_apModel[nCnt] = nullptr;
	}

	m_nNumModel = NULL;
}

//----------------------------------------
// デストラクタ
//----------------------------------------
CPlayerX::~CPlayerX()
{

}

//----------------------------------------
// 生成処理
//----------------------------------------
CPlayerX* CPlayerX::Create(D3DXVECTOR3 pos)
{
	CPlayerX* pPlayerX;

	// オブジェクトXの生成
	pPlayerX = new CPlayerX;

	// 初期化処理
	pPlayerX->Init(pos);

	// 位置の設定
	pPlayerX->SetPosition(pos);

	return pPlayerX;
}

//----------------------------------------
// 初期化処理
//----------------------------------------
HRESULT CPlayerX::Init(D3DXVECTOR3 pos)
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	CModel* pModel;

	// モデルの生成(全パーツ分)
	m_apModel[0] = pModel->Create(pos);


	// 親モデルの設定(全パーツ分)
	m_apModel[0]->SetParent(m_apModel[0]);


	return S_OK;
}

//----------------------------------------
// 終了処理
//----------------------------------------
void CPlayerX::Uninit(void)
{
	// オブジェクト(自分自身)の破棄
	this->Release();
}

//----------------------------------------
// 更新処理
//----------------------------------------
void CPlayerX::Update(void)
{

}

//----------------------------------------
// 描画処理
//----------------------------------------
void CPlayerX::Draw(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// 計算用のマトリックス
	D3DXMATRIX mtxRot, mtxTrans;

	D3DMATERIAL9 matDef; // 現在のマテリアル保存用

	// ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);

	// 向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// 位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);



	// 保存していたマテリアルを元に戻す
	pDevice->SetMaterial(&matDef);
}

//----------------------------------------
// 位置の設定処理
//----------------------------------------
void CPlayerX::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//----------------------------------------
// 位置の取得処理
//----------------------------------------
D3DXVECTOR3 CPlayerX::GetPos(void)
{
	return m_pos;
}