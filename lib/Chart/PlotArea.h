/*
 * PlotArea.h
 *
 *  Created on: 19.11.2017
 *      Author: sn
 */

#ifndef LIB_CHART_PLOTAREA_H_
#define LIB_CHART_PLOTAREA_H_

#include "GfxItem.h"
#include "Grid.h"
#include "Scale.h"

class PlotArea : public GfxItem {
public:
	PlotArea(GfxItem* parent, int offsetLeft, int offsetRight, int offsetTop, int offsetBottom, uint16_t color);

	Grid* addGridVertical(int division, uint16_t color);
	Grid* addGridHorizontal(int division, uint16_t color);
	YScale* addYScale(int offset, float minValue, float maxValue, uint16_t color);


	virtual void draw();

private:
	Grid* _gridVertical;
	Grid* _gridHorizontal;
	YScale* _yScale;
};



#endif /* LIB_CHART_PLOTAREA_H_ */
