#include "Editor.h"
#include "GroupIDInputLayer.h"
#include "GameObject.h"

bool check(GameObject* obj) {
	if (Editor::filter_id) {
		short count = obj->getGroupIDCount();
		bool has_id = false;

		if (count != 0) {
			for (int i = 0; i < count; i++) {
				if (obj->getGroupID(i) == Editor::id) {
					has_id = true;
				}
			}
		}

		if (!has_id) {
			return false;
		}
	}

	if (Editor::filter_scale) {
		if (obj->getScale() != Editor::scale) {
			return false;
		}
	}

	if (Editor::filter_color_id_1) {
		if (!obj->getBaseColor() || obj->getBaseColor()->colorID != Editor::color_id_1) {
			return false;
		}
	}

	if (Editor::filter_color_id_2) {
		if (!obj->getDetailColor() || obj->getDetailColor()->colorID != Editor::color_id_2) {
			return false;
		}
	}

	if (Editor::filter_z_order) {
		if (obj->getZOrder() != Editor::z_order) {
			return false;
		}

	}

	if (Editor::filter_z_layer) {
		if (obj->getZLayer() % 2 == 0 || obj->getZLayer() != Editor::z_layer) {
			return false;
		}
	}

	if (Editor::filter_high_detail) {
		if (!obj->isHighDetail()) {
			return false;
		}
	}

	if (Editor::filter_low_detail) {
		if (obj->isHighDetail()) {
			return false;
		}
	}

	return true;
}

void __fastcall Editor::hkSelectObject(CCLayer* self, void*, gd::GameObject* b, bool something) {
	if (check((GameObject*)b)) {
		return selectObject(self, b, something);
	}
}


void __fastcall Editor::hkSelectObjects(CCLayer* self, void*, CCArray* b, bool something) {
	int i = 0;
	while (i < b->count()) {
		if (!check((GameObject*)b->objectAtIndex(i))) {
			b->removeObjectAtIndex(i);
		}
		else {
			i++;
		}
	}
	
	return selectObjects(self, b, something);
}


int __fastcall Editor::hkInit(CCLayer* self, void*, void* b) {
	int res = init(self, b);

	auto sprite = CCSprite::create("GJ_button_01.png");

	CCMenuItemSpriteExtra* btn = CCMenuItemSpriteExtra::create(sprite, sprite, self, menu_selector(GroupIDInputLayer::onOpen));
	btn->setScale(0.8);

	auto size = btn->getContentSize();

	auto title = cocos2d::CCLabelBMFont::create("ID", "bigFont.fnt");
	title->setPosition({ size.width / 2.f, size.height / 2.f + 1.f }); // the + 1.f is very important, it keeps my sanity
	title->setScale(0.75);
	btn->addChild(title);

	CCMenu* menu = CCMenu::createWithItem(btn);
	auto winSize = CCDirector::sharedDirector()->getWinSize();
	menu->setPosition(winSize.width - 140, winSize.height - 60);
	

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