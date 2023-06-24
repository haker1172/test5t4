#pragma once
#include <Windows.h>
//#include "main.h"

class dllMain
{
public:
	static DWORD __stdcall MainThread(LPVOID param);
	static HMODULE handle_module;
	static HANDLE main_thread;
};