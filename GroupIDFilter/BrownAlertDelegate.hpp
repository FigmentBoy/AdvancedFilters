#pragma once

// i myself have one header file that
// includes cocos, gd.h, etc.
// i recommend that for you aswell

// include cocos2d
#include <cocos2d.h>
#include <cocos-ext.h>
// if you don't use GD.h, just change
// the class inherited from  below to
// your FLAlertLayer
#include <gd.h>

class BrownAlertDelegate : public gd::FLAlertLayer {
protected:
    // layer size is stored here
    cocos2d::CCSize m_pLrSize;

    // override this to add your own
    // layer code
    virtual void setup() = 0;

    // dont override this one
    // the floats are width and height
    // the background sprite may be changed
    inline virtual bool init(float _w, float _h, const char* _spr = "GJ_square01.png") {
        auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
        this->m_pLrSize = cocos2d::CCSize{ _w, _h };

        if (!this->initWithColor({ 0, 0, 0, 75 })) return false;
        this->m_pLayer = cocos2d::CCLayer::create();
        this->addChild(this->m_pLayer);

        auto bg = cocos2d::extension::CCScale9Sprite::create(_spr, { 0.0f, 0.0f, 80.0f, 80.0f });
        bg->setContentSize(this->m_pLrSize);
        bg->setPosition(winSize.width / 2, winSize.height / 2);
        this->m_pLayer->addChild(bg);

        this->m_pButtonMenu = cocos2d::CCMenu::create();
        this->m_pLayer->addChild(this->m_pButtonMenu);

        setup();

        auto closeSpr = cocos2d::CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png");
        closeSpr->setScale(.8f);

        auto closeBtn = gd::CCMenuItemSpriteExtra::create(
            closeSpr,
            this,
            (cocos2d::SEL_MenuHandler)&BrownAlertDelegate::onClose
        );
        closeBtn->setUserData(reinterpret_cast<void*>(this));

        this->m_pButtonMenu->addChild(closeBtn);

        closeBtn->setPosition(-_w / 2, _h / 2);

        this->setKeypadEnabled(true);
        this->setTouchEnabled(true);

        return true;
    }

    inline virtual void onClose(cocos2d::CCObject*) {
        this->setKeyboardEnabled(false);
        this->removeFromParentAndCleanup(true);
    }
};