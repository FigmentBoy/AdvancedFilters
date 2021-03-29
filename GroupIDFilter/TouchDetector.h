#pragma once
#include <gd.h>
#include <cocos2d.h>
#include <cocos-ext.h>
// Unused

class TouchDetector : public gd::FLAlertLayer {
protected:
	virtual void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) override;
};

class InputTouch : public cocos2d::extension::CCScale9Sprite, public cocos2d::CCTargetedTouchDelegate {
protected:
	virtual bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) override;
public:
	static InputTouch* create(const char* a);
};