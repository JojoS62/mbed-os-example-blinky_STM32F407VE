/*
 * Grid.cpp
 *
 *  Created on: 18.11.2017
 *      Author: sn
 */

#include "Grid.h"

Grid::Grid(GfxItem* parent, GridOrientation orientation, int division, uint16_t color) :
	GfxItem(parent, parent->x0(), parent->y0(), parent->width(), parent->height(), color),
	_orientation(orientation),
	_division(division) {
}

void Grid::draw() {
	if (_orientation == vertical) {
		int x = _x;
		while (x < (_x + _w  - 1)) {
			_gfx.drawFastVLine(x, _y, _h, _color);
			x += _division;
		}
	} else
		if (_orientation == horizontal) {
			int y = _y + _h - 1;
			while (y > (_y  - 1)) {
				_gfx.drawFastHLine(_x, y, _w, _color);
				y -= _division;
			}
		};
}
