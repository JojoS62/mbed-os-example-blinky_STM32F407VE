/*
 * Grid.h
 *
 *  Created on: 18.11.2017
 *      Author: sn
 */

#ifndef LIB_CHART_GRID_H_
#define LIB_CHART_GRID_H_

#include "GfxItem.h"

enum GridOrientation {vertical, horizontal};

class Grid : public GfxItem {
public:
	Grid(GfxItem* parent, GridOrientation orientation, int division, uint16_t color);

	void draw();

private:
	GridOrientation _orientation;
	int _division;
};


#endif /* LIB_CHART_GRID_H_ */
