#include "Observer.h"
#include <iostream>
using namespace std;

/**
 * @brief Default constructor for Observer.
 */
Observer::Observer() {
}

/**
 * @brief Destructor for Observer.
 */
Observer::~Observer() {
}

/**
 * @brief Called when a Subject notifies its observers.
 * @param subject The Subject that triggered the notification.
 */
void Observer::update(Subject& subject) {
    cout << "Observer notified of a change in subject." << endl;
}

//##################################################

/**
 * @brief Default constructor for Subject.
 */
Subject::Subject() {
}

/**
 * @brief Destructor for Subject. Clears observer list.
 */
Subject::~Subject() {
    observers.clear();
}

/**
 * @brief Attach an observer to the subject.
 * @param observer Pointer to observer to add.
 */
void Subject::attach(Observer *observer) {
    observers.push_back(observer);
}

/**
 * @brief Detach an observer from the subject.
 * @param observer Pointer to observer to remove.
 */
void Subject::detach(Observer *observer) {
    // Implementation commented out; can be implemented as needed
    // observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

/**
 * @brief Notify all attached observers of a change.
 */
void Subject::notify() {
    for (auto observer : observers) {
        observer->update(*this);
    }
}
