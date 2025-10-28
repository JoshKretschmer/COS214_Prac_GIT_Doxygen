#include "Plant.h"
#include "PlantState.h"

/*!
 *  @file Plant.cpp
 *
 *  @brief Contains function definitions for the Plant functions defined in Plant.h
 */

int Plant::instanceCount = 1;

Plant::Plant()
{
    health = 0;
    currState = new SeedingState();
    careRegime = NULL;
    fertilized = false;
    watered = false;
    sunLit = false;
    id = toUpperCase("plant") + to_string(instanceCount);
    instanceCount++;

    // initialize careRegime here
}

Plant::~Plant()
{
    delete currState;
    delete careRegime;

    instanceCount--;
}

bool Plant::needsCare()
{
    if (this->getState() == toUpperCase("Dead"))
    {
        return false;
    }

    if (this->health < 5)
    {
        return true;
    }
    return false;
}

void Plant::incrementHealth(int num)
{
    this->health = this->health + num;
}

int Plant::handleCare()
{
    return currState->handleCare(this);
}

void Plant::nuturePlant() // basically handles how state changes based off prior requirements.
{
    if (currState->getStateName() == "DEAD")
    {
        cout << errorMessage("cannot nuture a dead plant...\nNo changes occurred");
    }
    else
    {
        if (fertilized && watered && sunLit)
        {
            incrementHealth(handleCare()); //<---------------------- state changes
            delete careRegime;
            careRegime =NULL;
            fertilized = false;
            watered = false;
            sunLit = false;
        }
        else if (!fertilized)
        {
            if (careRegime)
            {
                delete careRegime;
                careRegime = new FertilizingStrategy();
                fertilized = careRegime->executeCare();
            }
            else
            {
                careRegime = new FertilizingStrategy();
                fertilized = careRegime->executeCare();
            }
        }
        else if (!watered)
        {
            if (careRegime)
            {
                delete careRegime;
                careRegime = new WateringStrategy();
                watered = careRegime->executeCare();
            }
            else
            {
                careRegime = new WateringStrategy();
                watered = careRegime->executeCare();
            }
        }
        else if (!sunLit)
        {
            if (careRegime)
            {
                delete careRegime;
                careRegime = new SunlightStrategy();
                sunLit = careRegime->executeCare();
            }
            else
            {
                careRegime = new SunlightStrategy();
                sunLit = careRegime->executeCare();
            }
        }
        else
        {
            cout << errorMessage("Logic needs to be fixed then...");
        }
    }
}

void Plant::changeState(PlantState* _newState)
{
    if(currState)
    {
        delete currState;
        currState = _newState;
    }
    else
    {
        currState = _newState;
    }
}

string Plant::getState()
{
    if(currState)
    {
        return currState->getStateName();
    }
    else
    {
        cout<<errorMessage("state has not been set yet... :)");
        return "";
    }
}

string Plant::getCareRegime()
{
    if(careRegime)
    {
        return careRegime->getStrategyName();
    }
    else
    {
        cout<<errorMessage("Stategy has not been set yet :)");
        return "";
    }
}


//................... SUCCULENT..................//

Succulent::Succulent() : Plant()
{
    group = toUpperCase("Succulent");
}

Succulent::~Succulent()
{
    // still need to verify object flow of control
}

//............... PEANUTCACTUS...................//

PeanutCactus::PeanutCactus() : Succulent()
{
    plant_type = toUpperCase("peanutcactus");
    plant_price = 35.00;
}

PeanutCactus::~PeanutCactus()
{
    // still need to verify object flow of control
}

Plant *PeanutCactus::clone()
{
    Plant *copy = new PeanutCactus();
    return copy;
}

string PeanutCactus::getDetails()
{
    string det;
    det += "    ID: " + id + "\n";
    det += "  Type: " + plant_type + "\n";
    det += " Group: " + group + "\n";
    det += "Health: " + to_string(health) + "\n";
    det += " State: " + currState->getStateName() + "\n";
    det += " Price: " + to_string(plant_price) + "\n";
    return det;
}

double PeanutCactus::getCost()
{
    return plant_price;
}

void PeanutCactus::decorate(Plant *_plant)
{
    cout << errorMessage("You not supposed to use decorate from concretePlant");
}
//............. HOUSELEEK ...................//

HouseLeek::HouseLeek() : Succulent()
{
    plant_type = toUpperCase("houseleek");
    plant_price = 35.50;
}

HouseLeek::~HouseLeek()
{
    // still need to verify object flow of control
}

Plant *HouseLeek::clone()
{
    Plant *copy = new HouseLeek();
    return copy;
}

string HouseLeek::getDetails()
{
    string det;
    det += "    ID: " + id + "\n";
    det += "  Type: " + plant_type + "\n";
    det += " Group: " + group + "\n";
    det += "Health: " + to_string(health) + "\n";
    det += " State: " + currState->getStateName() + "\n";
    det += " Price: " + to_string(plant_price) + "\n";
    return det;
}

double HouseLeek::getCost()
{
    return plant_price;
}

void HouseLeek::decorate(Plant *_plant)
{
    cout << errorMessage("You not supposed to use decorate from concretePlant");
}
//................ FLOWER ....................//

Flower::Flower() : Plant()
{
    group = toUpperCase("flower");
}

Flower::~Flower()
{
    // still need to verify object flow of control
}

//...................... ORCHID ..................... //

Orchid::Orchid() : Flower()
{
    plant_type = toUpperCase("orchid");
    plant_price = 160.00;
}

Orchid::~Orchid()
{
    // still need to verify object flow of control
}

Plant *Orchid::clone()
{
    Plant *copy = new Orchid();
    return copy;
}

string Orchid::getDetails()
{
    string det;
    det += "    ID: " + id + "\n";
    det += "  Type: " + plant_type + "\n";
    det += " Group: " + group + "\n";
    det += "Health: " + to_string(health) + "\n";
    det += " State: " + currState->getStateName() + "\n";
    det += " Price: " + to_string(plant_price) + "\n";
    return det;
}

double Orchid::getCost()
{
    return plant_price;
}

void Orchid::decorate(Plant *_plant)
{
    cout << errorMessage("You not supposed to use decorate from concretePlant");
}
//................. MARIGOLD ..................//

Marigold::Marigold() : Flower()
{
    plant_type = toUpperCase("marigold");
    plant_price = 16.00;
}

Marigold::~Marigold()
{
    // still need to verify object flow of control
}

Plant *Marigold::clone()
{
    Plant *copy = new Marigold();
    return copy;
}

string Marigold::getDetails()
{
    string det;
    det += "    ID: " + id + "\n";
    det += "  Type: " + plant_type + "\n";
    det += " Group: " + group + "\n";
    det += "Health: " + to_string(health) + "\n";
    det += " State: " + currState->getStateName() + "\n";
    det += " Price: " + to_string(plant_price) + "\n";
    return det;
}

double Marigold::getCost()
{
    return plant_price;
}

void Marigold::decorate(Plant *_plant)
{
    cout << errorMessage("You not supposed to use decorate from concretePlant");
}
//................. SHRUB ...................//

Shrub::Shrub() : Plant()
{
    group = toUpperCase("shrub");
}

Shrub::~Shrub()
{
    // still need to verify object flow of control
}

//................. BEEBLOSSOM ...................//

BeeBlossom::BeeBlossom() : Shrub()
{
    plant_type = toUpperCase("beeblossom");
    plant_price = 21.00;
}

BeeBlossom::~BeeBlossom()
{
    // still need to verify object flow of control
}

Plant *BeeBlossom::clone()
{
    Plant *copy = new BeeBlossom();
    return copy;
}

string BeeBlossom::getDetails()
{
    string det;
    det += "    ID: " + id + "\n";
    det += "  Type: " + plant_type + "\n";
    det += " Group: " + group + "\n";
    det += "Health: " + to_string(health) + "\n";
    det += " State: " + currState->getStateName() + "\n";
    det += " Price: " + to_string(plant_price) + "\n";
    return det;
}

double BeeBlossom::getCost()
{
    return plant_price;
}

void BeeBlossom::decorate(Plant *_plant)
{
    cout << errorMessage("You not supposed to use decorate from concretePlant");
}
//............... HONEYSUCKLE...................//

HoneySuckle::HoneySuckle() : Shrub()
{
    plant_type = toUpperCase("honeysuckle");
    this->plant_price = 39.95;
}

HoneySuckle::~HoneySuckle()
{
    // still need to verify object flow of control
}

Plant *HoneySuckle::clone()
{
    Plant *copy = new HoneySuckle();
    return copy;
}

string HoneySuckle::getDetails()
{
    string det;
    det += "    ID: " + id + "\n";
    det += "  Type: " + plant_type + "\n";
    det += " Group: " + group + "\n";
    det += "Health: " + to_string(health) + "\n";
    det += " State: " + currState->getStateName() + "\n";
    det += " Price: " + to_string(plant_price) + "\n";
    return det;
}

double HoneySuckle::getCost()
{
    return plant_price;
}

void HoneySuckle::decorate(Plant *_plant)
{
    cout << errorMessage("You not supposed to use decorate from concretePlant");
}