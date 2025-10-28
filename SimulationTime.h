#ifndef TIME_H
#define TIME_H

/*!
 * @headerfile SimulationTime.h
 */
#include "libraries.h"

/*!
 * @class SimulationTime
 *
 * @brief Used to organize and time the various repeated activities in the system
 */
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