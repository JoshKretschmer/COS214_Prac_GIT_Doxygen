#include "GreenHouseCommand.h"
#include "Request.h"
#include <iostream>

/*!
 * @brief Basic constructor function
 *
 * @param _request Request object to be contained
 */
GreenHouseCommand::GreenHouseCommand(Request *_request) : Command(_request)
{
    std::cout << "Calling GreenHouseCommand Constructor (request="
              << (_request ? _request->getPlantID() : "null") << ")\n";
    access = "greenhouse";
}

/*!
 * @brief Basic destructor function
 */
GreenHouseCommand::~GreenHouseCommand()
{
    std::cout << "Calling GreenHouseCommand Deconstructor\n";
}

/*!
 * @brief Executes the Request inside Command (nurturing Plant)
 *
 * @return nullptr
 */
Request *GreenHouseCommand::execute()
{
    std::cout << "Calling GreenHouseCommand::execute()\n";

    Staff *receiver = request->getReceiver();
    Horticulturist *horticulturist = dynamic_cast<Horticulturist *>(receiver);

    std::cout << (horticulturist ? horticulturist->getStaffName() : "null")
              << " is now tending to: " << request->getPlantID() << "\n";

    return nullptr;
}