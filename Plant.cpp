#include "Plant.h"
#include "PlantState.h"

Plant::Plant()
{
    health = 0;
    currState = new SeedingState();

    // initialize careRegime here
}

Plant::~Plant()
{
    delete currState;
    delete careRegime;
}

void Plant::changeState(PlantState *newState)
{
    delete currState;
    this->currState = newState;
}

bool Plant::needsCare()
{
    if (this->getState() == "Dead")
    {
        return false;
    }

    if (this->health < 5)
    {
        return true;
    }
    return false;
}

vector<Plant *> Plant::getPlants()
{
    return vector<Plant *>();
}

void Plant::movePlant(Plant *plant, string newState)
{
}

void Plant::incrementHealth(int num)
{
    this->health = this->health + num;
    this->currState->handleCare(this);
}

string Plant::getState()
{
    return currState->getStateName();
}

//................... SUCCULENT..................//

Succulent::Succulent() : Plant::Plant()
{
    type = "Succulent";
}

//............... PEANUTCACTUS...................//

PeanutCactus::PeanutCactus() : Succulent::Succulent()
{
    int randomNum = rand() % 101;
    this->id = "PC" + to_string(randomNum);

    this->price = 35.00;
}

string PeanutCactus::getDetails()
{
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Peanut Cactus" + "\n";
    return det;
}

double PeanutCactus::getCost()
{
    return this->price;
}

Plant* PeanutCactus::clone()
{
    Plant* copy = new PeanutCactus();

    return copy;

}

//............. HOUSELEEK ...................//

HouseLeek::HouseLeek() : Succulent::Succulent()
{
    int randomNum = rand() % 101;
    this->id = "HL" + to_string(randomNum);

    this->price = 35.50;
}

string HouseLeek::getDetails()
{
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: House Leek" + "\n";
    return det;
}

double HouseLeek::getCost()
{
    return this->price;
}

Plant* HouseLeek::clone()
{
    Plant* copy = new HouseLeek();

    return copy;

}




//................ FLOWER ....................//

Flower::Flower() : Plant::Plant()
{
    type = "Flower";
}

//...................... ORCHID ..................... //

Orchid::Orchid() : Flower::Flower()
{
    int randomNum = rand() % 101;
    this->id = "OR" + to_string(randomNum);

    this->price = 160.00;
}

string Orchid::getDetails()
{
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Orchid" + "\n";
    return det;
}

double Orchid::getCost()
{
    return this->price;
}

Plant* Orchid::clone()
{
    Plant* copy = new Orchid();

    return copy;

}




//................. MARIGOLD ..................//

Marigold::Marigold() : Flower::Flower()
{
    int randomNum = rand() % 101;
    this->id = "MG" + to_string(randomNum);

    this->price = 16.00;
}

string Marigold::getDetails()
{
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Marigold" + "\n";
    return det;
}

double Marigold::getCost()
{
    return this->price;
}

Plant* Marigold::clone()
{
    Plant* copy = new Marigold();

    return copy;

}




//................. SHRUB ...................//

Shrub::Shrub() : Plant::Plant()
{
    type = "Shrub";
}

//................. BEEBLOSSOM ...................//

BeeBlossom::BeeBlossom() : Shrub::Shrub()
{
    int randomNum = rand() % 101;
    this->id = "BB" + to_string(randomNum);

    this->price = 21.00;
}

string BeeBlossom::getDetails()
{
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Bee Blossom" + "\n";
    return det;
}

double BeeBlossom::getCost()
{
    return this->price;
}

Plant* BeeBlossom::clone()
{
    Plant* copy = new BeeBlossom();

    return copy;

}




//............... HONEYSUCKLE...................//

HoneySuckle::HoneySuckle() : Shrub::Shrub()
{
    int randomNum = rand() % 101;
    this->id = "HS" + to_string(randomNum);

    this->price = 39.95;
}

string HoneySuckle::getDetails()
{
    string det;
    det = det + "ID: " + id + "\n";
    det = det + "Type: " + type + "\n";
    det = det + "Name: Honey Suckle" + "\n";
    return det;
}

double HoneySuckle::getCost()
{
    return this->price;
}


Plant* HoneySuckle::clone()
{
    Plant* copy = new HoneySuckle();

    return copy;

}