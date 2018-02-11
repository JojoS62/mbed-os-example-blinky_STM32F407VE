/*
 * DataSeries.cpp
 *
 *  Created on: 18 Dec 2017
 *      Author: sn
 */

#include "DataBuffer.h"

DataBuffer::DataBuffer(int maxPoints, float fillValue) {
	data = new float[maxPoints];
	indexMax = maxPoints - 1;
	reset();
}

void DataBuffer::addPoint(float value) {
	if (stopIndex < indexMax) {
		stopIndex++;
		data[stopIndex] = value;
	}
}

void DataBuffer::reset() {
	startIndex = 0;
	stopIndex = -1;
}
