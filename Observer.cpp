#include "Observer.h"
#include <iostream>
using namespace std;


Observer::Observer() {

}

Observer::~Observer() {
    
}

void Observer::update(Subject& subject) {
    cout << "Observer notified of a change in subject." << endl;
}

//##################################################

Subject::Subject() {

}

Subject::~Subject() {
    observers.clear();
}

void Subject::attach(Observer *observer) {
    observers.push_back(observer);
}

void Subject::detach(Observer *observer) {
    //observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify() {
    for (auto observer : observers) {
        observer->update(*this);
    }
}


