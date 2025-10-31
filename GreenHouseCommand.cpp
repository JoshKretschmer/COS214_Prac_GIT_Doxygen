#include "GreenHouseCommand.h"

GreenHouseCommand::GreenHouseCommand(Request *_request) : Command(_request)
{
    access = "greenhouse";
}

GreenHouseCommand::~GreenHouseCommand()
{
}

Request* GreenHouseCommand::execute()
{
    Staff* receiver = request->getReceiver();
    Horticulturist* horticulturist = dynamic_cast<Horticulturist*>(receiver);
    std::cout << horticulturist->getStaffName() << " is now tending to: " << request->getPlantID() << endl;


    //we have the horticulturist, now we need to perform whatever action with him
    return nullptr;
}