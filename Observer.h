#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
using namespace std;

class Subject;

/**
 * @file Observer.h
 * @brief Implements the Observer design pattern for plant monitoring.
 *
 * Observers are notified of changes in Subjects (plants) and can react accordingly.
 * @author Palesa
 * @date 2025-10-22
 */

/**
 * @class Observer
 * @brief Abstract base class representing an observer.
 *
 * Observers are notified by Subjects when an event occurs.
 */
class Observer {
public:
    /** @brief Default constructor */
    Observer();

    /** @brief Virtual destructor */
    virtual ~Observer();

    /**
     * @brief Called by Subject when its state changes.
     * @param subject Reference to the Subject notifying the observer.
     */
    virtual void update(Subject& subject);
};

/**
 * @class Subject
 * @brief Base class for objects that are observed by Observer instances.
 *
 * Subjects maintain a list of observers and notify them of any changes.
 */
class Subject {
private:
    vector<Observer*> observers; /**< List of attached observers */

public:
    /** @brief Default constructor */
    Subject();

    /** @brief Virtual destructor */
    virtual ~Subject();

    /**
     * @brief Attaches an observer to the subject.
     * @param observer Pointer to observer to attach.
     */
    void attach(Observer* observer);

    /**
     * @brief Detaches an observer from the subject.
     * @param observer Pointer to observer to detach.
     */
    void detach(Observer* observer);

    /**
     * @brief Notifies all attached observers of a change.
     */
    void notify();
};

#endif // OBSERVER_H
