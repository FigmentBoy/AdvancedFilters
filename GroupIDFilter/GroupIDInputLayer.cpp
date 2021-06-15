#include "GroupIDInputLayer.h"
#include "GetPlaceholderLabelTextInputNode.h"

void GroupIDInputLayer::setup() {
	auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
	auto title = cocos2d::CCLabelBMFont::create("Advanced Filters", "goldFont.fnt", 0.f, kCCTextAlignmentCenter);
	auto check_off_sprite = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
	auto check_on_sprite = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");

	title->setPosition(
		winSize.width / 2,
		winSize.height / 2 + this->m_pLrSize.height / 2 - 25
	);

	

	m_groupInput = (CustomTextInputNode*)gd::CCTextInputNode::create(" Group ID ", this, "bigFont.fnt", 70.f, 40.f);;
	m_groupInput->setAllowedChars("1234567890");
	m_groupInput->setLabelPlaceholderColor({ 200, 200, 200 });
	m_groupInput->setMaxLabelLength(4);
	m_groupInput->setPosition(-157.5, m_pLrSize.height / 2 - 90);
	m_groupInput->setMaxLabelScale(3.f / 5.f);
	m_groupInput->setZOrder(100000);

	auto m_groupInputPath = extension::CCScale9Sprite::create("square02b_small.png");
	m_groupInputPath->setColor({ 0, 0, 0 });
	m_groupInputPath->setPosition(-157.5, m_pLrSize.height / 2 - 90);
	m_groupInputPath->setContentSize({ 70.f, 40.f });
	m_groupInputPath->setOpacity(75);

	if (Editor::filter_id) {
		m_groupInput->setString(std::to_string(Editor::id));
	}

	m_scaleInput = (CustomTextInputNode*)gd::CCTextInputNode::create(" Scale ", this, "bigFont.fnt", 70.f, 40.f);;
	m_scaleInput->setAllowedChars("-.1234567890");
	m_scaleInput->setLabelPlaceholderColor({ 200, 200, 200 });
	m_scaleInput->setMaxLabelLength(5);
	m_scaleInput->setPosition(-78.75, m_pLrSize.height / 2 - 90);
	m_scaleInput->setMaxLabelScale(3.f / 5.f);
	m_scaleInput->setZOrder(100000);

	auto m_scaleInputPath = extension::CCScale9Sprite::create("square02b_small.png");
	m_scaleInputPath->setColor({ 0, 0, 0 });
	m_scaleInputPath->setPosition(-78.75, m_pLrSize.height / 2 - 90);
	m_scaleInputPath->setContentSize({ 70.f, 40.f });
	m_scaleInputPath->setOpacity(75);

	if (Editor::filter_scale) {
		m_scaleInput->setString(std::to_string(Editor::scale));
	}

	m_zOrder = (CustomTextInputNode*)gd::CCTextInputNode::create(" Z Order ", this, "bigFont.fnt", 70.f, 40.f);;
	m_zOrder->setAllowedChars("-1234567890");
	m_zOrder->setLabelPlaceholderColor({ 200, 200, 200 });
	m_zOrder->setMaxLabelLength(4);
	m_zOrder->setPosition(0, m_pLrSize.height / 2 - 90);
	m_zOrder->setMaxLabelScale(3.f / 5.f);
	m_zOrder->setZOrder(100000);

	auto m_zOrderPath = extension::CCScale9Sprite::create("square02b_small.png");
	m_zOrderPath->setColor({ 0, 0, 0 });
	m_zOrderPath->setPosition(0, m_pLrSize.height / 2 - 90);
	m_zOrderPath->setContentSize({ 70.f, 40.f });
	m_zOrderPath->setOpacity(75);

	if (Editor::filter_z_order) {
		m_zOrder->setString(std::to_string(Editor::z_order));
	}

	m_col1Input = (CustomTextInputNode*)gd::CCTextInputNode::create(" Color 1 ", this, "bigFont.fnt", 70.f, 40.f);
	m_col1Input->setAllowedChars("1234567890");
	m_col1Input->setLabelPlaceholderColor({ 200, 200, 200 });
	m_col1Input->setMaxLabelLength(4);
	m_col1Input->setPosition(78.75, m_pLrSize.height / 2 - 90);
	m_col1Input->setMaxLabelScale(3.f / 5.f);
	m_col1Input->setZOrder(100000);


	auto m_col1InputPath = extension::CCScale9Sprite::create("square02b_small.png");
	m_col1InputPath->setColor({ 0, 0, 0 });
	m_col1InputPath->setPosition(78.75, m_pLrSize.height / 2 - 90);
	m_col1InputPath->setContentSize({ 70.f, 40.f });
	m_col1InputPath->setOpacity(75);

	if (Editor::filter_color_id_1) {
		m_col1Input->setString(std::to_string(Editor::color_id_1));
	}

	m_col2Input = (CustomTextInputNode*)gd::CCTextInputNode::create(" Color 2 ", this, "bigFont.fnt", 70.f, 40.f);
	m_col2Input->setAllowedChars("1234567890");
	m_col2Input->setLabelPlaceholderColor({ 200, 200, 200 });
	m_col2Input->setMaxLabelLength(4);
	m_col2Input->setPosition(157.5, m_pLrSize.height / 2 - 90);
	m_col2Input->setMaxLabelScale(3.f / 5.f);
	m_col2Input->setZOrder(100000);


	auto m_col2InputPath = extension::CCScale9Sprite::create("square02b_small.png");
	m_col2InputPath->setColor({ 0, 0, 0 });
	m_col2InputPath->setPosition(157.5, m_pLrSize.height / 2 - 90);
	m_col2InputPath->setContentSize({ 70.f, 40.f });
	m_col2InputPath->setOpacity(75);
	
	if (Editor::filter_color_id_2) {
		m_col2Input->setString(std::to_string(Editor::color_id_2));
	}
	
	m_lowDetail = gd::CCMenuItemToggler::createWithStandardSprites(this, menu_selector(GroupIDInputLayer::on_lowDetail));
	m_lowDetail->setPosition(-m_pLrSize.width / 2 + 50, m_pLrSize.height / 2 - 140);
	auto m_lowDetailText = cocos2d::CCLabelBMFont::create("Low Detail", "bigFont.fnt", 0.f, kCCTextAlignmentCenter);
	m_lowDetailText->setScale(0.75);
	m_lowDetailText->setPosition(-m_pLrSize.width / 2 + m_lowDetailText->getScaledContentSize().width / 2 + 75, m_pLrSize.height / 2 - 140);

	m_highDetail = gd::CCMenuItemToggler::createWithStandardSprites(this, menu_selector(GroupIDInputLayer::on_highDetail));
	m_highDetail->setPosition(-m_pLrSize.width / 2 + 50, m_pLrSize.height / 2 - 180);
	auto m_highDetailText = cocos2d::CCLabelBMFont::create("High Detail", "bigFont.fnt", 0.f, kCCTextAlignmentCenter);
	m_highDetailText->setScale(0.75);
	m_highDetailText->setPosition(-m_pLrSize.width / 2 + m_highDetailText->getScaledContentSize().width / 2 + 75, m_pLrSize.height / 2 - 180);

	m_lowDetail->toggle(Editor::filter_low_detail);
	m_highDetail->toggle(Editor::filter_high_detail);

	float first = 0;
	float last = 0;
	float spacing = 0;
	for (int i = 0; i <= 3; i++) {
		auto sprite_off = gd::ButtonSprite::create((std::string("B") + std::to_string(4 - i)).c_str(), 20, true, "bigFont.fnt", "GJ_button_04.png", 25, 1);
		auto sprite_on = gd::ButtonSprite::create((std::string("B") + std::to_string(4 - i)).c_str(), 20, true, "bigFont.fnt", "GJ_button_02.png", 25, 1);
		auto button = gd::CCMenuItemToggler::create(sprite_off, sprite_on, this, menu_selector(GroupIDInputLayer::on_zLayer));
		addZLayerButton(button);

		if (first == 0) {
			float width = sprite_off->getScaledContentSize().width;
			first = 17.5 + (width / 2);
			last = 192.5 - (width / 2);
			spacing = ((225 - first - (225 - last)) / 3);
		}
		
		button->setPosition(first + i * spacing, m_pLrSize.height / 2 - 140);

		if (Editor::filter_z_layer) {
			if ((Editor::z_layer + 3) / 2 == i) {
				button->toggle(true);
			}
		}
		this->m_pButtonMenu->addChild(button);
	}

	for (int i = 0; i <= 2; i++) {
		auto sprite_off = gd::ButtonSprite::create((std::string("T") + std::to_string(i + 1)).c_str(), 20, true, "bigFont.fnt", "GJ_button_04.png", 25, 1);
		auto sprite_on = gd::ButtonSprite::create((std::string("T") + std::to_string(i + 1)).c_str(), 20, true, "bigFont.fnt", "GJ_button_02.png", 25, 1);
		auto button = gd::CCMenuItemToggler::create(sprite_off, sprite_on, this, menu_selector(GroupIDInputLayer::on_zLayer));
		addZLayerButton(button);

		if (Editor::filter_z_layer) {
			if ((Editor::z_layer + 3) / 2 == i + 4) {
				button->toggle(true);
			}
		}

		button->setPosition(((first + last) / 2) + (spacing * (i - 1)), m_pLrSize.height / 2 - 170);
		this->m_pButtonMenu->addChild(button);
	}

	this->m_pLayer->addChild(title);

	this->m_pButtonMenu->addChild(m_groupInput);
	this->m_pButtonMenu->addChild(m_groupInputPath);

	this->m_pButtonMenu->addChild(m_scaleInput);
	this->m_pButtonMenu->addChild(m_scaleInputPath);

	this->m_pButtonMenu->addChild(m_zOrder);
	this->m_pButtonMenu->addChild(m_zOrderPath);

	this->m_pButtonMenu->addChild(m_col1Input);
	this->m_pButtonMenu->addChild(m_col1InputPath);

	this->m_pButtonMenu->addChild(m_col2Input);
	this->m_pButtonMenu->addChild(m_col2InputPath);

	this->m_pButtonMenu->addChild(m_lowDetail);
	this->m_pButtonMenu->addChild(m_lowDetailText);
	this->m_pButtonMenu->addChild(m_highDetail);
	this->m_pButtonMenu->addChild(m_highDetailText);


	this->setKeyboardEnabled(true);
}

GroupIDInputLayer* GroupIDInputLayer::create() {
    auto pRet = new GroupIDInputLayer();
    if (pRet && pRet->init(450.0f, 300.0f)) {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

void GroupIDInputLayer::on_lowDetail(cocos2d::CCObject*) {
	if (!m_lowDetail->isToggled()) {
		m_highDetail->toggle(false);
		Editor::filter_high_detail = false;
	}
	Editor::filter_low_detail = !m_lowDetail->isToggled();
};
 
void GroupIDInputLayer::on_highDetail(cocos2d::CCObject*) {
	if (!m_highDetail->isToggled()) {
		m_lowDetail->toggle(false);
		Editor::filter_low_detail = false;
	}
	Editor::filter_high_detail = !m_highDetail->isToggled();
};

void GroupIDInputLayer::on_zLayer(cocos2d::CCObject* pSender) {
	if (!((gd::CCMenuItemToggler*)pSender)->isToggled()) {
		clearZLayers();
		Editor::filter_z_layer = true;
		Editor::z_layer = getZLayer((gd::CCMenuItemToggler*)pSender);
	}
	else {
		Editor::filter_z_layer = false;
	}
}

void GroupIDInputLayer::saveSettings() {
	Editor::id = m_groupInput->getString().length() > 0 ? std::stoi(m_groupInput->getString()) : 0;
	Editor::filter_id = m_groupInput->getString().length() > 0;

	Editor::scale = m_scaleInput->getString().length() > 0 ? std::stof(m_scaleInput->getString()) : 0;
	Editor::filter_scale = m_scaleInput->getString().length() > 0;

	Editor::z_order = m_zOrder->getString().length() > 0 ? std::stoi(m_zOrder->getString()) : 0;
	Editor::filter_z_order = m_zOrder->getString().length() > 0;

	Editor::color_id_1 = m_col1Input->getString().length() > 0 ? std::stoi(m_col1Input->getString()) : 0;
	Editor::filter_color_id_1 = m_col1Input->getString().length() > 0;

	Editor::color_id_2 = m_col2Input->getString().length() > 0 ? std::stoi(m_col2Input->getString()) : 0;
	Editor::filter_color_id_2 = m_col2Input->getString().length() > 0;
}

void GroupIDInputLayer::onClose(cocos2d::CCObject* a) {
	saveSettings();
	BrownAlertDelegate::onClose(a);
}

void GroupIDInputLayer::keyBackClicked() {
	saveSettings();
	BrownAlertDelegate::onClose(nullptr);
}