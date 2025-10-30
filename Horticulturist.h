#ifndef HORTICULTURIST_H
#define HORTICULTURIST_H

#include "libraries.h"
#include "Staff.h"
#include "Command.h"

class Horticulturist : public Staff
{
private:
    
public:
    Horticulturist(string _name);
    ~Horticulturist();
    void executeTask(Command* command) override;
    
    //void movePlantToInventory(Plant* plant);               // <--- template method (makes request,makes command,sends it off);
    string getActionForMove() override;
    string getDescriptionForMove() override;
};



#endif