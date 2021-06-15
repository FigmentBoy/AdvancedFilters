#pragma once
#include "gd.h"

class GameObject : public gd::GameObject {
public:
	float getScale() {
		return m_fScale;
	}

	bool isHighDetail() {
		return m_bHighDetail;
	}

	int getZLayer() {
		return m_nZLayer;
	}
};