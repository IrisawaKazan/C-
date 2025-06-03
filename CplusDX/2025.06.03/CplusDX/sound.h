////==============================================================
////
//// [sound.h]
//// Author: Irisawa Kazan
////
////==============================================================
//#ifndef _SOUND_H_ // このマクロ定義がされてなかったら
//#define _SOUND_H_ // 2重インクルード防止のマクロ定義
//
//#include"main.h"
//
//// サウンドクラス
//class CSound
//{
//public:
//	// サウンド一覧
//	typedef enum
//	{
//		SOUND_LABEL_BGM = 0,
//		SOUND_LABEL_SHOT01,
//		SOUND_LABEL_MAX,
//	} SOUND_LABEL;
//
//	CSound();
//	~CSound();
//
//	HRESULT InitSound(HWND hWnd);
//	void UninitSound(void);
//
//	HRESULT PlaySound(SOUND_LABEL label);
//	void StopSound(SOUND_LABEL label);
//	void StopSound(void);
//
//	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD* pChunkSize, DWORD* pChunkDataPosition);
//	HRESULT ReadChunkData(HANDLE hFile, void* pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);
//
//private:
//	typedef struct
//	{
//		const char* m_pFilename;                    // ファイル名
//		int m_nCntLoop;			                    // ループカウント
//	} SOUNDINFO;
//
//	IXAudio2* m_pXAudio2;								   // XAudio2オブジェクトへのインターフェイス
//	IXAudio2MasteringVoice* m_pMasteringVoice;			   // マスターボイス
//	IXAudio2SourceVoice* m_apSourceVoice[SOUND_LABEL_MAX]; // ソースボイス
//	BYTE* m_apDataAudio[SOUND_LABEL_MAX];				   // オーディオデータ
//	DWORD m_aSizeAudio[SOUND_LABEL_MAX];				   // オーディオデータサイズ
//
//	// サウンドの情報
//	SOUNDINFO m_aSoundInfo[SOUND_LABEL_MAX] = 
//	{
//		{"data/BGM/Future_3.wav", -1}, // BGM1
//		{"data/SE/tama.wav", 0},       // SE1
//
//	};
//};
//
//#endif