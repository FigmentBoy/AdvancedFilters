#pragma once
#include "gd.h"

class GetPlaceholderLabelTextInputNode : public gd::CCTextInputNode {
public:
	cocos2d::CCLabelBMFont* getLabel() {
		return m_pPlaceholderLabel;
	}
};