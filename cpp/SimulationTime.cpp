#include "SimulationTime.h"

chrono::steady_clock::time_point SimulationTime::startTime;
bool SimulationTime::initialized = false;


void SimulationTime::initialize()
{
    if (!initialized) {
        startTime = chrono::steady_clock::now();
        initialized = true;
    }
}

int SimulationTime::getTime()
{
    if (!initialized)
    {
        initialize();
    }
    
    auto currentTime = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
    return static_cast<int>(duration.count());
}

void SimulationTime::reset()
{
    startTime = chrono::steady_clock::now();
}