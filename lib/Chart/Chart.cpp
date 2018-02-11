/*

 * CHART.cpp
 *
 *  Created on: 16.11.2017
 *      Author: sn
 */

#include <Chart.h>


Chart::Chart(Adafruit_GFX& gfx, int x, int y, int w, int h, uint16_t color) :
	GfxItem(gfx, x, y, w, h, color) {
	plotAreas = 0;
}

void Chart::draw() {
	_gfx.fillRect(_x, _y, _w, _h, _color);
	if (plotAreas)
		plotAreas->draw();
}

PlotArea* Chart::addPlotArea(int offsetLeft, int offsetRight, int offsetTop, int offsetBottom, uint16_t color) {
	PlotArea* p = new PlotArea(this, offsetLeft, offsetRight, offsetTop, offsetBottom, color);
	plotAreas = p;
	return p;
}
