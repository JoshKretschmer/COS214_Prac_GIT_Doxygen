/*!
 *  @file Plant.cpp
 *
 *  @brief Contains function definitions for the Plant functions defined in Plant.h
 */

#include "Plant.h"
#include "PlantState.h"


/*!
 * @brief Plant constructor function
 *
 * Initializes information shared by all plants (health, currState, careRegime)
 */
Plant::Plant() {
    health = 0;
    currState = new SeedingState();

    //initialize careRegime here
}

/*!
 * @brief Destructor for Plant class
 */
Plant::~Plant() {
    delete currState;
    delete careRegime;
}

/*!
 * @brief Changes the state of the Plant object
 *
 * Called in the PlantState class
 *
 * @param newState State that Plant object is being set to
 */
void Plant::changeState(PlantState *newState) {
    delete currState;
    this->currState=newState;
}

/*!
 * @brief If a Plant is not fully grown, care is still needed
 *
 * @return bool stating whether care is needed
 */
bool Plant::needsCare() {
    if (this->health <5) {
        return true;
    }
    return false;
}


void Plant::add(InventoryComponent *comp) {

}

void Plant::remove(InventoryComponent *comp) {

}

vector<Plant *> Plant::getPlants() {
    return vector<Plant*>();
}

void Plant::movePlant(Plant *plant, string newState) {

}



//#####################################################

/*!
 * @brief Constructor function for Succulent class
 *
 * Initialized type attribute, then calls Plant() constructor
 */
Succulent::Succulent() : Plant::Plant() {
    type = "Succulent";
}

//#####################################################

/*!
 * @brief Constructor function for PeanutCactus class
 *
 * Initializes id and price attributes, then calls Succulent() constructor
 */
PeanutCactus::PeanutCactus() : Succulent::Succulent() {
    int randomNum = rand() % 101;
    this->id = "PC" + to_string(randomNum);

    this->price = 35.00;
}

/*!
 *  return string formatted as ID: [id] \n Type: [type] \n Name: Peanut Cactus
 *
 * @return string containing basic details of the plant
 */
string PeanutCactus::getDetails() {
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Peanut Cactus" + "\n";
    return det;
}

/*!
 * @return price attribute of PeanutCactus (35.00)
 */
double PeanutCactus::getCost() {
    return this->price;
}

//#####################################################


/*!
 * @brief Constructor function for HouseLeek class
 *
 * Initializes id and price attributes, then calls Succulent() constructor
 */
HouseLeek::HouseLeek() : Succulent::Succulent() {
    int randomNum = rand() % 101;
    this->id = "HL" + to_string(randomNum);

    this->price = 35.50;
}

/*!
 *  return string formatted as ID: [id] \n Type: [type] \n Name: House Leek
 *
 * @return string containing basic details of the plant
 */
string HouseLeek::getDetails() {
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: House Leek" + "\n";
    return det;
}

/*!
 * @return price attribute of HouseLeek (35.50)
 */
double HouseLeek::getCost() {
    return this->price;
}

//#####################################################

/*!
 * @brief Constructor function for Flower class
 *
 * Initialized type attribute, then calls Plant() constructor
 */
Flower::Flower() : Plant::Plant() {
    type = "Flower";
}

//#####################################################

/*!
 * @brief Constructor function for Orchid class
 *
 * Initializes id and price attributes, then calls Flower() constructor
 */
Orchid::Orchid() : Flower::Flower() {
    int randomNum = rand() % 101;
    this->id = "OR" + to_string(randomNum);

    this->price = 160.00;
}

/*!
 *  return string formatted as ID: [id] \n Type: [type] \n Name: Orchid
 *
 * @return string containing basic details of the plant
 */
string Orchid::getDetails() {
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Orchid" + "\n";
    return det;
}

/*!
 * @return price attribute of Orchid (160.00)
 */
double Orchid::getCost() {
    return this->price;
}

//#####################################################

/*!
 * @brief Constructor function for Marigold class
 *
 * Initializes id and price attributes, then calls Flower() constructor
 */
Marigold::Marigold() : Flower::Flower() {
    int randomNum = rand() % 101;
    this->id = "MG" + to_string(randomNum);

    this->price = 16.00;
}

/*!
 *  return string formatted as ID: [id] \n Type: [type] \n Name: Marigold
 *
 * @return string containing basic details of the plant
 */
string Marigold::getDetails() {
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Marigold" + "\n";
    return det;
}

/*!
 * @return price attribute of Marigold (16.00)
 */
double Marigold::getCost() {
    return this->price;
}

//#####################################################

/*!
 * @brief Constructor function for Shrub class
 *
 * Initialized type attribute, then calls Plant() constructor
 */
Shrub::Shrub() : Plant::Plant() {
    type = "Shrub";
}

//#####################################################

/*!
 * @brief Constructor function for BeeBlossom class
 *
 * Initializes id and price attributes, then calls Shrub() constructor
 */
BeeBlossom::BeeBlossom() : Shrub::Shrub() {
    int randomNum = rand() % 101;
    this->id = "BB" + to_string(randomNum);

    this->price = 21.00;
}

/*!
 *  return string formatted as ID: [id] \n Type: [type] \n Name: Bee Blossom
 *
 * @return string containing basic details of the plant
 */
string BeeBlossom::getDetails() {
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Bee Blossom" + "\n";
    return det;
}

/*!
 * @return price attribute of BeeBlossom (21.00)
 */
double BeeBlossom::getCost() {
    return this->price;
}

//#####################################################

/*!
 * @brief Constructor function for HoneySuckle class
 *
 * Initializes id and price attributes, then calls Shrub() constructor
 */
HoneySuckle::HoneySuckle() : Shrub::Shrub() {
    int randomNum = rand() % 101;
    this->id = "HS" + to_string(randomNum);

    this->price = 39.95;
}

/*!
 *  return string formatted as ID: [id] \n Type: [type] \n Name: Honey Suckle
 *
 * @return string containing basic details of the plant
 */
string HoneySuckle::getDetails() {
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Honey Suckle" + "\n";
    return det;
}

/*!
 * @return price attribute of HoneySuckle (39.95)
 */
double HoneySuckle::getCost() {
    return this->price;
}

Succulent::~Succulent()
{

}

Plant* PeanutCactus::clone()
{
    Plant* copy = new PeanutCactus();
    return copy;
}

Plant* HouseLeek::clone()
{
    Plant* copy = new HouseLeek();
    return copy;
}

Plant* Orchid::clone()
{
    Plant* copy = new Orchid();
    return copy;
}

Plant* Marigold::clone()
{
    Plant* copy = new Marigold();
    return copy;
}

Plant* BeeBlossom::clone()
{
    Plant* copy = new BeeBlossom();
    return copy;
}

Plant* HoneySuckle::clone()
{
    Plant* copy = new HoneySuckle();
    return copy;
}