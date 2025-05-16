//=======================================
//
// エネミークラス[main.cpp]
// Irisawa Kazan
//
//=======================================
#include"main.h"
#include"enemy.h"

//----------------------------
// メイン関数
//----------------------------
int main(void)
{
	// 敵
	/*CEnemy enemy; // 敵のインスタンスを生成

	// 初期化処理
	enemy.Init();

	// 入力処理
	enemy.Input();

	printf("\n");

	// 出力処理
	enemy.Output();

	// 終了処理
	enemy.Uinit();*/

	// 人型と鳥型
	/*
	CEnemyHuman enemyhuman; // 人型敵のインスタンスを生成
	CEnemyBird enemybird;   // 鳥型敵のインスタンスを生成

	// 初期化処理
	enemyhuman.Init();
	enemybird.Init();

	// 入力処理
	enemyhuman.Input();
	printf("\n");
	enemybird.Input();

	printf("\n");

	// 出力処理
	enemyhuman.Output();
	printf("\n");
	enemybird.Output();

	// 終了処理
	enemyhuman.Uinit();
	enemybird.Uinit();*/

	// 人型敵
	CEnemyHuman* pEnemyHuman = NULL; // 人型敵クラスのポインタを宣言
	// 鳥型敵
	CEnemyBird* pEnemyBird = NULL;   // 鳥型敵クラスのポインタを宣言

	CEnemy::TYPE type;

	int nSelect;
	int nNumEnemy;

	printf("生成する敵の種類を選んでください\n%d.人型\n%d.鳥型\n番号 > ", CEnemy::TYPE_HUMAN, CEnemy::TYPE_BIRD);
	scanf("%d", &nSelect);
	printf("\n");

	printf("生成する敵の数を入力 > ");
	scanf("%d", &nNumEnemy);

	switch (nSelect)
	{
	case CEnemy::TYPE_HUMAN:
		if (pEnemyHuman == NULL)
		{
			pEnemyHuman = new CEnemyHuman[nNumEnemy]; // 人型敵のインスタンスを生成

			if (pEnemyHuman != NULL)
			{
				for (int nCount = 0; nCount < nNumEnemy; nCount++)
				{
					// 初期化処理
					(pEnemyHuman + nCount)->Init();

					// 入力処理
					(pEnemyHuman + nCount)->Input();
				}

				printf("\n");

				for (int nCount = 0; nCount < nNumEnemy; nCount++)
				{
					// 出力処理
					(pEnemyHuman + nCount)->Output();

					// 終了処理
					(pEnemyHuman + nCount)->Uinit();
				}
				delete[] pEnemyHuman;
				pEnemyHuman = NULL;
			}
			else
			{
				printf("\nエラー\n");
			}
		}
		break;

	case CEnemy::TYPE_BIRD:
		if (pEnemyBird == NULL)
		{
			pEnemyBird = new CEnemyBird[nNumEnemy]; // 鳥型敵のインスタンスを生成

			if (pEnemyBird != NULL)
			{
				for (int nCount = 0; nCount < nNumEnemy; nCount++)
				{
					// 初期化処理
					(pEnemyBird + nCount)->Init();

					// 入力処理
					(pEnemyBird + nCount)->Input();
				}

				printf("\n");

				for (int nCount = 0; nCount < nNumEnemy; nCount++)
				{
					// 出力処理
					(pEnemyBird + nCount)->Output();

					// 終了処理
					(pEnemyBird + nCount)->Uinit();
				}
				delete[] pEnemyBird;
				pEnemyBird = NULL;
			}
			else
			{
				printf("エラー");
			}
		}
		break;
	}

	// キー入力待ち
	printf("\n\n--- エンターキーで終了 ---");
	rewind(stdin);
	getchar();
	return 0;
}