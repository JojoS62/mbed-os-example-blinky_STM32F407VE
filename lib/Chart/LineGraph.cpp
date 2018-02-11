/*
 * LineChart.cpp
 *
 *  Created on: 4 Jan 2018
 *      Author: sn
 */

#include <LineGraph.h>

LineGraph::LineGraph(GfxItem *parent, DataBuffer* data, YScale* yScale, uint16_t color) :
	GraphBase(parent, data, yScale, color) {
	_stopIndex = data->stopIndex;
}

void LineGraph::draw() {
	float dY = (float)_h / (_yScale->_maxValue - _yScale->_minValue);

	if (_data->stopIndex < _stopIndex) {
		_parent->draw();
	};
	_stopIndex = _data->stopIndex;

	if (_data->stopIndex < 0)
		return;

	int x =_x;
	for (int i = 0; i<_data->stopIndex; i++) {
		int y = (_y + _h) - _data->data[i] * dY;
		_gfx.drawPixel(x, y, _color);
		x++;
	}
}
