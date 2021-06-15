#pragma once
#include <cocos2d.h>
#include <cocos-ext.h>
#include "MinHook.h"
#include <iostream>
#include <vector>
#include "CustomTextInputNode.h"

using namespace cocos2d;
namespace Editor {
	inline bool filter_scale = false;
	inline int scale = 0;

	inline bool filter_rotation = false;
	inline int rotation = 0;

	inline bool filter_id = false;
	inline int id = 0;

	inline bool filter_high_detail = false;
	inline bool filter_low_detail = false;

	inline bool filter_z_order = false;
	inline int z_order = 0;

	inline bool filter_z_layer = false;
	inline int z_layer = 0;

	inline bool filter_color_id_1 = false;
	inline int color_id_1 = 0;

	inline bool filter_color_id_2 = false;
	inline int color_id_2 = 0;

	void __fastcall hkSelectObject(CCLayer*, void*, gd::GameObject*, bool);
	inline void(__thiscall* selectObject)(CCLayer*, void*, bool);

	void __fastcall hkSelectObjects(CCLayer*, void*, CCArray*, bool);
	inline void(__thiscall* selectObjects)(CCLayer*, CCArray*, bool);

	int __fastcall hkInit(CCLayer*, void*, void*);
	inline int(__thiscall* init)(CCLayer*, void*);

	void mem_init();
}