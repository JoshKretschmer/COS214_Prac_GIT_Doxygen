#include "PlantState.h"

PlantState::PlantState()
{
    // Constructor implementation
   // cout<<"\nPlantState: Created\n";
}

PlantState::~PlantState()
{
   // cout<<"\nPlantState: Destroyed\n";
}


//################################################


SeedingState::SeedingState()
{
   // cout<<"\nSeedingState: Created\n";;
}

int SeedingState::handleCare(Plant* plant)
{
    // Example: auto-transition
    PlantState* newState = new GrowingState();
    string oldState = plant->getState();
    plant->changeState(newState);
    cout<<"\nPlant changed from: "<<oldState<<" to "<<newState->getStateName()<<endl;

    return 50;
}

string SeedingState::getStateName()
{
    return toUpperCase("seeding");
}


//################################################


GrowingState::GrowingState()
{
   // cout << "\nGrowingState: Created\n";
}

int GrowingState::handleCare(Plant* plant)
{
    // Example: auto-transition
    PlantState* newState = new MatureState();
    string oldState = plant->getState();
    plant->changeState(newState);
    cout<<"\nPlant changed from: "<<oldState<<" to "<<newState->getStateName()<<endl;
    
    return 50;
}

string GrowingState::getStateName()
{
    return toUpperCase("growing");
}


//################################################


MatureState::MatureState()
{
   // cout<<"\nMatureState: Created\n";
}

int MatureState::handleCare(Plant* plant)
{
    // Example: auto-transition
    PlantState* newState = new MoultState();
    string oldState = plant->getState();
    plant->changeState(newState);
    cout<<"\nPlant changed from: "<<oldState<<" to "<<newState->getStateName()<<endl;

    return -75;
}

string MatureState::getStateName()
{
    return toUpperCase("mature");
}


//################################################


MoultState::MoultState()
{
  // cout<<"\nMoultState: Created\n";
}

int MoultState::handleCare(Plant* plant)
{
    // Example: auto-transition
    PlantState* newState = new DeadState();
    string oldState = plant->getState();
    plant->changeState(newState);
    cout<<"\nPlant changed from: "<<oldState<<" to "<<newState->getStateName()<<endl;

    return -25;
}

string MoultState::getStateName() {
    return toUpperCase("moult");
}


//###############################################


int DeadState::handleCare(Plant *plant)
{
    cout<<"\nDeadState: Plant is dead....\n";
    cout<<errorMessage("No state change occured");

    return 0;

}

string DeadState::getStateName()
{
    return toUpperCase("dead");
}
