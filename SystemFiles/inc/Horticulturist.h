#ifndef HORTICULTURIST_H
#define HORTICULTURIST_H

#include "Staff.h"
#include "Command.h"

/*!
 * @class Horticulturist
 *
 * @brief public Staff class responsible for the growing(creation), monitoring, care, and management of Plant objects
 */
class Horticulturist : public Staff
{
private:
    
public:
    Horticulturist(std::string _name);
    ~Horticulturist();
    void executeTask(Command* command) override;
    
    //void movePlantToInventory(Plant* plant);               // <--- template method (makes request,makes command,sends it off);
    std::string getActionForMove() override;
    std::string getDescriptionForMove() override;
};

#endif