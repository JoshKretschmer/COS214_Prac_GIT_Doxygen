#ifndef PLANTCARE_H
#define PLANTCARE_H

#include <string>

class Plant;

/*!
 * @class PlantCare
 *
 * @brief Abstract parent class for various plant care strategies
 */
class PlantCare {
public:
    PlantCare();
    virtual ~PlantCare() = default;
    virtual bool executeCare() = 0;
    virtual std::string getCareType() = 0;
    virtual PlantCare *clone() const = 0;
};

#endif // PLANTCARE_H
