#ifndef TIME_H
#define TIME_H

#include "libraries.h"

class SimulationTime
{
private:
    static chrono::steady_clock::time_point startTime;
    static bool initialized;

public:
    static void initialize();
    static int getTime();
    static void reset();
};

#endif