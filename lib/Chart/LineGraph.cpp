/*
 MIT License

Copyright (c) 2018 JojoS

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*
 */

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
