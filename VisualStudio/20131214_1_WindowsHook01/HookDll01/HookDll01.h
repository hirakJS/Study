// 以下の ifdef ブロックは DLL からのエクスポートを容易にするマクロを作成するための 
// 一般的な方法です。この DLL 内のすべてのファイルは、コマンド ラインで定義された HOOKDLL01_EXPORTS
// シンボルを使用してコンパイルされます。このシンボルは、この DLL を使用するプロジェクトでは定義できません。
// ソースファイルがこのファイルを含んでいる他のプロジェクトは、 
// HOOKDLL01_API 関数を DLL からインポートされたと見なすのに対し、この DLL は、このマクロで定義された
// シンボルをエクスポートされたと見なします。
#ifdef HOOKDLL01_EXPORTS
#define HOOKDLL01_API __declspec(dllexport)
#else
#define HOOKDLL01_API __declspec(dllimport)
#endif

typedef void(*MSG_CALLBACK)(TCHAR *msg);

// このクラスは HookDll01.dll からエクスポートされました。
class HOOKDLL01_API CHookDll01 {
public:
	CHookDll01(void);
	// TODO: メソッドをここに追加してください。
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
