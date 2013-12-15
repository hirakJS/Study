// HookDll01.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"
#include <tchar.h>
#include "HookDll01.h"

#pragma data_seg( ".CKHookData" )
HINSTANCE g_hInst = NULL;
HHOOK	g_hHook = NULL;
#pragma data_seg()

MSG_CALLBACK g_pfnMSG_CALLBACK = NULL;

// これは、エクスポートされた変数の例です。
HOOKDLL01_API int nHookDll01=0;

// これは、エクスポートされた関数の例です。
HOOKDLL01_API int fnHookDll01(void)
{
	return 42;
}

// これは、エクスポートされたクラスのコンストラクターです。
// クラス定義に関しては HookDll01.h を参照してください。
CHookDll01::CHookDll01()
{
	return;
}

HOOKDLL01_API int StartHook(void)
{
	g_hHook = ::SetWindowsHookEx(WH_CALLWNDPROC
		, (HOOKPROC)GetMsgProc
		, g_hInst	//この行を変更。
		, 0);

	if (!g_hHook)
		return FALSE;

	return TRUE;
}
HOOKDLL01_API int EndHook(void)
{
	::OutputDebugString(_T("EndHook is called.\n"));
	return ::UnhookWindowsHookEx(g_hHook);
}

LRESULT CALLBACK GetMsgProc(
	_In_  int code,
	_In_  WPARAM wParam,
	_In_  LPARAM lParam
	)
{
	LPMSG msg = (LPMSG)lParam;
	TCHAR szMsg[1024];
	memset(szMsg, NULL, sizeof(szMsg));
	::wsprintf(szMsg+lstrlen(szMsg), _T("msg->time=%d\n"), msg->time); //::myOutputDebugString(szMsg);
	::wsprintf(szMsg + lstrlen(szMsg), _T("lParam=0x%X\n"), lParam); //::myOutputDebugString(szMsg);
	::wsprintf(szMsg + lstrlen(szMsg), _T("wParam=0x%X\n"), wParam); ::myOutputDebugString(szMsg);
	//::myOutputDebugString(_T("GetMsgProc is called.\n"));
	return CallNextHookEx(NULL, code, wParam, lParam);
}


HOOKDLL01_API BOOL RegisterMsgCallback(MSG_CALLBACK pfn)
{
	if (pfn)
	{
		g_pfnMSG_CALLBACK = pfn;
		return TRUE;
	}
	return FALSE;
}

void myOutputDebugString(TCHAR* msg){
	::OutputDebugString(msg);
	if (g_pfnMSG_CALLBACK)
	{
		g_pfnMSG_CALLBACK(msg);
	}
}
