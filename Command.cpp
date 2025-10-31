#include "Command.h"

Command::Command(Request *_request)
{
    request = _request;
}

Command::~Command()
{
}

bool Command::hasAccess(string _staffType)
{
    return (_staffType == access);
}

SalesCommand::SalesCommand(Request *_request) : Command(_request)
{
    access = "sales";
}

SalesCommand::~SalesCommand()
{
}

Request* SalesCommand::execute()
{
    Customer* customer = request->getSender();
    //all I want to do is add the plant to the customer's current order
    string plantID = request->getPlantID();
    string decor = request->getExtra();
    customer->addPlant(plantID, decor); //note that we need to add functionality to this
    std::cout << request->getReceiver() << " has added " << plantID << " to your order.\n";
}

InventoryCommand::InventoryCommand(Request *_request) : Command(_request)
{
    access = "inventoryclerk";
}

InventoryCommand::~InventoryCommand()
{
}

Request* InventoryCommand::execute()
{
    //now I simply want to print the information of the plant
    //how do I navigate the inventory from here?
    Staff* receiver = request->getReceiver();
    InventoryClerk* clerk = dynamic_cast<InventoryClerk*>(receiver);
    Plant* plant = clerk->getPlant(request->getPlantID());
    if (plant != nullptr){
        std::cout << plant->getDetails() << std::endl;
    }else{
        std::cout << "Plant not found in inventory." << std::endl;
    }
}

ManagerCommand::ManagerCommand(Request *_request) : Command(_request)
{
    access = "manager";
}

ManagerCommand::~ManagerCommand()
{
}

Request* ManagerCommand::execute()
{
    // I am not sure what I can do hree
    std::cout << "We have informed our manager about your request, we will hopefully be able to help out soon." << std::endl;
}

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
}

