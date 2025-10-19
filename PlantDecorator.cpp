#include "PlantDecorator.h"

//Plant (Component) is ConcretePlant (ConcreteComponent)

//#################################################

PlantDecorator::PlantDecorator() {
    wrappedPlant=nullptr;
}

PlantDecorator::~PlantDecorator() {
    delete wrappedPlant;
}


void PlantDecorator::setWrapped(Plant* wrappedPlant) {
    this->wrappedPlant = wrappedPlant;
}


//#################################################

string ArrangementDecorator::getDetails() {
    string det = getWrapped()->getDetails();
    det += "Decoration: Arrangement \n";
    return det;
}

double ArrangementDecorator::getCost() {
    double cost = getWrapped()->getCost();
    cost += 10;
    return cost;
}

//#################################################

string PotDecorator::getDetails() {
    string det = getWrapped()->getDetails();
    det += "Decoration: Pot \n";
    return det;
}

double PotDecorator::getCost() {
    double cost = getWrapped()->getCost();
    cost += 20;
    return cost;
}

//#################################################

string WrapDecorator::getDetails() {
    string det = getWrapped()->getDetails();
    det += "Decoration: Wrap \n";
    return det;
}

double WrapDecorator::getCost() {
    double cost = getWrapped()->getCost();
    cost += 15;
    return cost;
}
