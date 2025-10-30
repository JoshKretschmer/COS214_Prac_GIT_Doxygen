#ifndef ORDER_H
#define ORDER_H

/*!
 * @headerfile Order.h
 */
#include "Plant.h"
#include "Memento.h"
#include <string>
#include <vector>
using namespace std;

class Memento;

/*!
 * @class Order
 *
 * @brief Contains information of a in progress purchase being made by a Customer object
 */
class Order {
private:
    string orderId;
    vector<Plant*> plants;
    double totalCost;
    vector<Memento*> mementos;
public:
    Order();
    ~Order();
    void addPlant(Plant* plant);
    string getDetails();
    void updateCost();
    Memento* createMemento();
    void restoreMemento(Memento* memento);
    vector<Memento*>& getMementos();
    void undoLastAddition();
};

#endif //ORDER_H
