#ifndef PLANT_H
#define PLANT_H

//test change

#include "PlantState.h"
#include "PlantCare.h"
#include "Inventory.h"
#include <string>
#include <vector>

#include "Observer.h"
using namespace std;

class Plant : public Subject{
    private:
        string id;
        string type;
        double price;
        PlantState* currState;
        PlantCare* careRegime;
        int health;
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
