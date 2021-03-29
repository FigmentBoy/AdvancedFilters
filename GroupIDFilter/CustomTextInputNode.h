#pragma once
#include <gd.h>
#include "Editor.h";

class CustomTextInputNode : public gd::CCTextInputNode {

public:
	std::string getString() {
		return m_pTextField->getString();
	}

	void setString(std::string a) {
		m_pTextField->setString(a.c_str());
	}
};