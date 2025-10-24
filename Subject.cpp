#include "Subject.h"

Subject::Subject()
{

}

Subject::~Subject()
{

}

void Subject::attach(Observer* observer)
{
    if (observer) {
        observers.push_back(observer);
    }
}

void Subject::detach(Observer* observer)
{
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify()
{
    for (Observer* observer : observers) {
        if (observer) observer->update(this);
    }
}