#pragma once
#include <cocos2d.h>
#include <cocos-ext.h>
#include "MinHook.h"
#include <iostream>
#include <vector>
#include "CustomTextInputNode.h"

using namespace cocos2d;
namespace Editor {
	inline int id = 0;

	void __fastcall hkSelectObject(CCLayer*, void*, void*, bool);
	inline void(__thiscall* selectObject)(CCLayer*, void*, bool);

	void __fastcall hkSelectObjects(CCLayer*, void*, CCArray*, bool);
	inline void(__thiscall* selectObjects)(CCLayer*, CCArray*, bool);

	int __fastcall hkInit(CCLayer*, void*, void*);
	inline int(__thiscall* init)(CCLayer*, void*);

	void mem_init();
}