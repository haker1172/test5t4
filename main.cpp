#include "main.h"

uintptr_t main::baseModule = NULL;

int main::Run()
{
	baseModule = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL));
	Weapon* weapon = reinterpret_cast<Weapon*>(*(uintptr_t*)(baseModule + 0x22440));
	functions::AddAmmo(weapon, 2000000);
	return 0;
}