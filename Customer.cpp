#include "Customer.h"

/*!
 * @brief Basic constructor for customer object
 */
Customer::Customer(string _name,string _id,InventoryClerk* _clerk, Staff* _salesPerson)
{
    salesPerson = _salesPerson; //will need to reconfigure and add some functions to salesPerson 
    name = _name;
    id = _id;
}

/*!
 * @brief Basic destructor for customer object
 */
Customer::~Customer()
{
    // no memeory management required
}

/*!
 *
 * @param type type of request to be made
 * @param details details added to the request
 * @param action action to be executed by the request
 * @return The Request object that has been created
 */
Request *Customer::makeRequest(string type, string details, string action)
{
    Request *request;
    enum class RequestType
    {
        SALES = 1,
        CARE = 2,
        PURCHASE = 3,
        INVENTORY = 4,
        GENERAL = 5
    };

    RequestType requestType = RequestType::GENERAL;

    if (type == "Sales")
    {
        requestType = RequestType::SALES;
    }
    else if (type == "Care")
    {
        requestType = RequestType::CARE;
    }
    else if (type == "Purchase")
    {
        requestType = RequestType::PURCHASE;
    }
    else if (type == "Inventory")
    {
        requestType = RequestType::INVENTORY;
    }

    switch (requestType)
    {
    case RequestType::SALES:
        request = new Request();
        break;

    case RequestType::CARE:
        request = new Request();
        break;

    case RequestType::PURCHASE:
        request = new Request();
        break;

    case RequestType::INVENTORY:
        request = new Request();

    default:
        request = new Request(); // this is for GENERAL
        break;
    }

    return request;
}

/*!
 * @brief Allow the customer to view available Palnt objects
 */
void Customer::browsePlants()
{
    
}

/*!
 * @brief Creates an Order object for the customer to make a purchase
 */
void Customer::startPurchase()
{

}

/*!
 * @brief Allows the customer to customize the order they have made
 */
void Customer::customizeOrder()
{
    cout<<"\n What would you like to add? \n"
        <<"\t...POT...\n"
        <<"1- POT1 Cost R20.00\n"
        <<"2- POT2 Cost R20.00\n\n"
        <<"\t...ARRANGEMENT...\n"
        <<"3- ARRANGEMENT1 Cost R10.00\n"
        <<"4- ARRANGEMENT2 Cost R10.00\n\n"
        <<"\t...WRAP...\n"
        <<"6- WRAP1 Cost R15.00\n"
        <<"7- WRAP2 Cost R15.00\n\n"
        <<"CHOICE:(number only): ";
    
        int option;
        cin>>option;

}

/*!
 * @brief undo the last customization action
 */
void Customer::undoCustomization()
{
}

/*!
 * @brief Complete a purchase tasks and remove all purchased plants from system
 */
void Customer::confirmPurchase()
{
}
