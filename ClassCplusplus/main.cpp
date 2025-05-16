//========================================
//
// クラス・ファイル分割[main.cpp]
// Author: Irisawa Kazan	
//
//========================================
#include"main.h"
#include"process.h"

//----------------------------
// メイン関数
//----------------------------
int main(void)
{
	CProcess process; // プロセスオブジェクトを生成

	// 初期化処理
	process.Init();

	// 選択処理
	process.SelectMode();

	// 終了処理
	process.Uninit();

	// キー入力待ち
	printf("\n--- エンターキーで終了 ---");
	rewind(stdin);
	getchar();
	return 0;
}