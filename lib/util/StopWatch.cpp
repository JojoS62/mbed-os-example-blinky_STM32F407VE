/*
 * StopWatch.cpp
 *
 *  Created on: 10.02.2018
 *      Author: sn
 */

#include "StopWatch.h"

StopWatch::StopWatch (int nLapTimes)
{
    actLapTime = 0;
    maxLapTimes = nLapTimes;
    lapTimes = new us_timestamp_t[nLapTimes];

    // measure start-stop delay
    offset = 0;
    start();
    int64_t t1 = stopLapTime();
    int64_t t2 = stopLapTime();
    offset = t2 - t1;
}

void StopWatch::start (bool reset)
{
    if (reset) {
        timer.stop();
        timer.reset();
        actLapTime = 0;
    }
    timer.start();
}

void StopWatch::stop ()
{
    timer.stop();
}

us_timestamp_t StopWatch::stopLapTime ()
{
    us_timestamp_t lapTime = timer.read_high_resolution_us();
    if (actLapTime < maxLapTimes)
        lapTimes[actLapTime++] = lapTime;

    return lapTime;
}

us_timestamp_t StopWatch::getLapTime (int n)
{
    if ((n >= 0)  && (n < maxLapTimes))
        return lapTimes[n];
    else
        return 0;
}

int64_t StopWatch::getLapTimeDiff (int n)
{
    if ((n >= 0)  && (n < maxLapTimes-1)) {
        int64_t delta = lapTimes[n+1] - lapTimes[n] - offset;
        return (delta < 0) ? 0 : delta;  // catch -1 µs due to small readout diff
    }
    else
        return 0;
}
