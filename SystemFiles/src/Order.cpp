#include "../inc/Order.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*!
 * @brief Constructs an empty Order.
 */
Order::Order()
{
    totalCost = 0.0;
    static int nextId = 1;
    orderId = "ORD" + std::to_string(nextId++);
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
    mementos.push_back(createMemento());
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
    details += "Total cost: " + std::to_string(totalCost) + "\n";
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
    Memento *m = new Memento(plants, totalCost);
    return m;
}

/*!
 * @brief Restores the order to the state stored in the given Memento.
 *
 * @param memento Memento containing the target state.
 */
void Order::restoreMemento(Memento *memento)
{
    if (!memento)
    {
        std::cout << "Order::restoreMemento() - no memento, nothing done\n";
        return;
    }

    for (auto *p : plants)
        delete p;
    plants.clear();

    for (auto *saved : memento->getSavedPlants())
    {
        if (saved)
        {
            Plant *cloned = saved->clone();
            if (cloned)
            {
                plants.push_back(cloned);
            }
            else
            {
                std::cerr << "Order::restoreMemento() - failed to clone plant\n";
            }
        }
        else
        {
            std::cerr << "Order::restoreMemento() - null plant in memento, skipping\n";
        }
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
    {
        return;
    }

    Memento *last = mementos.back();
    mementos.pop_back();

    redoMementos.push_back(createMemento());
    restoreMemento(last);
    delete last;
}

/*!
 * @brief Redoes the previously undone action.
 */
void Order::redoLastStep()
{
    if (redoMementos.empty())
    {
       // std::cout << "Order::redoLastStep() - no redo mementos, nothing done\n";
        return;
    }

    Memento *next = redoMementos.back();
    redoMementos.pop_back();

    mementos.push_back(createMemento());
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
    std::cout << "Calling Order::getLastPlant() - size=" << plants.size() << "\n";
    Plant *result = plants.empty() ? nullptr : plants.back();
    std::cout << "Order::getLastPlant() returning "
              << (result ? result->getDetails() : "null") << "\n";
    return result;
}

/*!
 * @brief Replaces the last plant with a new one (used for decoration).
 *
 * @param newPlant New plant to insert.
 */
void Order::replaceLastPlant(Plant *newPlant)
{
    std::cout << "Calling Order::replaceLastPlant(newPlant="
              << (newPlant ? newPlant->getDetails() : "null") << ")\n";

    if (plants.empty())
    {
        std::cout << "Order::replaceLastPlant() - empty plants, nothing done\n";
        return;
    }

    delete plants.back();
    plants.back() = newPlant;
    updateCost();

    std::cout << "Order::replaceLastPlant() completed - new totalCost=" << totalCost << "\n";
}

/*!
 * @brief Prints the order in a user-friendly format.
 */
void Order::printOrder() const
{
    cout << fixed << setprecision(2);
    cout << getDetails();
}

/*!
 * @brief Returns the total cost of the order.
 * @return Total cost of all plants in the order.
 */
double Order::getTotalCost() const
{
    return totalCost;
}