// Order.h
#ifndef ORDER_H
#define ORDER_H

#include "Plant.h"
#include "Memento.h"
#include <string>
#include <vector>
using namespace std;

class Memento;

/*!
 * @class Order
 *
 * @brief Represents a customer's in-progress purchase.
 */
class Order
{
private:
    std::string orderId;
    std::vector<Plant *> plants;
    double totalCost;
    std::vector<Memento *> mementos;     // undo stack
    std::vector<Memento *> redoMementos; // redo stack

public:
    Order();
    ~Order();

    void addPlant(Plant *plant);
    std::string getDetails() const;
    void updateCost();

    Memento *createMemento();
    void restoreMemento(Memento *memento);

    std::vector<Memento *> &getMementos();
    std::vector<Memento *> &getRedoMementos();

    void undoLastAddition();
    void redoLastStep();

    std::vector<Plant *> getPlants() const;
    Plant *getLastPlant() const;
    void replaceLastPlant(Plant *newPlant);

    bool isEmpty() const { return plants.empty(); }
    void printOrder() const;
};

#endif // ORDER_H