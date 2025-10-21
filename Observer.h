#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
using namespace std;

class Subject;
class Observer {
    public:
        Observer();
        virtual ~Observer();
        virtual void update(Subject& subject);
};

class Subject {
    private:
        vector<Observer*> observers;
    public:
        Subject();
        virtual ~Subject();
        void attach(Observer* observer);
        void detach(Observer* observer);
        void notify();
};


#endif //OBSERVER_H
