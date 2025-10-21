#ifndef PLANT_H
#define PLANT_H

#include "PlantCare.h"
#include <string>
#include <vector>

#include "Observer.h"
using namespace std;

class PlantState;
class PlantCare;
class InventoryComponent;

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
        Plant(const Plant& other);
        virtual ~Plant();
        string virtual getDetails()=0;
        double virtual getCost()=0;
        void changeState(PlantState* newState);
        bool needsCare();
        void add(InventoryComponent* comp);
        void remove(InventoryComponent* comp);
        vector<Plant*> getPlants();
        void movePlant(Plant* plant,string newState);
        virtual Plant* clone() const = 0; //for deep copies to avoid seg faults

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
        virtual Plant* clone() const;
        string getDetails();
        double getCost();
};

class HouseLeek : public Succulent {
    public:
        HouseLeek();
        virtual Plant* clone() const;
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
        virtual Plant* clone() const;
        string getDetails();
        double getCost();
};

class Marigold : public Flower {
    public:
        Marigold();
        virtual Plant* clone() const;
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
        virtual Plant* clone() const;
        string getDetails();
        double getCost();
};

class HoneySuckle : public Shrub {
    public:
        HoneySuckle();
        virtual Plant* clone() const;
        string getDetails();
        double getCost();
};

#include "PlantState.h"
#endif //PLANT_H
