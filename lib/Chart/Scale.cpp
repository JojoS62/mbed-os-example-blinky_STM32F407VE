/*
 * Scale.cpp
 *
 *  Created on: 18.11.2017
 *      Author: sn
 */


#include "Scale.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

YScale::YScale(GfxItem* parent, int offsetLeft, float minValue, float maxValue, uint16_t color) :
	GfxItem(parent, parent->x0(), parent->y0(), parent->width(), parent->height(), color),
	_minValue(minValue),
	_maxValue(maxValue)
{
}

void YScale::draw() {
//	int nScaleValues = 5;
//	int digits = 3;
	int16_t x1=_x, y1=_y;
	uint16_t w=0, h=0;
	char sValue[16];

	sprintf(sValue, "%4.0f", _maxValue);
	_gfx.getTextBounds(sValue, x1, y1, &x1, &y1, &w, &h);

	x1 -= 2;	// offset to grid
	x1 -= w;	// left pos to grid

	_gfx.setFont();	// TODO: set YScale font
	_gfx.setTextColor(_color);

	_gfx.setCursor(x1, y1);
	_gfx.println(sValue);

	_gfx.setCursor(x1, y1+_h-h);
	_gfx.printf("%4.0f", _minValue);
}
