#ifndef MEMENTO_H
#define MEMENTO_H

#include "Plant.h"
#include <vector>

class Memento {
    private:
        vector<Plant*> savedPlants;
        double savedCost;
        
    public:
        Memento(const std::vector<Plant*>& plants, double cost);
        ~Memento();
        const vector<Plant*>& getSavedPlants() const;
        double getSavedCost() const;
        vector<Plant*> getMementos() const { return savedPlants; }
        vector<Memento*> mementos;
        
};



#endif //MEMENTO_H