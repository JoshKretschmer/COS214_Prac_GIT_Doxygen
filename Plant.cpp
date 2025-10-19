#include "Plant.h"
#include "PlantState.h"

//will do doxygen later

//initialize info shared by all plants
Plant::Plant() {
    health = 0;
    currState = new SeedingState();

    //initialize careRegime here
}

Plant::~Plant() {
    delete currState;
    delete careRegime;
}


//set new state for plant
void Plant::changeState(PlantState *newState) {
    this->currState=newState;
}

//if plant is not fully grown, it needs care
bool Plant::needsCare() {
    if (this->health <5) {
        return true;
    }
    return false;
}



//inventory related i.e NOT ME
/*void Plant::add(InventoryComponent *comp) {

}

//inventory related i.e NOT ME
void Plant::remove(InventoryComponent *comp) {

}

//inventory related i.e NOT ME
vector<Plant *> Plant::getPlants() {
    return vector<Plant*>();
}

//inventory related i.e NOT ME
void Plant::movePlant(Plant *plant, string newState) {

}
*/


//#####################################################

//initialize plant type
Succulent::Succulent() : Plant::Plant() {
    type = "Succulent";
}

//#####################################################

//initialize plant id and price
PeanutCactus::PeanutCactus() : Succulent::Succulent() {
    int randomNum = rand() % 101;
    this->id = "HS" + to_string(randomNum);

    this->price = 35.00;
}

//get id,type,name, and price of plant
string PeanutCactus::getDetails() {
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Peanut Cactus" + "\n";
    det = det + "Price: " + to_string(price) + "\n";
    return det;
}

//return price as double
double PeanutCactus::getCost() {
    return this->price;
}

//#####################################################


//initialize plant id and price
HouseLeek::HouseLeek() : Succulent::Succulent() {
    int randomNum = rand() % 101;
    this->id = "HS" + to_string(randomNum);

    this->price = 35.50;
}

//get id,type,name, and price of plant
string HouseLeek::getDetails() {
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: House Leek" + "\n";
    det = det + "Price: " + to_string(price) + "\n";
    return det;
}

//return price as double
double HouseLeek::getCost() {
    return this->price;
}

//#####################################################

//initialize plant type
Flower::Flower() : Plant::Plant() {
    type = "Flower";
}

//#####################################################

//initialize plant id and price
Orchid::Orchid() : Flower::Flower() {
    int randomNum = rand() % 101;
    this->id = "HS" + to_string(randomNum);

    this->price = 160.00;
}

//get id,type,name, and price of plant
string Orchid::getDetails() {
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Orchid" + "\n";
    det = det + "Price: " + to_string(price) + "\n";
    return det;
}

//return price as double
double Orchid::getCost() {
    return this->price;
}

//#####################################################

//initialize plant id and price
Marigold::Marigold() : Flower::Flower() {
    int randomNum = rand() % 101;
    this->id = "HS" + to_string(randomNum);

    this->price = 16.00;
}

//get id,type,name, and price of plant
string Marigold::getDetails() {
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Marigold" + "\n";
    det = det + "Price: " + to_string(price) + "\n";
    return det;
}

//return price as double
double Marigold::getCost() {
    return this->price;
}

//#####################################################

//initialize plant type
Shrub::Shrub() : Plant::Plant() {
    type = "Shrub";
}

//#####################################################

//initialize plant id and price
BeeBlossom::BeeBlossom() : Shrub::Shrub() {
    int randomNum = rand() % 101;
    this->id = "HS" + to_string(randomNum);

    this->price = 21.00;
}

//get id,type,name, and price of plant
string BeeBlossom::getDetails() {
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Bee Blossom" + "\n";
    det = det + "Price: " + to_string(price) + "\n";
    return det;
}

//return price as double
double BeeBlossom::getCost() {
    return this->price;
}

//#####################################################

//initialize plant id and price
HoneySuckle::HoneySuckle() : Shrub::Shrub() {
    int randomNum = rand() % 101;
    this->id = "HS" + to_string(randomNum);

    this->price = 39.95;
}

//get id,type,name, and price of plant
string HoneySuckle::getDetails() {
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Honey Suckle" + "\n";
    det = det + "Price: " + to_string(price) + "\n";
    return det;
}

//return price as double
double HoneySuckle::getCost() {
    return this->price;
}
