#include "GreenHouseCommand.h"
#include "Request.h"

/*!
 * @brief Basic constructor function
 *
 * @param _request Request object to be contained
 */
GreenHouseCommand::GreenHouseCommand(Request *_request) : Command(_request)
{
    access = "greenhouse";
}

/*!
 * @brief Basic destructor function
 */
GreenHouseCommand::~GreenHouseCommand()
{
}

/*!
 * @brief Executes the Request inside Command (nurturing Plant)
 *
 * @return nullptr
 */
Request* GreenHouseCommand::execute()
{
    Staff* receiver = request->getReceiver();
    Horticulturist* horticulturist = dynamic_cast<Horticulturist*>(receiver);
    std::cout << horticulturist->getStaffName() << " is now tending to: " << request->getPlantID() << endl;


    //we have the horticulturist, now we need to perform whatever action with him
    return nullptr;
}