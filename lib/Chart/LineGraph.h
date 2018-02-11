/*
 * LineChart.h
 *
 *  Created on: 4 Jan 2018
 *      Author: sn
 */

#ifndef LIB_CHART_LINECHART_H_
#define LIB_CHART_LINECHART_H_

#include "GraphBase.h"

class LineGraph : public GraphBase {
public:
	LineGraph(GfxItem *parent, DataBuffer *data, YScale *yScale, uint16_t color);

	void draw();

private:
	int _stopIndex;
};


#endif /* LIB_CHART_LINEGRAPH_H_ */
