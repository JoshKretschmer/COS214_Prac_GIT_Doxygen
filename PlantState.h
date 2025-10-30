#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include <string>
using namespace std;

/*!
 * @brief Forward declaration for Plant class to avoid circular dependency
 */
class Plant;

/*!
 * @class PlantState
 *
 * @brief Abstract parent class for concrete state classes
 */

class PlantState {
public:
    PlantState();
    virtual ~PlantState();
    void virtual handleCare(Plant* plant)=0;
    string virtual getStateName()=0;
};

#endif //PLANTSTATE_H
