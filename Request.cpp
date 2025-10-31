#include "Request.h"

/*!
 * @brief Basic constructor function
 *
 * @param sender Object that created/sent the Request
 * @param receiver Staff member expected to receive and fulfil the Request
 */
Request::Request(Customer* sender, Staff* receiver) : sender(sender), receiver(receiver)
{
    plantID = "";
    type = "";
    plantType = "";
    sender = nullptr;
}

/*!
 * @brief Basic destructor function
 */
Request::~Request()
{
}

/*!
 *
 * @param _plantType Category/State of the Plant object to attach to the Request
 */
void Request::setPlantType(std::string _plantType)
{
    plantType = _plantType;
}

/*!
 *
 * @return Category/State of the Plant object attached to the Request
 */
std::string Request::getPlantType()
{
    return plantType;
}

/*!
 *
 * @param _plantID Unique ID of the Plant to be attached to the Request
 */
void Request::setPlantID(std::string _plantID)
{
    plantID = _plantID;
}

/*!
 *
 * @return Unique ID of the Plant object attached to the Request
 */
std::string Request::getPlantID()
{
    return plantID;
}

/*!
 *
 * @param _type type of the Plant to be attached to the Request
 */
void Request::setType(std::string _type)
{
    type = _type;
}

/*!
 *
 * @return type of the Plant object attached to the Request
 */
std::string Request::getType()
{
    return type;
}

/*!
 *
 * @param _sender Specifies the object that created the Request
 */
void Request::setSender(Customer* _sender)
{
    sender = _sender;
}

/*!
 *
 * @return the object that created the Request
 */
Customer* Request::getSender()
{
    return sender;
}

/*!
 *
 * @param _extra Additional information to be added to the request
 */
void Request::setExtra(std::string _extra)
{
    extra = _extra;
}

/*!
 *
 * @return Additional information that has been added to the request
 */
std::string Request::getExtra()
{
    return extra;
}

/*!
 *
 * @param _receiver Specifies the object to which the request will be sent
 */
void Request::setReceiver(Staff* _receiver)
{
    receiver = _receiver;
}

/*!
 *
 * @return The object to which the request will be sent
 */
Staff* Request::getReceiver()
{
    return receiver;
}