#include "GroupIDInputLayer.h"

void GroupIDInputLayer::setup() {
	m_pTextInput = (CustomTextInputNode*)gd::CCTextInputNode::create("id", this, "bigFont.fnt", 50.f, 40.f);;
	m_pTextInput->setAllowedChars("1234567890");
	m_pTextInput->setLabelPlaceholderColor({ 200, 200, 200 });
	m_pTextInput->setMaxLabelLength(3);
	//m_pTextInput->setPosition(m_pLrSize.width / 2, m_pLrSize.height / 2);
	m_pTextInput->setMaxLabelScale(3.f / 5.f);
	m_pTextInput->setZOrder(100000);

	if (Editor::id != 0) {
		m_pTextInput->setString(std::to_string(Editor::id));
	}

	auto pathBG = extension::CCScale9Sprite::create("square02b_small.png");
	pathBG->setColor({ 0, 0, 0 });
	//pathBG->setPosition(m_pLrSize.width / 2, m_pLrSize.height / 2);
	pathBG->setContentSize({ 50.f, 40.f });
	pathBG->setOpacity(75);

	auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
	auto title = cocos2d::CCLabelBMFont::create("GroupID Filter", "goldFont.fnt", 0.f, kCCTextAlignmentCenter);

	title->limitLabelWidth(this->m_pLrSize.width * 4, .75f, .2f);
	title->setPosition(
		winSize.width / 2,
		winSize.height / 2 + this->m_pLrSize.height / 2 - 25
	);

	this->m_pLayer->addChild(title);

	this->m_pButtonMenu->addChild(m_pTextInput);
	this->m_pButtonMenu->addChild(pathBG);

	this->setKeyboardEnabled(true);
}

GroupIDInputLayer* GroupIDInputLayer::create() {
    auto pRet = new GroupIDInputLayer();
    if (pRet && pRet->init(200.0f, 165.0f)) {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

void GroupIDInputLayer::onClose(cocos2d::CCObject* a) {
	Editor::id = m_pTextInput->getString().length() > 0 ? std::stoi(m_pTextInput->getString()) : 0;
	BrownAlertDelegate::onClose(a);
}

void GroupIDInputLayer::keyBackClicked() {
	Editor::id = m_pTextInput->getString().length() > 0 ? std::stoi(m_pTextInput->getString()) : 0;
	BrownAlertDelegate::onClose(nullptr);
}