#include "PlantState.h"

PlantState::PlantState()
{
    // Constructor implementation
    cout<<"\nPlantState: Created\n";
}

PlantState::~PlantState()
{
    cout<<"\nPlantState: Destroyed\n";
}


//################################################


SeedingState::SeedingState()
{
   cout<<"\nSeedingState: Created\n";;
}

void SeedingState::handleCare(Plant* plant)
{
    cout<<"\nSeedingState: Watering and fertilizing young plant...\n";
    // Example: auto-transition
    PlantState* newState = new GrowingState();
    plant->changeState(newState);
}

string SeedingState::getStateName()
{
    return "Seeding";
}


//################################################


GrowingState::GrowingState()
{
    cout << "\nGrowingState: Created\n";
}

void GrowingState::handleCare(Plant* plant)
{
    cout<<"\nGrowingState: Providing sunlight and nutrients...\n";
    // Example: auto-transition
    PlantState* newState = new MatureState();
    plant->changeState(newState);
}

string GrowingState::getStateName()
{
    return "Growing";
}


//################################################


MatureState::MatureState()
{
    cout<<"\nMatureState: Created\n";
}

void MatureState::handleCare(Plant* plant)
{
    cout<<"\nMatureState: Maintaining plant health...\n";
    // Example: auto-transition
    PlantState* newState = new MoultState();
    plant->changeState(newState);
}

string MatureState::getStateName()
{
    return "Mature";
}


//################################################


MoultState::MoultState()
{
   cout<<"\nMoultState: Created\n";
}

void MoultState::handleCare(Plant* plant)
{
    cout<<"\nMoultState: Plant is aging, special care needed...\n";
    // Could end lifecycle here
}

string MoultState::getStateName() {
    return "Moult";
}


//###############################################


void DeadState::handleCare(Plant *plant)
{
    cout<<"\nDead\n";

}

string DeadState::getStateName()
{
    return "Dead";
}
