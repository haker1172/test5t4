#pragma once


struct Weapon
{
public:
	int ammo; // 0x0
};

namespace functions
{
	// Weapon
	typedef void* (__thiscall* _AddAmmo)(Weapon* weapon, int value);
	_AddAmmo AddAmmo = reinterpret_cast<_AddAmmo>(0x159D0);
	// Weapon End
}