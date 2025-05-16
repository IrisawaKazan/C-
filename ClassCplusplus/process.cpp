//========================================
//
// クラス・ファイル分割[process.cpp]
// Author: Irisawa Kazan	
//
//========================================
#include"process.h"

//----------------------------
// コンストラクタ
//----------------------------
CProcess::CProcess()
{
	m_nNumPlayer = 0;
}

//----------------------------
// デストラクタ
//----------------------------
CProcess::~CProcess()
{

}

//----------------------------
// 初期化処理
//----------------------------
void CProcess::Init(void)
{
	for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		m_aPlayer[nCount].Init();
	}
}

//----------------------------
// 終了処理
//----------------------------
void CProcess::Uninit(void)
{
	for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		m_aPlayer[nCount].Uninit();
	}
}

//----------------------------
// 選択処理
//----------------------------
void CProcess::SelectMode(void)
{
	int nSelect;

	do
	{
		printf("処理する番号を以下から選んでください\n");
		printf("1.データ入力\n");
		printf("2.データ出力\n");
		printf("0.終了\n\n");

		printf("処理する番号 > ");
		scanf("%d", &nSelect);

		switch (nSelect)
		{
		case MODE_INPUT:
			Input();
			break;

		case MODE_OUTPUT:
			Output();
			break;

		case MODE_FINISH:
			break;
		}

		printf("\n");

	} while (nSelect != 0);
}

//----------------------------
// 入力処理
//----------------------------
void CProcess::Input(void)
{
	printf("人数を入力 > ");
	scanf("%d", &m_nNumPlayer);

	for (int nCount = 0; nCount < m_nNumPlayer; nCount++)
	{
		m_aPlayer[nCount].Input();
	}
}

//----------------------------
// 出力処理
//----------------------------
void CProcess::Output(void)
{
	for (int nCount = 0; nCount < m_nNumPlayer; nCount++)
	{
		m_aPlayer[nCount].Output();
	}
}