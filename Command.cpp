#include "Command.h"

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
    return (_staffType == access);
}

