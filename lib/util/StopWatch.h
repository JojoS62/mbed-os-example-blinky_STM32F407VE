/*
 * StopWatch.h
 *
 *  Created on: 10.02.2018
 *      Author: sn
 */

#ifndef LIB_UTIL_STOPWATCH_H_
#define LIB_UTIL_STOPWATCH_H_

#include "mbed.h"

class StopWatch
{
public:
    StopWatch(int nLapTimes=8);
    void start(bool reset=true);
    void stop();
    us_timestamp_t stopLapTime();
    us_timestamp_t getLapTime(int n);
    int64_t getLapTimeDiff(int n);

private:
    Timer timer;
    us_timestamp_t *lapTimes;
    int maxLapTimes;
    int actLapTime;
    int offset;
};

#endif /* LIB_UTIL_STOPWATCH_H_ */
