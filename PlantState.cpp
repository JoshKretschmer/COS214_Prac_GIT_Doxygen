#include "PlantState.h"

/*!
 * @brief Basic constructor for PlantState class
 */
PlantState::PlantState()
{
    // Constructor implementation
   // cout<<"\nPlantState: Created\n";
}

/*!
 * @brief Basic destructor for PlantState class
 */
PlantState::~PlantState()
{
   // cout<<"\nPlantState: Destroyed\n";
}


//################################################

/*!
 * @brief Basic constructor for SeedingState class
 */
SeedingState::SeedingState()
{
   // cout<<"\nSeedingState: Created\n";;
}

/*!
 * @Automated state change function
 *
 * @param plant Plant for which care is done
 * @return 50
 */
int SeedingState::handleCare(Plant* plant)
{
    // Example: auto-transition
    PlantState* newState = new GrowingState();
    string oldState = plant->getState();
    plant->changeState(newState);
    cout<<"\nPlant changed from: "<<oldState<<" to "<<newState->getStateName()<<endl;

    return 50;
}

/*!
 * @return "Seeding"
 */
string SeedingState::getStateName()
{
    return toUpperCase("seeding");
}


//################################################

/*!
 * @brief Basic constructor for GrowingState class
 */
GrowingState::GrowingState()
{
   // cout << "\nGrowingState: Created\n";
}

/*!
 * @Automated state change function
 *
 * @param plant Plant for which care is done
 * @return 50
 */
int GrowingState::handleCare(Plant* plant)
{
    // Example: auto-transition
    PlantState* newState = new MatureState();
    string oldState = plant->getState();
    plant->changeState(newState);
    cout<<"\nPlant changed from: "<<oldState<<" to "<<newState->getStateName()<<endl;
    
    return 50;
}

/*!
 * @return "Growing"
 */
string GrowingState::getStateName()
{
    return toUpperCase("growing");
}


//################################################

/*!
 * @brief Basic constructor for MatureState class
 */
MatureState::MatureState()
{
   // cout<<"\nMatureState: Created\n";
}

/*!
 * @Automated state change function
 *
 * @param plant Plant for which care is done
 * @return -75
 */
int MatureState::handleCare(Plant* plant)
{
    // Example: auto-transition
    PlantState* newState = new MoultState();
    string oldState = plant->getState();
    plant->changeState(newState);
    cout<<"\nPlant changed from: "<<oldState<<" to "<<newState->getStateName()<<endl;

    return -75;
}

/*!
 * @return "Mature"
 */
string MatureState::getStateName()
{
    return toUpperCase("mature");
}


//################################################

/*!
 * @brief Basic constructor for MoultState class
 */
MoultState::MoultState()
{
  // cout<<"\nMoultState: Created\n";
}

/*!
 * @Automated state change function
 *
 * @param plant Plant for which care is done
 * @return -25
 */
int MoultState::handleCare(Plant* plant)
{
    // Example: auto-transition
    PlantState* newState = new DeadState();
    string oldState = plant->getState();
    plant->changeState(newState);
    cout<<"\nPlant changed from: "<<oldState<<" to "<<newState->getStateName()<<endl;

    return -25;
}

/*!
 * @return "Moult"
 */
string MoultState::getStateName() {
    return toUpperCase("moult");
}


//###############################################


/*!
 * @Automated state change function
 *
 * @param plant Plant for which care is done
 * @return 0
 */
int DeadState::handleCare(Plant *plant)
{
    cout<<"\nDeadState: Plant is dead....\n";
    cout<<errorMessage("No state change occured");

    return 0;

}

/*!
 * @return "Dead"
 */
string DeadState::getStateName()
{
    return toUpperCase("dead");
}
