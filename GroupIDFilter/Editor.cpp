#include "Editor.h"

static int id = 0;

void __fastcall Editor::hkSelectObject(void* self, void*, void* b, bool something) {
	short* addy = *(short**)((uintptr_t)b + 0x3F4);

	if (id == 0) {
		return selectObject(self, b, something);
	}
	if (addy != nullptr) {
		for (int i = 0; i < 10; i++) {
			if (addy[i] == 1) {
				return selectObject(self, b, something);
			}
		}
	}
	
}

int __fastcall Editor::hkInit(CCLayer* self, void*, void* b) {

	return init(self, b);
}

void Editor::mem_init() {
	uintptr_t base = (uintptr_t)GetModuleHandle(0);
	
	MH_CreateHook(
		(PVOID) (base + 0x86250),
		Editor::hkSelectObject,
		(PVOID*)&Editor::selectObject
	);
}