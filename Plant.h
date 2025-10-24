#ifndef PLANT_H
#define PLANT_H

#include "libraries.h"
#include "PlantCare.h"
#include "PlantState.h"

class PlantState;

class Plant
{
    protected:
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
        //void add(InventoryComponent* comp);
        //void remove(InventoryComponent* comp);
        vector<Plant*> getPlants();
        void movePlant(Plant* plant,string newState);
        int getHealth() { return health; };
        string getID() { return id; };
        string getType() { return type; };
        void incrementHealth(int num);
        string getState();
        virtual Plant* clone()=0;
};



class Succulent : public Plant
{
    public:
        Succulent();
        string virtual getDetails()=0;
        double virtual getCost()=0;
};

class PeanutCactus : public Succulent
{
    public:
        PeanutCactus();
        string getDetails();
        double getCost();
        virtual Plant* clone() override;
};

class HouseLeek : public Succulent
{
    public:
        HouseLeek();
        string getDetails();
        double getCost();
        virtual Plant* clone() override;
};

class Flower : public Plant
{
    public:
        Flower();
        string virtual getDetails()=0;
        double virtual getCost()=0;
};

class Orchid : public Flower
{
    public:
        Orchid();
        string getDetails();
        double getCost();
        virtual Plant* clone() override;
};

class Marigold : public Flower
{
    public:
        Marigold();
        string getDetails();
        double getCost();
        virtual Plant* clone() override;
};

class Shrub : public Plant
{
    public:
        Shrub();
        string virtual getDetails()=0;
        double virtual getCost()=0;
};

class BeeBlossom : public Shrub
{
    public:
        BeeBlossom();
        string getDetails();
        double getCost();
        virtual Plant* clone() override;
};


class HoneySuckle : public Shrub
{
    public:
        HoneySuckle();
        string getDetails();
        double getCost();
        virtual Plant* clone() override;
};

#endif //PLANT_H