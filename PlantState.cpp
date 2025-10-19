#include "PlantState.h"
#include "Plant.h"
#include <iostream>

PlantState::PlantState() {

}

PlantState::~PlantState() {

}


//################################################

//called every time after plant care is executed
void SeedingState::handleCare(Plant *plant) {
    int hp = plant->getHealth();
    if (hp >= 2) {
        //go to GrowingState
        plant->changeState(new GrowingState);
    } else if (hp < 0) {
        cout << "Plant " + plant->getID() + " has died.\n";
        //remove from inventory
    }
}

string SeedingState::getStateName() {
    return "Seeding";
}


//################################################

//called every time after plant care is executed
void GrowingState::handleCare(Plant* plant) {
    int hp = plant->getHealth();
    if (hp <=1) {
        //go to moult state
        plant->changeState(new MoultState);
    } else if (hp >= 4) {
        //go to matureState
        plant->changeState(new MatureState);
    }
}

string GrowingState::getStateName() {
    return "Growing";
}


//################################################

//called every time after plant care is executed
void MatureState::handleCare(Plant* plant) {
    int hp = plant->getHealth();
    if (hp <= 2) {
        //go to MoultState
        plant->changeState(new MoultState);
    }
}

string MatureState::getStateName() {
    return "Matured";
}


//################################################

//called every time after plant care is executed
void MoultState::handleCare(Plant* plant) {
    int hp = plant->getHealth();
    if (hp <= 0) {
        //plant has died
        cout << "Plant " + plant->getID() + " has died.\n";
        //remove from inventory
    } else if (hp >= 3) {
        //go to growing state
        plant->changeState(new GrowingState);
    }
}

string MoultState::getStateName() {
    return "Moulting";
}

