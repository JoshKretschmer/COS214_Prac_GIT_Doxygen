/*!
 *@headerfile Plant.h
 *
 *@brief Class hierarchy for main plant product
 *
 *Patterns: Factory, State, Strategy, Decorator, Observer, Composite
 */

#ifndef PLANT_H
#define PLANT_H

#include "PlantCare.h"
#include "PlantState.h"
#include "Inventory.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;


/*!
 * @class Plant
 *
 * @Brief Main Plant class
 *
 *  Parent class for different types of plants.
 *  Product in Factory Method, ConcreteComponent in Decorator, Context for State
 *
 */
class Plant{
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
        string getType() { return type; };
        void incrementHealth(int num);
        string getState();
        Plant* clone();
};
//##############################################
/*!
 * @class Succulent
 *
 * @brief public subclass of Plant, category of plants
 */
class Succulent : public Plant {
    public:
        Succulent();
        string virtual getDetails()=0;
        double virtual getCost()=0;
};

/*!
 * @class PeanutCactus
 *
 * @brief public subclass of Succulent, specific kind of plant
 */
class PeanutCactus : public Succulent {
    public:
        PeanutCactus();
        string getDetails();
        double getCost();
};

/*!
 * @class HouseLeek
 *
 * @brief public subclass of Succulent, specific kind of plant
 */
class HouseLeek : public Succulent {
    public:
        HouseLeek();
        string getDetails();
        double getCost();
};
//##############################################
/*!
 * @class Flower
 *
 * @brief public subclass of Plant, category of plants
 */
class Flower : public Plant {
    public:
        Flower();
        string virtual getDetails()=0;
        double virtual getCost()=0;
};

/*!
 * @class Orchid
 *
 * @brief public subclass of Flower, specific kind of plant
 */
class Orchid : public Flower {
    public:
        Orchid();
        string getDetails();
        double getCost();
};

/*!
 * @class Marigold
 *
 * @brief public subclass of Flower, specific kind of plant
 */
class Marigold : public Flower {
    public:
        Marigold();
        string getDetails();
        double getCost();
};
//##############################################
/*!
 * @class Shrub
 *
 * @brief public subclass of Plant, category of plants
 */
class Shrub : public Plant {
    public:
        Shrub();
        string virtual getDetails()=0;
        double virtual getCost()=0;
};

/*!
 * @class BeeBlossom
 *
 * @brief public subclass of Shrub, specific kind of plant
 */
class BeeBlossom : public Shrub {
    public:
        BeeBlossom();
        string getDetails();
        double getCost();
};

/*!
 * @class HoneySuckle
 *
 * @brief public subclass of Shrub, specific kind of plant
 */
class HoneySuckle : public Shrub {
    public:
        HoneySuckle();
        string getDetails();
        double getCost();
};

#endif //PLANT_H