//==============================================================
//
// [sound.h]
// Author: Irisawa Kazan
//
//==============================================================
#ifndef _SOUND_H_ // ���̃}�N����`������ĂȂ�������
#define _SOUND_H_ // 2�d�C���N���[�h�h�~�̃}�N����`

#include"main.h"

// �T�E���h�N���X
class CSound
{
public:
	// �T�E���h�ꗗ
	typedef enum
	{
		SOUND_LABEL_MAINBGM = 0, // ���C����BGM

		SOUND_LABEL_MAX,
	} SOUND_LABEL;

	CSound();
	~CSound();

	HRESULT Init(HWND hWnd);
	void Uninit(void);
	HRESULT PlaySound(SOUND_LABEL label);
	void Stop(SOUND_LABEL label);
	void Stop(void);
	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD* pChunkSize, DWORD* pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void* pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

private:
	typedef struct
	{
		const char* m_pFilename; // �t�@�C����
		int m_nCntLoop;          // ���[�v�J�E���g
	} SOUNDINFO;

	IXAudio2* m_pXAudio2 = NULL;                                // XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	IXAudio2MasteringVoice* m_pMasteringVoice = NULL;           // �}�X�^�[�{�C�X
	IXAudio2SourceVoice* m_apSourceVoice[SOUND_LABEL_MAX] = {}; // �\�[�X�{�C�X
	BYTE* m_apDataAudio[SOUND_LABEL_MAX] = {};                  // �I�[�f�B�I�f�[�^
	DWORD m_aSizeAudio[SOUND_LABEL_MAX] = {};                   // �I�[�f�B�I�f�[�^�T�C�Y
	SOUNDINFO m_aSoundInfo[SOUND_LABEL_MAX] = 
	{
		{"data/BGM/sample_bgm.wav", 0}, // �T���v�����C��BGM

	};
};

#endif