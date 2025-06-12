////==============================================================
////
//// [floor.h]
//// Author: Irisawa Kazan
////
////==============================================================
//#ifndef _FLOOR_H_ // ���̃}�N����`������ĂȂ�������
//#define _FLOOR_H_ // 2�d�C���N���[�h�h�~�̃}�N����`
//
//#include"main.h"
//#include"object3D.h"
//
//// ���|���S���N���X
//class CFloor : public CObject3D
//{
//public:
//	CFloor(int nPriority = 3);
//	~CFloor();
//
//	static HRESULT Load(void);
//	static void Unload(void);
//
//	static CFloor* Create(D3DXVECTOR3 pos, float xsize, float ysize);
//
//	HRESULT Init(D3DXVECTOR3 pos);
//	void Uninit(void);
//	void Update(void);
//	void Draw(void);
//
//	void SetPosition(D3DXVECTOR3 pos);
//	void SetSize(float xsize, float ysize);
//
//private:
//	static LPDIRECT3DTEXTURE9 m_pTexture;
//};
//
//#endif