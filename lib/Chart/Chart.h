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
	PlotArea* addPlotArea(int offsetLeft, int offsetRight, int offsetTop, int offsetBottom, uint16_t color);

private:
	//vector<PlotArea*> plotAreas;
	PlotArea* plotAreas;
};


#endif /* SRC_CHART_H_ */
