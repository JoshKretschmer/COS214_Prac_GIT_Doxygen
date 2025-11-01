#include "Request.h"
#include <iostream>
#include "Staff.h"
#include "Customer.h"

/*!
 * @brief Basic constructor function
 *
 * @param sender Object that created/sent the Request
 * @param receiver Staff member expected to receive and fulfil the Request
 */
Request::Request(Customer *sender, Staff *receiver) : sender(sender), receiver(receiver)
{
    std::cout << "Calling Request Constructor (sender="
              << (sender ? sender->getName() : "null")
              << ", receiver=" << (receiver ? receiver->getStaffName() : "null") << ")\n";
    plantID = "";
    type = "";
    plantType = "";
}

/*!
 * @brief Basic destructor function
 */
Request::~Request()
{
    std::cout << "Calling Request Deconstructor\n";
}

/*!
 *
 * @param _plantType Category/State of the Plant object to attach to the Request
 */
void Request::setPlantType(std::string _plantType)
{
    std::cout << "Calling Request::setPlantType(plantType=\"" << _plantType << "\")\n";
    plantType = _plantType;
    std::cout << "Request::setPlantType() set plantType to \"" << plantType << "\"\n";
}

/*!
 *
 * @return Category/State of the Plant object attached to the Request
 */
std::string Request::getPlantType()
{
    std::cout << "Calling Request::getPlantType() returning \"" << plantType << "\"\n";
    return plantType;
}

/*!
 *
 * @param _plantID Unique ID of the Plant to be attached to the Request
 */
void Request::setPlantID(std::string _plantID)
{
    std::cout << "Calling Request::setPlantID(plantID=\"" << _plantID << "\")\n";
    plantID = _plantID;
    std::cout << "Request::setPlantID() set plantID to \"" << plantID << "\"\n";
}

/*!
 *
 * @return Unique ID of the Plant object attached to the Request
 */
std::string Request::getPlantID()
{
    std::cout << "Calling Request::getPlantID() returning \"" << plantID << "\"\n";
    return plantID;
}

/*!
 *
 * @param _type type of the Plant to be attached to the Request
 */
void Request::setType(std::string _type)
{
    std::cout << "Calling Request::setType(type=\"" << _type << "\")\n";
    type = _type;
    std::cout << "Request::setType() set type to \"" << type << "\"\n";
}

/*!
 *
 * @return type of the Plant object attached to the Request
 */
std::string Request::getType()
{
    std::cout << "Calling Request::getType() returning \"" << type << "\"\n";
    return type;
}

/*!
 *
 * @param _sender Specifies the object that created the Request
 */
void Request::setSender(Customer *_sender)
{
    std::cout << "Calling Request::setSender(sender="
              << (_sender ? _sender->getName() : "null") << ")\n";
    sender = _sender;
    std::cout << "Request::setSender() set sender to "
              << (sender ? sender->getName() : "null") << "\n";
}

/*!
 *
 * @return the object that created the Request
 */
Customer *Request::getSender()
{
    std::cout << "Calling Request::getSender() returning "
              << (sender ? sender->getName() : "null") << "\n";
    return sender;
}

/*!
 *
 * @param _extra Additional information to be added to the request
 */
void Request::setExtra(std::string _extra)
{
    std::cout << "Calling Request::setExtra(extra=\"" << _extra << "\")\n";
    extra = _extra;
    std::cout << "Request::setExtra() set extra to \"" << extra << "\"\n";
}

/*!
 *
 * @return Additional information that has been added to the request
 */
std::string Request::getExtra()
{
    std::cout << "Calling Request::getExtra() returning \"" << extra << "\"\n";
    return extra;
}

/*!
 *
 * @param _receiver Specifies the object to which the request will be sent
 */
void Request::setReceiver(Staff *_receiver)
{
    std::cout << "Calling Request::setReceiver(receiver="
              << (_receiver ? _receiver->getStaffName() : "null") << ")\n";
    receiver = _receiver;
    std::cout << "Request::setReceiver() set receiver to "
              << (receiver ? receiver->getStaffName() : "null") << "\n";
}

/*!
 *
 * @return The object to which the request will be sent
 */
Staff *Request::getReceiver()
{
    std::cout << "Calling Request::getReceiver() returning "
              << (receiver ? receiver->getStaffName() : "null") << "\n";
    return receiver;
}