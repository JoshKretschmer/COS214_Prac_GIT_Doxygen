#ifndef SUBJECT_H
#define SUBJECT_H

#include "libraries.h"
#include "Observer.h"

class Observer;

class Subject
{
private:
    vector<Observer *> observers;

public:
    Subject();
    ~Subject();
    void attach(Observer *observer);
    void detach(Observer *observer);
    void notify();
};

#endif