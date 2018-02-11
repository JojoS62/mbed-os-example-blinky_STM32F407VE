/*
 * Scale.h
 *
 *  Created on: 18.11.2017
 *      Author: sn
 */

#ifndef LIB_CHART_SCALE_H_
#define LIB_CHART_SCALE_H_

#include "GfxItem.h"

class YScale  : public GfxItem {
public:
	YScale(GfxItem* parent, int offsetLeft, float minValue, float maxValue, uint16_t color);

	virtual void draw();

//private:
	float	_minValue;
	float	_maxValue;
};



#endif /* LIB_CHART_SCALE_H_ */
