#ifndef ORDER_H
#define ORDER_H

#include "Plant.h"
#include "Memento.h"
#include <string>
#include <vector>
using namespace std;

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
        Memento* createMemento();
        void restoreMemento(Memento* memento);
        string getDetails();
        void updateCost();
};



#endif //ORDER_H
