#include "Observer.h"
#include <algorithm>
#include <iostream>
using namespace std;

Observer::Observer() {}
Observer::~Observer() {}

void Observer::update(Subject& subject) {
    cout << "Observer received update from subject." << endl;
}


Subject::Subject() {}

Subject::~Subject() {}

void Subject::attach(Observer* observer) {
    if (observer) {
        observers.push_back(observer);
    }
}

void Subject::detach(Observer* observer) {
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify() {
    for (Observer* observer : observers) {
        if (observer) observer->update(*this);
    }
}
