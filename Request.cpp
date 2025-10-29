#include "Request.h"

int Request::instanceCount = 1;

Request::Request()
{
    id = "REQUEST" + to_string(instanceCount);
    description = "";
    action = "";
    sender = NULL;
    plantObject = NULL;
    instanceCount++;
}

Request::~Request()
{
    // zero memory management ! remember we passing the pointers!
    if(sender)
    {
        sender = NULL;
    }

    if(plantObject)
    {
        plantObject = NULL;
    }

    instanceCount--;
}

void Request::setDescription(string _description)
{
    description = _description;
}

void Request::setAction(string _action)
{
    action = _action;
}

void Request::setSender(Staff* _sender)
{
    if(_sender)
    {
        sender = _sender;
    }
    else
    {
        cerr<<"Sender is a NULL object...";
    }
}

void Request::setPlantObject( Plant* _plantObject)
{
    if(_plantObject)
    {
        plantObject = _plantObject;
    }
    else
    {
        cerr<<"Plant is a NULL object";
    }
}

string Request::getDetails()
{
    string details = "";

    details += "REQUEST ID: "+id + "\n"
             + "REQUEST ACTION: "+action + "\n"
             + "REQUEST DESCRIPTION: "+description + "\n";

    return details;
}