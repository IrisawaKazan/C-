////==============================================================
////
//// [sphereX.h]
//// Author: Irisawa Kazan
////
////==============================================================
//#ifndef _SPHEREX_H_ // ���̃}�N����`������ĂȂ�������
//#define _SPHEREX_H_ // 2�d�C���N���[�h�h�~�̃}�N����`
//
//#include"main.h"
//#include"objectX.h"
//
//// �X�t�B�AX�N���X
//class CSphereX : public CObjectX
//{
//public:
//	CSphereX(int nPriority = 5);
//	~CSphereX();
//
//	static HRESULT Load(void);
//	static void Unload(void);
//
//	static CSphereX* Create(D3DXVECTOR3 pos);
//
//	HRESULT Init(D3DXVECTOR3 pos);
//	void Uninit(void);
//	void Update(void);
//	void Draw(void);
//
//	void SetPosition(/*const */D3DXVECTOR3 pos);
//	void SetRotation(/*const */D3DXVECTOR3 rot);
//
//private:
//	static LPDIRECT3DTEXTURE9 m_pTexture;
//	static LPD3DXMESH m_pMesh;      // ���b�V��(���_���W)�ւ̃|�C���^
//	static LPD3DXBUFFER m_pBuffMat; // �}�e���A���ւ̃|�C���^
//	static DWORD m_dwNumMat;        // �}�e���A���̐�
//
//	D3DXVECTOR3 m_move;
//	float m_fRotation; // ���[�e�[�V����
//};
//
//#endif