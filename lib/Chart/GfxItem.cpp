/*
 * GfxItem.cpp
 *
 *  Created on: 19.11.2017
 *      Author: sn
 */

#include "GfxItem.h"

GfxItem::GfxItem(Adafruit_GFX &gfx, int x, int y, int w, int h, uint16_t color) :
	_parent(0),
	_gfx(gfx),
	_x(x),
	_y(y),
	_w(w),
	_h(h),
	_color(color) {
}

GfxItem::GfxItem(GfxItem *parent, int x, int y, int w, int h, uint16_t color) :
	_parent(parent),
	_gfx(parent->_gfx),
	_x(x),
	_y(y),
	_w(w),
	_h(h),
	_color(color) {
}


