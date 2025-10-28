#include "Plant.h"
#include "PlantState.h"

/*!
 *  @file Plant.cpp
 *
 *  @brief Contains function definitions for the Plant functions defined in Plant.h
 */

int Plant::instanceCount = 1;

/*!
 * @brief Basic constructor for Plant object
 */
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

/*!
 * @brief Basic destructor for Plant object
 */
Plant::~Plant()
{
    delete currState;
    delete careRegime;

    instanceCount--;
}

/*!
 *
 * @return True if care actions need to be executed on the plant, false otherwise
 */
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

/*!
 *
 * @param num value with which to increase the plant health attribute
 */
void Plant::incrementHealth(int num)
{
    this->health = this->health + num;
}

/*!
 *
 * @return Executes care tasks on the Plant according to current PlantCare Strategy
 */
int Plant::handleCare()
{
    return currState->handleCare(this);
}

/*!
 * @brief Handles how care tasks are executed
 */
void Plant::nuturePlant()
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

/*!
 *
 * @param _newState State to which Plant transitions
 */
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

/*!
 *
 * @return Current state of the Plant object
 */
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

/*!
 *
 * @return Current care Strategy of the plant
 */
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

/*!
 * @brief Basic constructor for Succulents
 */
Succulent::Succulent() : Plant()
{
    group = toUpperCase("Succulent");
}

/*!
 * @brief Basic destructor for Succulents
 */
Succulent::~Succulent()
{
    // still need to verify object flow of control
}

//............... PEANUTCACTUS...................//

/*!
 * @brief Basic constructor for PeanutCactus
 */
PeanutCactus::PeanutCactus() : Succulent()
{
    plant_type = toUpperCase("peanutcactus");
    plant_price = 35.00;
}

/*!
 * @brief Basic destructor for PeanutCactus
 */
PeanutCactus::~PeanutCactus()
{
    // still need to verify object flow of control
}

/*!
 *
 * @return Clone of current Plant object
 */
Plant *PeanutCactus::clone()
{
    Plant *copy = new PeanutCactus();
    return copy;
}

/*!
 *
 * @return String for all relevant details of the Plant object
 */
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

/*!
 *
 * @return Basic cost of the Plant
 */
double PeanutCactus::getCost()
{
    return plant_price;
}

/*!
 * @brief Trap function to catch logic errors
 *
 * @param _plant
 */
void PeanutCactus::decorate(Plant *_plant)
{
    cout << errorMessage("You not supposed to use decorate from concretePlant");
}
//............. HOUSELEEK ...................//

/*!
 * @brief Basic constructor for HouseLeek
 */
HouseLeek::HouseLeek() : Succulent()
{
    plant_type = toUpperCase("houseleek");
    plant_price = 35.50;
}

/*!
 * @brief Basic destructor for HouseLeek
 */
HouseLeek::~HouseLeek()
{
    // still need to verify object flow of control
}

/*!
 *
 * @return Clone of current Plant object
 */
Plant *HouseLeek::clone()
{
    Plant *copy = new HouseLeek();
    return copy;
}

/*!
 *
 * @return String for all relevant details of the Plant object
 */
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

/*!
 *
 * @return Basic cost of the Plant
 */
double HouseLeek::getCost()
{
    return plant_price;
}

/*!
 * @brief Trap function to catch logic errors
 *
 * @param _plant
 */
void HouseLeek::decorate(Plant *_plant)
{
    cout << errorMessage("You not supposed to use decorate from concretePlant");
}
//................ FLOWER ....................//

/*!
 * @brief Basic constructor for Flowers
 */
Flower::Flower() : Plant()
{
    group = toUpperCase("flower");
}

/*!
 * @brief Basic destructor for Flowers
 */
Flower::~Flower()
{
    // still need to verify object flow of control
}

//...................... ORCHID ..................... //

/*!
 * @brief Basic constructor for Orchid
 */
Orchid::Orchid() : Flower()
{
    plant_type = toUpperCase("orchid");
    plant_price = 160.00;
}

/*!
 * @brief Basic destructor for Orchid
 */
Orchid::~Orchid()
{
    // still need to verify object flow of control
}

/*!
 *
 * @return Clone of current Plant object
 */
Plant *Orchid::clone()
{
    Plant *copy = new Orchid();
    return copy;
}

/*!
 *
 * @return String for all relevant details of the Plant object
 */
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

/*!
 *
 * @return Basic cost of the Plant
 */
double Orchid::getCost()
{
    return plant_price;
}

/*!
 * @brief Trap function to catch logic errors
 *
 * @param _plant
 */
void Orchid::decorate(Plant *_plant)
{
    cout << errorMessage("You not supposed to use decorate from concretePlant");
}
//................. MARIGOLD ..................//

/*!
 * @brief Basic constructor for Marigold
 */
Marigold::Marigold() : Flower()
{
    plant_type = toUpperCase("marigold");
    plant_price = 16.00;
}

/*!
 * @brief Basic destructor for Marigold
 */
Marigold::~Marigold()
{
    // still need to verify object flow of control
}

/*!
 *
 * @return Clone of current Plant object
 */
Plant *Marigold::clone()
{
    Plant *copy = new Marigold();
    return copy;
}

/*!
 *
 * @return String for all relevant details of the Plant object
 */
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

/*!
 *
 * @return Basic cost of the Plant
 */
double Marigold::getCost()
{
    return plant_price;
}

/*!
 * @brief Trap function to catch logic errors
 *
 * @param _plant
 */
void Marigold::decorate(Plant *_plant)
{
    cout << errorMessage("You not supposed to use decorate from concretePlant");
}
//................. SHRUB ...................//

/*!
 * @brief Basic constructor for Shrubs
 */
Shrub::Shrub() : Plant()
{
    group = toUpperCase("shrub");
}

/*!
 * @brief Basic destructor for Shrubs
 */
Shrub::~Shrub()
{
    // still need to verify object flow of control
}

//................. BEEBLOSSOM ...................//

/*!
 * @brief Basic constructor for BeeBlossom
 */
BeeBlossom::BeeBlossom() : Shrub()
{
    plant_type = toUpperCase("beeblossom");
    plant_price = 21.00;
}

/*!
 * @brief Basic destructor for BeeBlossom
 */
BeeBlossom::~BeeBlossom()
{
    // still need to verify object flow of control
}

/*!
 *
 * @return Clone of current Plant object
 */
Plant *BeeBlossom::clone()
{
    Plant *copy = new BeeBlossom();
    return copy;
}

/*!
 *
 * @return String for all relevant details of the Plant object
 */
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

/*!
 *
 * @return Basic cost of the Plant
 */
double BeeBlossom::getCost()
{
    return plant_price;
}

/*!
 * @brief Trap function to catch logic errors
 *
 * @param _plant
 */
void BeeBlossom::decorate(Plant *_plant)
{
    cout << errorMessage("You not supposed to use decorate from concretePlant");
}
//............... HONEYSUCKLE...................//

/*!
 * @brief Basic constructor for HoneySuckle
 */
HoneySuckle::HoneySuckle() : Shrub()
{
    plant_type = toUpperCase("honeysuckle");
    this->plant_price = 39.95;
}

/*!
 * @brief Basic destructor for HoneySuckle
 */
HoneySuckle::~HoneySuckle()
{
    // still need to verify object flow of control
}

/*!
 *
 * @return Clone of current Plant object
 */
Plant *HoneySuckle::clone()
{
    Plant *copy = new HoneySuckle();
    return copy;
}

/*!
 *
 * @return String for all relevant details of the Plant object
 */
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

/*!
 *
 * @return Basic cost of the Plant
 */
double HoneySuckle::getCost()
{
    return plant_price;
}

/*!
 * @brief Trap function to catch logic errors
 *
 * @param _plant
 */
void HoneySuckle::decorate(Plant *_plant)
{
    cout << errorMessage("You not supposed to use decorate from concretePlant");
}