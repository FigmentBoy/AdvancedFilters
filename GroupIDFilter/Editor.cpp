#include "Editor.h"
#include "GroupIDInputLayer.h"
void __fastcall Editor::hkSelectObject(CCLayer* self, void*, void* b, bool something) {
	short* addy = *(short**)((uintptr_t)b + 0x3F4);

	if (id == 0) {
		return selectObject(self, b, something);
	}
	if (addy != nullptr) {
		for (int i = 0; i < 10; i++) {
			if (addy[i] == id) {
				return selectObject(self, b, something);
			}
		}
	}
	
}


void __fastcall Editor::hkSelectObjects(CCLayer* self, void*, CCArray* b, bool something) {
	if (id == 0) {
		return selectObjects(self, b, something);
	}

	int i = 0;
	while (i < b->count()) {
		short* addy = *(short**)((uintptr_t)b->objectAtIndex(i) + 0x3F4);

		if (addy != nullptr) {
			bool has = false;
			for (int j = 0; j < 10; j++) {
				if (addy[j] == id) {
					has = true;
				}
			}

			if (!has) {
				b->removeObjectAtIndex(i);
			}
			else {
				i++;
			}
		} else {
			b->removeObjectAtIndex(i);
		}
	}
	
	return selectObjects(self, b, something);
}


int __fastcall Editor::hkInit(CCLayer* self, void*, void* b) {
	int res = init(self, b);

	auto image = new CCImage;
	image->initWithImageFile("square01_001.png");

	auto texture = new CCTexture2D;
	texture->initWithImage(image);

	auto sprite = CCSprite::createWithTexture(texture);

	CCMenuItemSpriteExtra* btn = CCMenuItemSpriteExtra::create(sprite, sprite, self, menu_selector(GroupIDInputLayer::onOpen));
	btn->setScale(0.375);

	auto size = btn->getContentSize();

	auto title = cocos2d::CCLabelBMFont::create("ID", "bigFont.fnt");
	title->setPosition(size / 2);
	btn->addChild(title);

	CCMenu* menu = CCMenu::createWithItem(btn);
	menu->setPosition(65, 210);
	
	self->addChild(menu);
	return res;
}

void Editor::mem_init() {
	uintptr_t base = (uintptr_t)GetModuleHandle(0);
	
	MH_CreateHook(
		(PVOID) (base + 0x86250),
		Editor::hkSelectObject,
		(PVOID*)&Editor::selectObject
	);

	MH_CreateHook(
		(PVOID)(base + 0x864A0),
		Editor::hkSelectObjects,
		(PVOID*)&Editor::selectObjects
	);

	MH_CreateHook(
		(PVOID)(base + 0x76310),
		Editor::hkInit,
		(PVOID*)&Editor::init
	);
}