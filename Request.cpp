#include "Request.h"

Request::Request(Customer* sender, Staff* receiver) : sender(sender), receiver(receiver)
{
    plantID = "";
    type = "";
    plantType = "";
    sender = nullptr;
}

Request::~Request()
{
}

void Request::setPlantType(std::string _plantType)
{
    plantType = _plantType;
}

std::string Request::getPlantType()
{
    return plantType;
}

void Request::setPlantID(std::string _plantID)
{
    plantID = _plantID;
}

std::string Request::getPlantID()
{
    return plantID;
}

void Request::setType(std::string _type)
{
    type = _type;
}

std::string Request::getType()
{
    return type;
}

void Request::setSender(Customer* _sender)
{
    sender = _sender;
}

Customer* Request::getSender()
{
    return sender;
}

void Request::setExtra(std::string _extra)
{
    extra = _extra;
}

std::string Request::getExtra()
{
    return extra;
}

void Request::setReceiver(Staff* _receiver)
{
    receiver = _receiver;
}

Staff* Request::getReceiver()
{
    return receiver;
}