/*
 * DataBuffer.h
 *
 *  Created on: 18 Dec 2017
 *      Author: sn
 */

#ifndef LIB_CHART_DATABUFFER_H_
#define LIB_CHART_DATABUFFER_H_

#include <string.h>

class DataBuffer {
public:
	DataBuffer(int maxPoints, float fillValue=0.0f);
	void reset();
	void addPoint(float value);
	bool isFull() {return stopIndex==indexMax;};

	float* data;
	int indexMax;
	int startIndex;
	int stopIndex;
	float X0;
	float deltaX;
};


#endif /* LIB_CHART_DATABUFFER_H_ */
