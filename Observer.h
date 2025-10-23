#ifndef OBSERVER_H
#define OBSERVER_H

#include "libraries.h"

class Subject;

class Observer {
    public:
        Observer();
        ~Observer();
        virtual void update(Subject& subject);
};

class Subject {
    private:
        vector<Observer*> observers;
    public:
        Subject();
        ~Subject();
        void attach(Observer* observer);
        void detach(Observer* observer);
        void notify();
};


#endif //OBSERVER_H