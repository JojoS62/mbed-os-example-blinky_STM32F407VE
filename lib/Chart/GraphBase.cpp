/*
 * GraphBase.cpp
 *
 *  Created on: 4 Jan 2018
 *      Author: sn
 */

#include "GraphBase.h"

GraphBase::GraphBase(GfxItem* parent, DataBuffer* data, YScale* yScale, uint16_t color) :
	GfxItem(parent, parent->x0(), parent->y0(), parent->width(), parent->height(), color),
	_data(data),
	_yScale(yScale) {
}
