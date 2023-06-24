#include "dllMain.h"
#include "main.h"

HMODULE dllMain::handle_module = nullptr;
HANDLE dllMain::main_thread = nullptr;

DWORD __stdcall dllMain::MainThread(LPVOID param)
{
	main::Run();
	FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(param), 0);
}


BOOL __stdcall DllMain(HMODULE instance, DWORD reason, LPVOID reserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		dllMain::handle_module = instance;
		DisableThreadLibraryCalls(dllMain::handle_module);
		dllMain::main_thread = CreateThread(NULL, NULL, dllMain::MainThread, dllMain::handle_module, NULL, NULL);
		break;
	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}