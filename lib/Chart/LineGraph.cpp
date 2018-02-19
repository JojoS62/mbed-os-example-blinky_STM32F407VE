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
//#include <math.h>

LineGraph::LineGraph(GfxItem& parent, DataBuffer* data, YScale& yScale, uint16_t color) :
	GraphBase(parent, data, yScale, color) {
	_stopIndex = data->stopIndex;
	_dY = (float)_h / (yScale.maxValue() - yScale.minValue());
}

void LineGraph::draw() {
	// redraw if new data
	if (_data->stopIndex < _stopIndex) {
		_parent->draw();
	};

	// exit if no data
	if (_data->stopIndex < 0)
		return;

	// draw from last index to new datalength
	int x =_x + _stopIndex;
	for (int i = _stopIndex; i <= _data->stopIndex; i++) {
	    // get value and check clipping
	    float value = _data->data[i];
        value = fmax(value, _yScale->minValue());
        value = fmin(value, _yScale->maxValue());

		int y = (_y + _h) - value * _dY;
		_gfx.drawPixel(x, y, _color);
		x++;
	}

	_stopIndex = _data->stopIndex;

}
