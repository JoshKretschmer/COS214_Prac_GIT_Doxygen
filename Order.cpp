// Order.cpp
#include "Order.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*!
 * @brief Constructs an empty Order.
 */
Order::Order()
{
    totalCost = 0.0;
    static int nextId = 1;
    orderId = "ORD" + to_string(nextId++);
}

/*!
 * @brief Destroys the Order, freeing all plants and mementos.
 */
Order::~Order()
{
    for (auto *p : plants)
        delete p;
    for (auto *m : mementos)
        delete m;
    for (auto *m : redoMementos)
        delete m;
}

/*!
 * @brief Adds a plant to the order, saving the previous state for undo.
 *
 * @param plant Plant to add.
 */
void Order::addPlant(Plant *plant)
{
    mementos.push_back(createMemento()); // snapshot before change
    plants.push_back(plant);
    updateCost();
}

/*!
 * @brief Returns a string with order details.
 *
 * @return Formatted order description.
 */
string Order::getDetails() const
{
    string details = "Order ID: " + orderId + "\nPlants:\n";
    for (auto *p : plants)
    {
        details += "- " + p->getDetails() + "\n";
    }
    details += "Total cost: " + to_string(totalCost) + "\n";
    return details;
}

/*!
 * @brief Recalculates the total cost from all plants.
 */
void Order::updateCost()
{
    totalCost = 0.0;
    for (auto *p : plants)
    {
        totalCost += p->getCost();
    }
}

/*!
 * @brief Creates a new Memento capturing the current state.
 *
 * @return New Memento (caller must delete).
 */
Memento *Order::createMemento()
{
    return new Memento(plants, totalCost);
}

/*!
 * @brief Restores the order to the state stored in the given Memento.
 *
 * @param memento Memento containing the target state.
 */
void Order::restoreMemento(Memento *memento)
{
    if (!memento)
        return;

    // delete current plants
    for (auto *p : plants)
        delete p;
    plants.clear();

    // clone saved plants
    for (auto *saved : memento->getSavedPlants())
    {
        plants.push_back(saved->clone());
    }

    totalCost = memento->getSavedCost();
}

/*!
 * @return Reference to the undo stack.
 */
vector<Memento *> &Order::getMementos()
{
    return mementos;
}

/*!
 * @return Reference to the redo stack.
 */
vector<Memento *> &Order::getRedoMementos()
{
    return redoMementos;
}

/*!
 * @brief Undoes the last plant addition.
 */
void Order::undoLastAddition()
{
    if (mementos.empty())
        return;

    Memento *last = mementos.back();
    mementos.pop_back();

    redoMementos.push_back(createMemento()); // save for redo
    restoreMemento(last);
    delete last;
}

/*!
 * @brief Redoes the previously undone action.
 */
void Order::redoLastStep()
{
    if (redoMementos.empty())
        return;

    Memento *next = redoMementos.back();
    redoMementos.pop_back();

    mementos.push_back(createMemento()); // save for undo
    restoreMemento(next);
    delete next;
}

/*!
 * @return Copy of the current plants vector.
 */
vector<Plant *> Order::getPlants() const
{
    return plants;
}

/*!
 * @return Pointer to the last added plant, or nullptr if empty.
 */
Plant *Order::getLastPlant() const
{
    return plants.empty() ? nullptr : plants.back();
}

/*!
 * @brief Replaces the last plant with a new one (used for decoration).
 *
 * @param newPlant New plant to insert.
 */
void Order::replaceLastPlant(Plant *newPlant)
{
    if (plants.empty())
        return;
    delete plants.back();
    plants.back() = newPlant;
    updateCost();
}

/*!
 * @brief Prints the order in a user-friendly format.
 */
void Order::printOrder() const
{
    cout << fixed << setprecision(2);
    cout << getDetails();
}