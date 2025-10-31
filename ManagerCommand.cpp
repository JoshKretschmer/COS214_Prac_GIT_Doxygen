#include "ManagerCommand.h"

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