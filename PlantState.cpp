#include "PlantState.h"
#include <iostream>
PlantState::PlantState() {
    // Constructor implementation
    std::cout << "PlantState: Created" << std::endl;
}

PlantState::~PlantState() {
    std::cout << "PlantState: Destroyed" << std::endl;
}


//################################################


SeedingState::SeedingState() {
    std::cout << "SeedingState: Created" << std::endl;
}

void SeedingState::handleCare(Plant &plant) {
    cout << "SeedingState: Watering and fertilizing young plant..." << endl;
    // Example: auto-transition
    plant.changeState(new GrowingState());
}

string SeedingState::getStateName() {
    return "Seeding";
}


//################################################


GrowingState::GrowingState() {
    std::cout << "GrowingState: Created" << std::endl;
}

void GrowingState::handleCare(Plant& plant) {
    cout << "GrowingState: Providing sunlight and nutrients..." << endl;
    // Example: auto-transition
    plant.changeState(new MatureState());
}

string GrowingState::getStateName() {
    return "Growing";
}


//################################################


MatureState::MatureState() {
    std::cout << "MatureState: Created" << std::endl;
}

void MatureState::handleCare(Plant& plant) {
    cout << "MatureState: Maintaining plant health..." << endl;
    // Example: auto-transition
    plant.changeState(new MoultState());
}

string MatureState::getStateName() {
    return "Mature";
}


//################################################


MoultState::MoultState() {
    std::cout << "MoultState: Created" << std::endl;
}

void MoultState::handleCare(Plant& plant) {
    cout << "MoultState: Plant is aging, special care needed..." << endl;
    // Could end lifecycle here
}

string MoultState::getStateName() {
    return "Moult";
}
