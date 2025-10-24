#ifndef TIME_H
#define TIME_H
#include <chrono>

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