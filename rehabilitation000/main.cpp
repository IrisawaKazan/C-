//==================================================
//
// [main.cpp]
// Irisawa Kazan
//
//==================================================
#include"main.h"
#include"enemy.h"

// 加算処理のテンプレート関数[テンプレート型 "T" を定義する]
template<class T> T Add(const T data0, const T data1)
{
	T answer;

	answer = data0 + data1;

	return answer;
}

//-------------------------------------
// メイン関数
//-------------------------------------
int main(void)
{
	/*int nData;
	int nData1;

	CEnemy *pEnemy = NULL; // 敵オブジェクトへのポインタ

	// メモリ確保
	pEnemy = new CEnemy;

	// 初期化処理
	pEnemy->Init();

	// 入力処理
	pEnemy->Input();

	// 出力処理
	pEnemy->Output();

	printf("\n攻撃力を再入力してください > ");
	scanf("%d", &nData);

	// 設定処理
	pEnemy->SetAttack(nData);

	// 取得処理
	nData1 = pEnemy->GetAttack();

	printf("\n攻撃力を再出力: %d\n", nData1);

	//// 攻撃力のみの入力処理
	//pEnemy->AttackInput();

	//// 攻撃力のみの出力処理
	//pEnemy->AttackOutput();

	// 終了処理
	pEnemy->Uninit();

	// メモリ解放
	delete pEnemy;
	pEnemy = NULL;*/

	/*int aNum[2];

	for (int nCount = 0; nCount < 2; nCount++)
	{
		printf("%dつ目の数値を入力してください > ", nCount + 1);
		scanf("%d", &aNum[nCount]);

		printf("\n");
	}

	printf("2つの数値の合計: %d\n", aNum[0] + aNum[1]);*/

	/*float fNum[MAX_NUM];

	for (int nCount = 0; nCount < MAX_NUM; nCount++)
	{
		printf("%dつ目の数値を入力してください > ", nCount + 1);
		scanf("%f", &fNum[nCount]);

		printf("\n");
	}

	printf("%dつの数値の合計: %.1f\n", MAX_NUM, fNum[0] + fNum[1]);*/

	int nData0, nData1;

	printf("1つ目の数値を入力 > ");
	scanf("%d", &nData0);
	printf("2つ目の数値を入力 > ");
	scanf("%d", &nData1);

	printf("\n1つ目の数値: %d\n", nData1);
	printf("\n2つ目の数値: %d\n", nData0);

	// キー入力待ち
	printf("\n*** エンターキーで終了 ***");
	rewind(stdin);
	getchar();
	return 0;
}