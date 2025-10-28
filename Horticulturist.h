#ifndef HORTICULTURIST_H
#define HORTICULTURIST_H

/*!
 * @headerfile Horticulturist.h
 */

#include "libraries.h"
#include "Staff.h"
#include "Command.h"

/*!
 * @class Horticulturist
 *
 * @brief Public child of the staff class
 *
 * Specific member of staff that exist to manage plant care, creation, and storage before maturity
 */
class Horticulturist : public Staff
{
private:
    
public:
    Horticulturist(string _name);
    ~Horticulturist();
    
    virtual void executeTask(Command* command) override;

    void movePlantToInventory(Plant* plant);               // <--- template method (makes reuqest,makes command,sends it off);
};



#endif