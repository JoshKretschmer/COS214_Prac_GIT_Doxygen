#ifndef LIBRARIES_H
#define LIBRARIES_H

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <iomanip>
#include <list>
#include <fstream>
#include <cmath>
#include <thread>
#include <chrono>
#include <queue>
#include <algorithm>

using namespace std;

inline void delay() {
    // Convert seconds to milliseconds and sleep
    this_thread::sleep_for(chrono::milliseconds(static_cast<int>(1 * 1000)));
}

inline void delay(double time) {
    // Convert seconds to milliseconds and sleep
    this_thread::sleep_for(chrono::milliseconds(static_cast<int>(time * 1000)));
}

inline void clearTerminal() {
    cout << "\033[2J\033[1;1H";  // Clear screen and move cursor to top-left
}

#endif // LIBRARIES_H