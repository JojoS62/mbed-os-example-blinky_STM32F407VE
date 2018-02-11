/*

 * GraphBase.h
 *
 *  Created on: 4 Jan 2018
 *      Author: sn
 */

#ifndef LIB_CHART_GRAPHBASE_H_
#define LIB_CHART_GRAPHBASE_H_

#include "GfxItem.h"
#include "DataBuffer.h"
#include "Scale.h"

class GraphBase : public GfxItem {
public:
	GraphBase(GfxItem *parent, DataBuffer *data, YScale *yScale, uint16_t color);

protected:
	DataBuffer *_data;
	YScale *_yScale;
};





#endif /* LIB_CHART_GRAPHBASE_H_ */
