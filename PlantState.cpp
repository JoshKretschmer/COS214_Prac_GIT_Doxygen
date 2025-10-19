#include "PlantState.h"

PlantState::PlantState() {

}

PlantState::~PlantState() {

}


//################################################


SeedingState::SeedingState() {

}

void SeedingState::handleCare(Plant &plant) {

}

string SeedingState::getStateName() {
    return "Seeding";
}


//################################################


GrowingState::GrowingState() {

}

void GrowingState::handleCare(Plant& plant) {

}

string GrowingState::getStateName() {
    return "Growing";
}


//################################################


MatureState::MatureState() {

}

void MatureState::handleCare(Plant& plant) {

}

string MatureState::getStateName() {
    return "Mature";
}


//################################################


MoultState::MoultState() {

}

void MoultState::handleCare(Plant& plant) {

}

string MoultState::getStateName() {
    return "Moult";
}

