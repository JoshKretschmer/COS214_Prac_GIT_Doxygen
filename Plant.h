#ifndef PLANT_H
#define PLANT_H

#include "PlantCare.h"
#include "PlantState.h"
#include "Inventory.h"
#include "Observer.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Plant : public Subject{
    protected:
        string id;//
        string type;//
        double price;//
        PlantState* currState;//
        PlantCare* careRegime;
        int health;//
    public:
        Plant();
        virtual ~Plant();
        string virtual getDetails()=0;
        double virtual getCost()=0;
        void changeState(PlantState* newState);
        bool needsCare();
        void add(InventoryComponent* comp);
        void remove(InventoryComponent* comp);
        vector<Plant*> getPlants();
        void movePlant(Plant* plant,string newState);
        int getHealth() { return health; };
        string getID() { return id; };

    //temp function for testing
    void setHealth(int hp) {
        this->health = hp;
        this->currState->handleCare(this);
    };
    string getState() { return currState->getStateName(); };
};
//##############################################
class Succulent : public Plant {
    public:
        Succulent();
        string virtual getDetails()=0;
        double virtual getCost()=0;
};

class PeanutCactus : public Succulent {
    public:
        PeanutCactus();
        string getDetails();
        double getCost();
};

class HouseLeek : public Succulent {
    public:
        HouseLeek();
        string getDetails();
        double getCost();
};
//##############################################
class Flower : public Plant {
    public:
        Flower();
        string virtual getDetails()=0;
        double virtual getCost()=0;
};

class Orchid : public Flower {
    public:
        Orchid();
        string getDetails();
        double getCost();
};

class Marigold : public Flower {
    public:
        Marigold();
        string getDetails();
        double getCost();
};
//##############################################
class Shrub : public Plant {
    public:
        Shrub();
        string virtual getDetails()=0;
        double virtual getCost()=0;
};

class BeeBlossom : public Shrub {
    public:
        BeeBlossom();
        string getDetails();
        double getCost();
};

class HoneySuckle : public Shrub {
    public:
        HoneySuckle();
        string getDetails();
        double getCost();
};

#endif //PLANT_H
