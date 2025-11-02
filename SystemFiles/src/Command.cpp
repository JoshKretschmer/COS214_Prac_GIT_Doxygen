#include "../inc/Command.h"
#include <iostream>
#include "../inc/Request.h"

/*!
 * @brief Basic constructor function
 *
 * @param _request Request object to be contained
 */
Command::Command(Request *_request)
{
    request = _request;
}

/*!
 * @brief Basic destructor function
 */
Command::~Command()
{
}

/*!
 *
 * @param _staffType Staff object trying to access the Request inside Command
 * @return True if the Staff object has access rights, false otherwise
 */
bool Command::hasAccess(std::string _staffType)
{
    bool result = (_staffType == access);
    return result;
}