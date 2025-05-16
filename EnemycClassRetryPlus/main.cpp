//============================================
//
// 仮想関数[main.cpp]
// Author: Irisawa Kazan
//
//============================================
#include"main.h"
#include"enemy.h"

// プロトタイプ宣言
void Init(void);
void Uninit(void);
void Input(void);
void Output(void);

//------------------------------------
// メイン関数
//------------------------------------
int main(void)
{
	Init();

	Input();

	Output();

	Uninit();

	// キー入力待ち
	printf("\n\n--- エンターキーで終了 ---");
	rewind(stdin);
	getchar();
	return 0;
}

//------------------------------------
// 初期化処理
//------------------------------------
void Init(void)
{
	CEnemy::RleaseAll();
}

//------------------------------------
// 終了関数
//------------------------------------
void Uninit(void)
{
	CEnemy::RleaseAll();
}

//------------------------------------
// 入力処理
//------------------------------------
void Input(void)
{
	CEnemy* pEnemy;

	CEnemy::TYPE type = CEnemy::TYPE_NONE;

	int nCount = 0;

	do
	{
		printf("[ 生成する敵の種類を選択 ]\n%d.人型\n%d.鳥型\n%d.終了\n番号を入力 > ", CEnemy::TYPE_HUMAN, CEnemy::TYPE_BIRD, CEnemy::TYPE_NONE);
		scanf("%d", &type);

		pEnemy = CEnemy::Create(type);

		if (pEnemy != NULL)
		{
			// 初期化処理
			pEnemy->Init();

			// 入力処理
			pEnemy->Input();

			printf("\n");
		}

		nCount++;
	} while (type != 0 && nCount < MAX_ENEMY);
}

//------------------------------------
// 出力処理
//------------------------------------
void Output(void)
{
	CEnemy::OutputAll();
}