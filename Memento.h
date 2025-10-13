#ifndef MEMENTO_H
#define MEMENTO_H

#include "Plant.h"
#include <vector>

class Memento {
    private:
        vector<Plants*> savedPlants;
        double savedCost;
    public:
        Memento();
        ~Memento();
};



#endif //MEMENTO_H
