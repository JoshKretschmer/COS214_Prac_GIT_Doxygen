#include "SimulationTime.h"

chrono::steady_clock::time_point SimulationTime::startTime;
bool SimulationTime::initialized = false;

/*!
 * @brief Basic construction function
 */
void SimulationTime::initialize()
{
    if (!initialized) {
        startTime = chrono::steady_clock::now();
        initialized = true;
    }
}

/*!
 *
 * @return Amount of time for which the clock has been running
 */
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

/*!
 * @brief Basic time reset function
 */
void SimulationTime::reset()
{
    startTime = chrono::steady_clock::now();
}