#include "OpenGIDButton.h"
#include "GroupIDInputLayer.h"

void OpenGIDButton::onPress(CCObject* sender) {
	GroupIDInputLayer::create()->show();
}