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
    
    virtual void executeTask(Command* command) override;

    void movePlantToInventory(Plant* plant);               // <--- template method (makes reuqest,makes command,sends it off);
};



#endif