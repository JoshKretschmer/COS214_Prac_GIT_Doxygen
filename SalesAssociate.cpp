#include "SalesAssociate.h"
#include "Customer.h"
#include "Command.h"
#include "Request.h"

/*!
 * @brief Basic constructor
 *
 * @param _name name of Staff member
 */
SalesAssociate::SalesAssociate( std::string _name) : Staff(_name)
{
    staffType = "SalesAssociate";
}

/*!
 * @brief Basic destructor for sales associate
 */
SalesAssociate::~SalesAssociate(){
}


void SalesAssociate::executeTask(Command *command)
{
    if (command->getRequest()->getType() != "sales") {
        // Forward to next handler if not a sales command
        forwardCommand(command);
        return;
    }
    command->getRequest()->setReceiver(this);
    Request* request = command->execute();
    //need command to be written first
    //execute purchase command
    //request plant from inventory clerk (next handler)
    //send plant back to Customer
}