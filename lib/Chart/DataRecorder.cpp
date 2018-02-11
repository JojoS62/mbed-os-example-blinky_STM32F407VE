
/*
 * DataRecorder.cpp
 *
 *  Created on: 6 Jan 2018
 *      Author: sn
 */

#include "mbed.h"
#include "DataRecorder.h"

DataRecorder::DataRecorder(uint32_t numPoints, RecordMode recordMode) :
	_recordMode(recordMode) {
	dataBuffer = new DataBuffer(numPoints);
}


void DataRecorder::addYValue(float value) {
	if (dataBuffer->isFull())
		dataBuffer->reset();
	dataBuffer->addPoint(value);
}


void DataRecorder::reset(float xMin, float xMax) {
}


