//#include "TouchDetector.h"
//#include "Editor.h"
//// Unused
//void TouchDetector::ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {
//	/*if (Editor::isIn == 0) {
//			Editor::isIn += 1;
//			return;
//		}
//		Editor::isIn = 0;*/
//
//	std::string input = Editor::input->getString();
//	CCLayer* parent = (CCLayer*)Editor::input->getParent();
//
//	Editor::input->removeFromParentAndCleanup(true);
//
//	Editor::input = (CustomTextInputNode*)gd::CCTextInputNode::create("id", parent, "bigFont.fnt", 30.f, 25.f);
//	Editor::input->setAllowedChars("1234567890");
//	Editor::input->setLabelPlaceholderColor({ 200, 200, 200 });
//	Editor::input->setMaxLabelLength(3);
//	Editor::input->setPosition(65, 200);
//	Editor::input->setMaxLabelScale(3.f / 5.f);
//	Editor::input->setString(input);
//
//	parent->addChild(Editor::input);
//	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
//}
//
//bool InputTouch::ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {
//		Editor::det->registerWithTouchDispatcher();
//		Editor::isIn = 0;
//
//		return true;
//}
//
//InputTouch* InputTouch::create(const char* a) {
//	InputTouch* pRet = new InputTouch();
//
//	if (pRet && pRet->initWithFile(a)) {
//		pRet->autorelease();
//		return pRet;
//	}
//	else {
//		CC_SAFE_DELETE(pRet);
//		return nullptr;
//	}
//}