#ifndef MEMENTO_H
#define MEMENTO_H

#include "Plant.h"
#include <vector>

class Memento {
    private:
        vector<Plant*> savedPlants;
        double savedCost;
    public:
        Memento();
        ~Memento();
};



#endif //MEMENTO_H
