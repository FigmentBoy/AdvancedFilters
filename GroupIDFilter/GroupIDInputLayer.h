#pragma once
#include "BrownAlertDelegate.hpp"
#include "CustomTextInputNode.h"

class GroupIDInputLayer : public BrownAlertDelegate {
protected:
	CustomTextInputNode* m_groupInput;
	CustomTextInputNode* m_scaleInput;
	CustomTextInputNode* m_zOrder;
	CustomTextInputNode* m_col1Input;
	CustomTextInputNode* m_col2Input;

	gd::CCMenuItemToggler* m_lowDetail;
	gd::CCMenuItemToggler* m_highDetail;

	std::vector<gd::CCMenuItemToggler*> m_zLayerToggles;

    void setup();
	virtual void onClose(cocos2d::CCObject*) override;
	virtual void keyBackClicked() override;

	void on_lowDetail(cocos2d::CCObject*);
	void on_highDetail(cocos2d::CCObject*);

	void on_zLayer(cocos2d::CCObject*);

	void saveSettings();
public:
	inline void onOpen(cocos2d::CCObject* sender) {
		GroupIDInputLayer::create()->show();
	}

	inline void addZLayerButton(gd::CCMenuItemToggler* input) {
		m_zLayerToggles.push_back(input);
	}

	inline void clearZLayers() {
		for (int i = 0; i < m_zLayerToggles.size(); i++) {
			 m_zLayerToggles[i]->toggle(false);
		}
	}

	inline int getZLayer(gd::CCMenuItemToggler* input) {
		auto it = std::find(m_zLayerToggles.begin(), m_zLayerToggles.end(), input);
		int index = it - m_zLayerToggles.begin();
		return (index * 2) - 3;
	}

    static GroupIDInputLayer* create();
};