#include "SalesCommand.h"

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