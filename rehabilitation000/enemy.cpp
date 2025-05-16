//==================================================
//
// [enemy.cpp]
// Irisawa Kazan
//
//==================================================
#include"enemy.h"

// 静的メンバ変数宣言
int CEnemy::m_nAttackBase = 0;            // 初期値
const int CEnemy::m_nAttackLinit = 10000; // 限界値

//-------------------------------------
// コンストラクタ
//-------------------------------------
CEnemy::CEnemy() : m_nAttackMax(1000)
{
	m_nLife = 0;
	m_nAttack = 0;
	m_nSpeed = 0;
}

//-------------------------------------
// コンストラクタ(オーバーロード)
//-------------------------------------
CEnemy::CEnemy(const int nAttackMax) : m_nAttackMax(nAttackMax)
{
	m_nLife = 0;
	m_nAttack = 0;
	m_nSpeed = 0;
}

//-------------------------------------
// デストラクタ
//-------------------------------------
CEnemy::~CEnemy()
{

}

//-------------------------------------
// 加算のオーバーロード
//-------------------------------------
CEnemy CEnemy::operator+(const CEnemy& enemy)
{
	CEnemy enemyWk;

	enemyWk.m_nAttack = m_nAttack + enemy.m_nAttack;

	return enemyWk;
}

//-------------------------------------
// 代入のオーバーロード
//-------------------------------------
CEnemy &CEnemy::operator=(const CEnemy& enemy)
{
	m_nAttack = enemy.m_nAttack;

	return *this;
}

//-------------------------------------
// 前置インクリメントのオーバーロード
//-------------------------------------
CEnemy& CEnemy::operator++(void)
{
	m_nAttack++;

	return *this;
}

//-------------------------------------
// 後置インクリメントのオーバーロード
//-------------------------------------
CEnemy CEnemy::operator++(int)
{
	CEnemy enemyWk;

	enemyWk = *this;

	m_nAttack++;

	return enemyWk;
}

//-------------------------------------
// 初期化処理
//-------------------------------------
void CEnemy::Init(void)
{
	m_nLife = 100;
	m_nAttack = 50;
	m_nSpeed = 20;
}

//-------------------------------------
// 終了処理
//-------------------------------------
void CEnemy::Uninit(void)
{

}

//-------------------------------------
// 入力処理
//-------------------------------------
void CEnemy::Input(void)
{
	printf("体力を入力してください > ");
	scanf("%d", &m_nLife);
	printf("攻撃力を入力してください > ");
	scanf("%d", &m_nAttack);
	printf("素早さを入力してください > ");
	scanf("%d", &m_nSpeed);
}

//-------------------------------------
// 出力処理
//-------------------------------------
void CEnemy::Output(void)
{
	printf("\n体力: %d\n", m_nLife);
	printf("攻撃力: %d\n", m_nAttack);
	printf("素早さ: %d\n", m_nSpeed);
}

//-------------------------------------
// 攻撃力の設定処理
//-------------------------------------
void CEnemy::SetAttack(const int nAttack)
{
	m_nAttack = nAttack;
}

//-------------------------------------
// 攻撃力の取得処理
//-------------------------------------
int CEnemy::GetAttack(void) const
{
	return m_nAttack;
}

////-------------------------------------
//// 攻撃力のみの入力処理
////-------------------------------------
//void CEnemy::AttackInput(void)
//{
//	printf("\n攻撃力を再入力してください > ");
//	scanf("%d", &m_nAttack);
//}
//
//
////-------------------------------------
//// 攻撃力のみの出力処理
////-------------------------------------
//void CEnemy::AttackOutput(void)
//{
//	printf("\n攻撃力を再出力 > %d\n", m_nAttack);
//}