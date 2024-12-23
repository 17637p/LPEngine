#include "DefaultDemo.h"

#ifdef _DEBUG
#pragma comment(lib, "../x64/Debug/LPCommon.lib")
#else
#pragma comment(lib, "../x64/Release/LPCommon.lib")
#endif // DEBUG

/// Demo EntryPoint
/// 2024.12.23 YuJin
/// Math는 Directx::SimpleMath 를 사용한다. 
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Chase Memory Leak
	//_crtBreakAlloc = 101010; //_CrtSetBreakAlloc(101010); // Chase Memory Leak Line
#endif

	DefaultDemo* demo = new DefaultDemo;

	demo->Init(hInstance);
	demo->Loop();
	demo->Finalize();

	delete demo;

	return 0;
}