/*
 * PlotArea.cpp
 *
 *  Created on: 19.11.2017
 *      Author: sn
 */

#include "PlotArea.h"

PlotArea::PlotArea(GfxItem* parent, int offsetLeft, int offsetRight, int offsetTop, int offsetBottom, uint16_t color) :
	GfxItem(parent,
			parent->x0() + offsetLeft,
			parent->y0() + offsetTop,
			parent->width() - offsetLeft - offsetRight,
			parent->height() - offsetTop - offsetBottom,
			color) {
	_gridVertical = 0;
	_gridHorizontal = 0;
}

void PlotArea::draw() {
	_gfx.fillRect(_x, _y, _w, _h, _color);

	if (_gridVertical)
		_gridVertical->draw();

	if (_gridHorizontal)
		_gridHorizontal->draw();

	if (_yScale)
		_yScale->draw();
}

Grid* PlotArea::addGridVertical(int division, uint16_t color) {
	_gridVertical = new Grid(this, vertical, division, color);
	return _gridVertical;
}

Grid* PlotArea::addGridHorizontal(int division, uint16_t color) {
	_gridHorizontal = new Grid(this, horizontal, division, color);
	return _gridHorizontal;
}

YScale* PlotArea::addYScale(int offset, float minValue, float maxValue,
		uint16_t color) {
	_yScale = new YScale(this, offset, minValue, maxValue, color);
	return _yScale;
}
