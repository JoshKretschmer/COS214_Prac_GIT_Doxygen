#include "PlantDecorator.h"

ConcretePlant::ConcretePlant() {

}

string ConcretePlant::getDetails() {
    return "";
}

double ConcretePlant::getCost() {
    return 0;
}

//#################################################

PlantDecorator::PlantDecorator() {

}

//#################################################

ArrangementDecorator::ArrangementDecorator() {

}

string ArrangementDecorator::getDetails() {
    return "";
}

double ArrangementDecorator::getCost() {
    return 0;
}

//#################################################

PotDecorator::PotDecorator() {

}

string PotDecorator::getDetails() {
    return "";
}

double PotDecorator::getCost() {
    return 0;
}

//#################################################

WrapDecorator::WrapDecorator() {

}

string WrapDecorator::getDetails() {
    return "";
}

double WrapDecorator::getCost() {
    return 0;
}
