#ifndef PLANT_H
#define PLANT_H

/*!
 * @headerfile Plant.h
 */
#include "libraries.h"
#include "PlantCare.h"
#include "PlantState.h"

class PlantState;
class PlantCare;
class SeedingCare;

/*!
 * @class Plant
 *
 * @Brief Main Plant class
 *
 *  Parent class for different types of plants.
 */
class Plant
{
protected:
    string id;
    string group;
    string plant_type;
    double plant_price; //<------- used by getCost()
    int health;
    bool fertilized;          //<---- used by nuturePlant()
    bool watered;             //<---- used by nuturePlant()
    bool sunLit;              //<---- used by nuturePlant()
    static int instanceCount; // <---used to make unique plant id
    PlantState *currState;
    PlantCare *careRegime;

    bool needsCare(); //<--------------------?

    void incrementHealth(int num);
    int handleCare(); // this shoul be made protected since nuturePlant calls this and is used by health.

public:
    Plant();
    virtual ~Plant();

    // ............. virtual functions ............ //
    virtual string getDetails() = 0;
    virtual double getCost() = 0;
    virtual Plant *clone() = 0;
    virtual void decorate(Plant *_plant) = 0;

    // ............ getters .................//
    string getPlantID() { return id; };
    string getPlantGroup() { return group; };
    int getPlantHealth() { return health; };
    string getPlantType() { return plant_type; };
    string getState();
    string getCareRegime();

    // ............. setters ................//
    void changeState(PlantState *_plant); // <----------- used ONLY by PlantState

    // ........... other functions .............//
    void nuturePlant(); //<--------------------------- Hortuculturist uses this function.
                        // bool isReadyForStorage()?  if plant state is in Mature
};

/*!
 * @class Succulent
 *
 * @brief public subclass of Plant, category of plants
 */
class Succulent : public Plant
{
public:
    Succulent();
    virtual ~Succulent();
};

/*!
 * @class PeanutCactus
 *
 * @brief public subclass of Succulent, specific kind of plant
 */
class PeanutCactus : public Succulent
{
public:
    PeanutCactus();
    virtual ~PeanutCactus();
    virtual Plant *clone() override;
    virtual string getDetails() override;
    virtual double getCost() override;
    virtual void decorate(Plant *_plant) override;
};


/*!
 * @class HouseLeek
 *
 * @brief public subclass of Succulent, specific kind of plant
 */
class HouseLeek : public Succulent
{
public:
    HouseLeek();
    virtual ~HouseLeek();
    virtual Plant *clone() override;
    virtual string getDetails() override;
    virtual double getCost() override;
    virtual void decorate(Plant *_plant) override;
};

/*!
 * @class Flower
 *
 * @brief public subclass of Plant, category of plants
 */
class Flower : public Plant
{
public:
    Flower();
    ~Flower();
};

/*!
 * @class Orchid
 *
 * @brief public subclass of Flower, specific kind of plant
 */
class Orchid : public Flower
{
public:
    Orchid();
    ~Orchid();
    virtual Plant *clone() override;
    virtual string getDetails() override;
    virtual double getCost() override;
    virtual void decorate(Plant *_plant) override;
};

/*!
 * @class Marigold
 *
 * @brief public subclass of Flower, specific kind of plant
 */
class Marigold : public Flower
{
public:
    Marigold();
    virtual ~Marigold();
    virtual Plant *clone() override;
    virtual string getDetails() override;
    virtual double getCost() override;
    virtual void decorate(Plant *_plant) override;
};

/*!
 * @class Shrub
 *
 * @brief public subclass of Plant, category of plants
 */
class Shrub : public Plant
{
public:
    Shrub();
    ~Shrub();
};

/*!
 * @class BeeBlossom
 *
 * @brief public subclass of Shrub, specific kind of plant
 */
class BeeBlossom : public Shrub
{
public:
    BeeBlossom();
    ~BeeBlossom();
    virtual Plant *clone() override;
    virtual string getDetails() override;
    virtual double getCost() override;
    virtual void decorate(Plant *_plant) override;
};

/*!
 * @class HoneySuckle
 *
 * @brief public subclass of Shrub, specific kind of plant
 */
class HoneySuckle : public Shrub
{
public:
    HoneySuckle();
    virtual ~HoneySuckle();
    virtual Plant *clone() override;
    virtual string getDetails() override;
    virtual double getCost() override;
    virtual void decorate(Plant *_plant) override;
};

#endif // PLANT_H