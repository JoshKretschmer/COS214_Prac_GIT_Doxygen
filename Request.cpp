#include "Request.h"

int Request::instanceCount = 1;

/*!
 * @brief Basic constructor function
 */
Request::Request()
{
    id = "REQUEST" + to_string(instanceCount);
    description = "";
    action = "";
    sender = NULL;
    plantObject = NULL;
    instanceCount++;
}

/*!
 * @brief Basic destructor function
 */
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

/*!
 *
 * @param _description value to set description attribute
 */
void Request::setDescription(string _description)
{
    description = _description;
}

/*!
 *
 * @param _action value to set action attribute
 */
void Request::setAction(string _action)
{
    action = _action;
}

/*!
 *
 * @param _sender value to set sender attribute
 */
void Request::setSender(Staff* _sender)
{
    if(_sender)
    {
        sender = _sender;
    }
    else
    {
        cout<<errorMessage("Sender is a NULL object...");
    }
}

/*!
 *
 * @param _plantObject value to set Plant object
 */
void Request::setPlantObject( Plant* _plantObject)
{
    if(_plantObject)
    {
        plantObject = _plantObject;
    }
    else
    {
        cout<<errorMessage("Plant is a NULL object");
    }
}

/*!
 *
 * @return request details as a formatted string
 */
string Request::getDetails()
{
    string details = "";

    details += "REQUEST ID: "+id + "\n"
             + "REQUEST ACTION: "+action + "\n"
             + "REQUEST DESCRIPTION: "+description + "\n";

    return details;
}