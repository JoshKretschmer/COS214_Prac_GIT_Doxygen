#include "Manager.h"
#include "Command.h"
#include "Request.h"
#include <iostream>

/*!
     * @brief Constructor for Manager
     *
     * @param _name Name of the manager
 */
Manager::Manager(std::string _name) : Staff(_name) {
    staffType = "manager";
}

/*!
     * @brief Destructor for Manager
 */
Manager::~Manager() = default;

/*!
     * @brief Executes the command if this staff can handle it
     *
     * @param command The command to execute
*/
void Manager::executeTask(Command* command) {
    Request* req = command->getRequest();
    
    // Manager handles ANY request that reaches it
    req->setReceiver(this);

    std::cout << "Manager " << staffName << " is now handling the request: ";
    std::cout << "Type='" << req->getType() << "', PlantID='" << req->getPlantID() << "'\n";

    Request* result = command->execute();

    if (result == nullptr) {
        std::cout << "Manager has processed the request.\n";
    }
}