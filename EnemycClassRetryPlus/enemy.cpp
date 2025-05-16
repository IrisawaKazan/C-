//============================================
//
// 仮想関数[enemy.cpp]
// Author: Irisawa Kazan
//
//============================================
#include"enemy.h"

// 静的メンバ変数宣言
int CEnemy::m_nNumAll = 0;                 // 敵の総数
int CEnemy::m_nNumHuman = 0;               // 人型敵の総数
int CEnemy::m_nNumBird = 0;                // 鳥型敵の総数
CEnemy* CEnemy::m_apEnemy[MAX_ENEMY] = {}; // オブジェクトへのポインタ

//------------------------------------
// オブジェクトの生成処理
//------------------------------------
CEnemy* CEnemy::Create(TYPE type)
{
	if (m_nNumAll < MAX_ENEMY)
	{
		int nIdx;

		nIdx = m_nNumAll; // 現在の総数を代入

		switch (type)
		{
		case CEnemy::TYPE_HUMAN:
			m_apEnemy[nIdx] = new CEnemyHuman;
			break;

		case CEnemy::TYPE_BIRD:
			m_apEnemy[nIdx] = new CEnemyBird;
			break;
		}

		return m_apEnemy[nIdx];
	}

	return NULL;
}

//------------------------------------
// 初期化兼終了処理
//------------------------------------
void CEnemy::RleaseAll(void)
{
	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (m_apEnemy[nCntEnemy] != NULL)
		{
			// 終了処理
			m_apEnemy[nCntEnemy]->Uinit();

			delete m_apEnemy[nCntEnemy];
			m_apEnemy[nCntEnemy] = NULL;
		}
	}
}

//------------------------------------
// 出力処理
//------------------------------------
void CEnemy::OutputAll(void)
{
	int nNumAll = 0;      // 敵の総数
	int nNumAllHuman = 0; // 人型敵の総数
	int nNumAllBird = 0;  // 鳥型敵の総数

	// 敵の総数を取得
	nNumAll = CEnemy::GetNumAll();
	nNumAllHuman = CEnemy::GetNumHuman();
	nNumAllBird = CEnemy::GetNumBird();

	printf("\n* 出力 *\n");

	for (int nCntEnemy = 0; nCntEnemy < nNumAll; nCntEnemy++)
	{
		if (m_apEnemy[nCntEnemy] != NULL)
		{
			// 出力処理
			m_apEnemy[nCntEnemy]->Output();
		}

		delete m_apEnemy[nCntEnemy];
		m_apEnemy[nCntEnemy] = NULL;
	}

	printf("\n敵の総数: %d", nNumAll);
	printf("\n人型敵の総数: %d", nNumAllHuman);
	printf("\n鳥型敵の総数: %d", nNumAllBird);
}

//------------------------------------
// 敵のコンストラクタ
//------------------------------------
CEnemy::CEnemy()
{
	m_nLife = 0;
	m_nAttack = 0;
	m_nNumAll++; // 敵の総数カウントアップ
}

//------------------------------------
// 敵のコンストラクタ(オーバーロード)
//------------------------------------
CEnemy::CEnemy(TYPE type)
{
	m_nLife = 0;
	m_nAttack = 0;
	m_nNumAll++; // 敵の総数カウントアップ

	switch (type)
	{
	case TYPE_HUMAN:
		m_nNumHuman++;
		break;

	case TYPE_BIRD:
		m_nNumBird++;
		break;
	}
}

//------------------------------------
// 敵のデストラクタ
//------------------------------------
CEnemy::~CEnemy()
{

}

#if 0
//------------------------------------
// 敵の初期化処理
//------------------------------------
void CEnemy::Init(void)
{
	m_nLife = 100;
	m_nAttack = 50;
}
#endif // 0

//------------------------------------
// 敵の終了処理
//------------------------------------
void CEnemy::Uinit(void)
{

}

//------------------------------------
// 敵の入力処理
//------------------------------------
void CEnemy::Input(void)
{
	printf("\n体力を入力 > ");
	scanf("%d", &m_nLife);
	printf("攻撃力を入力 > ");
	scanf("%d", &m_nAttack);
}

//------------------------------------
// 敵の出力処理
//------------------------------------
void CEnemy::Output(void)
{
	printf("\n体力: %d\n", m_nLife);
	printf("攻撃力: %d\n", m_nAttack);
}

//------------------------------------
// 人型敵のコンストラクタ
//------------------------------------
CEnemyHuman::CEnemyHuman() : CEnemy(TYPE_HUMAN)
{
	m_nSpeedWalk = 0;
}

//------------------------------------
// 人型敵のデストラクタ
//------------------------------------
CEnemyHuman::~CEnemyHuman()
{

}

//------------------------------------
// 人型敵の初期化処理
//------------------------------------
void CEnemyHuman::Init(void)
{
	m_nLife = 100;
	m_nAttack = 50;

	m_nSpeedWalk = 30;
}

//------------------------------------
// 人型敵の終了処理
//------------------------------------
void CEnemyHuman::Uinit(void)
{

}

//------------------------------------
// 人型敵の入力処理
//------------------------------------
void CEnemyHuman::Input(void)
{
	printf("\n[人型の敵]\n");
	CEnemy::Input();

	printf("歩く速さを入力 > ");
	scanf("%d", &m_nSpeedWalk);
}

//------------------------------------
// 人型敵の出力処理
//------------------------------------
void CEnemyHuman::Output(void)
{
	printf("\n[人型の敵]");
	CEnemy::Output();

	printf("歩く速さ: %d\n", m_nSpeedWalk);
}

//------------------------------------
// 鳥型敵のコンストラクタ
//------------------------------------
CEnemyBird::CEnemyBird() : CEnemy(TYPE_BIRD)
{
	m_nSpeedFly = 0;
}

//------------------------------------
// 鳥型敵のデストラクタ
//------------------------------------
CEnemyBird::~CEnemyBird()
{

}

//------------------------------------
// 鳥型敵の初期化処理
//------------------------------------
void CEnemyBird::Init(void)
{
	m_nLife = 100;
	m_nAttack = 50;

	m_nSpeedFly = 40;
}

//------------------------------------
// 鳥型敵の終了処理
//------------------------------------
void CEnemyBird::Uinit(void)
{

}

//------------------------------------
// 鳥型敵の入力処理
//------------------------------------
void CEnemyBird::Input(void)
{
	printf("\n[鳥型の敵]\n");
	CEnemy::Input();

	printf("飛ぶ速さを入力 > ");
	scanf("%d", &m_nSpeedFly);
}

//------------------------------------
// 鳥型敵の出力処理
//------------------------------------
void CEnemyBird::Output(void)
{
	printf("\n[鳥型の敵]");
	CEnemy::Output();

	printf("飛ぶ速さ: %d\n", m_nSpeedFly);
}