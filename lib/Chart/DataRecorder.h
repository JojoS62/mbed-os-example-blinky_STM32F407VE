/*
 * DataRecorder.h
 *
 *  Created on: 6 Jan 2018
 *      Author: sn
 */

#ifndef LIB_CHART_DATARECORDER_H_
#define LIB_CHART_DATARECORDER_H_

#include "DataBuffer.h"

class DataRecorder {
public:
	enum RecordMode {noWrap, wrap, wrapNoClear, compress, scroll};

	DataRecorder(uint32_t numPoints, RecordMode recordMode);

	void addYValue(float value);
	void reset(float xMin, float xMax);
	DataBuffer* dataBuffer;

private:
	RecordMode _recordMode;
};



#endif /* LIB_CHART_DATARECORDER_H_ */
