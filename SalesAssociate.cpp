#include "SalesAssociate.h"
#include "Customer.h"

/*!
 * @brief Basic constructor
 *
 * @param _name name of Staff member
 */
SalesAssociate::SalesAssociate(string _name, Staff* clerk) : Staff(_name)
{
    staffType = "SalesAssociate";
    this->setNextHandler(clerk);
}

/*!
 * @brief Basic destructor for sales associate
 */
SalesAssociate::~SalesAssociate(){
}

/*!
 * @brief executes the specified Command object
 *
 * Command is from the client to get a Plant from the InventoryClerk for purchase
 *
 * @param command Command object containing the Request to be run
 */
void SalesAssociate::executeTask(Command *command)
{
    //need command to be written first
    //execute purchase command
    //request plant from inventory clerk (next handler)
    //send plant back to Customer
}