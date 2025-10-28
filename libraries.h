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
#include <string_view>
using namespace std;


const string ACTION_STOREPLANT = "STOREPLANT";



inline void delay()
{
    // Convert seconds to milliseconds and sleep
    this_thread::sleep_for(chrono::milliseconds(static_cast<int>(1 * 1000)));
}

inline void delay(double time)
{
    // Convert seconds to milliseconds and sleep
    this_thread::sleep_for(chrono::milliseconds(static_cast<int>(time * 1000)));
}

inline void clearTerminal()
{
    // Clear screen and move cursor to top-left
    cout << "\033[2J\033[1;1H";
}

inline string toUpperCase(string _text)
{
    // makes all characters upper case
    int size = _text.size();
    for(int i=0; i<size; i++)
    {
        _text[i] = toupper(_text[i]);
    }

    return _text;
}

inline string errorMessage(string _text)
{
    return "\n\033[1;31m" + _text + "\033[0m\n";
}


#endif // LIBRARIES_H