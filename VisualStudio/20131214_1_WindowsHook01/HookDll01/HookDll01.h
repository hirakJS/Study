// �ȉ��� ifdef �u���b�N�� DLL ����̃G�N�X�|�[�g��e�Ղɂ���}�N�����쐬���邽�߂� 
// ��ʓI�ȕ��@�ł��B���� DLL ���̂��ׂẴt�@�C���́A�R�}���h ���C���Œ�`���ꂽ HOOKDLL01_EXPORTS
// �V���{�����g�p���ăR���p�C������܂��B���̃V���{���́A���� DLL ���g�p����v���W�F�N�g�ł͒�`�ł��܂���B
// �\�[�X�t�@�C�������̃t�@�C�����܂�ł��鑼�̃v���W�F�N�g�́A 
// HOOKDLL01_API �֐��� DLL ����C���|�[�g���ꂽ�ƌ��Ȃ��̂ɑ΂��A���� DLL �́A���̃}�N���Œ�`���ꂽ
// �V���{�����G�N�X�|�[�g���ꂽ�ƌ��Ȃ��܂��B
#ifdef HOOKDLL01_EXPORTS
#define HOOKDLL01_API __declspec(dllexport)
#else
#define HOOKDLL01_API __declspec(dllimport)
#endif

typedef void(*MSG_CALLBACK)(TCHAR *msg);

// ���̃N���X�� HookDll01.dll ����G�N�X�|�[�g����܂����B
class HOOKDLL01_API CHookDll01 {
public:
	CHookDll01(void);
	// TODO: ���\�b�h�������ɒǉ����Ă��������B
};

extern HOOKDLL01_API int nHookDll01;

HOOKDLL01_API int fnHookDll01(void);
HOOKDLL01_API int StartHook(void);
HOOKDLL01_API int EndHook(void);
HOOKDLL01_API BOOL RegisterMsgCallback(MSG_CALLBACK pfn);


LRESULT CALLBACK GetMsgProc(
	_In_  int code,
	_In_  WPARAM wParam,
	_In_  LPARAM lParam
	);

void myOutputDebugString(TCHAR* msg);
