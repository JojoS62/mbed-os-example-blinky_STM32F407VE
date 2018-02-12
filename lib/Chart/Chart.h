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

 * CHART.h
 *
 *  Created on: 16.11.2017
 *      Author: sn
 */

#ifndef SRC_CHART_H_
#define SRC_CHART_H_

#include "GfxItem.h"
#include "PlotArea.h"
#include "Grid.h"
#include "Scale.h"
#include "LineGraph.h"
#include "DataBuffer.h"

class Chart : public GfxItem {
public:
	Chart(Adafruit_GFX &gfx, int x, int y, int w, int h, uint16_t color);

	void draw();
	PlotArea& addPlotArea(int offsetLeft, int offsetRight, int offsetTop, int offsetBottom, uint16_t color);

private:
	//vector<PlotArea*> plotAreas;
	PlotArea* plotAreas;
};


#endif /* SRC_CHART_H_ */
