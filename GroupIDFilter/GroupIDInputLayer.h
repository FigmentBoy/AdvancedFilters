#pragma once
#include "BrownAlertDelegate.hpp"
#include "CustomTextInputNode.h"

class GroupIDInputLayer : public BrownAlertDelegate {
protected:
	CustomTextInputNode* m_pTextInput;
	
    void setup();
	virtual void onClose(cocos2d::CCObject*) override;
	virtual void keyBackClicked() override;
public:
	inline void onOpen(cocos2d::CCObject* sender) {
		GroupIDInputLayer::create()->show();
	}

    static GroupIDInputLayer* create();
};