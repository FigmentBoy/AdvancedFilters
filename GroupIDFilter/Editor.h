#pragma once
#include <cocos2d.h>
#include "MinHook.h"
#include <iostream>
#include <vector>

using namespace cocos2d;
namespace Editor {
	void __fastcall hkSelectObject(void*, void*, void*, bool);
	inline void(__thiscall* selectObject)(void*, void*, bool);

	int __fastcall hkInit(CCLayer*, void*, void*);
	inline int(__thiscall* init)(CCLayer*, void*);

	void mem_init();
}