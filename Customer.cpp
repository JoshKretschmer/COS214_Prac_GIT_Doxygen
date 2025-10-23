#include "Customer.h"

Customer::Customer(string _name,string _id,InventoryClerk* _clerk, SalesAssociate* _salesPerson)
{
    clerk = _clerk;
    salesPerson = _salesPerson; //will need to reconfigure and add some functions to salesPerson 
    name = _name;
    id = _id;
}

Customer::~Customer()
{
    // no memeory management required
}

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

    if (type == "Sales" || type == "SALES")
    {
        RequestType requestType = RequestType::SALES;
    }
    else if (type == "Care" || type == "CARE")
    {
        RequestType requestType = RequestType::CARE;
    }
    else if (type == "Purchase" || type == "PURCHASE")
    {
        RequestType requestType = RequestType::PURCHASE;
    }
    else if (type == "Inventory" || type == "INVENTORY")
    {
        RequestType requestType = RequestType::INVENTORY;
    }

    switch (requestType)
    {
    case RequestType::SALES:
        request = new Request(type, details, action);
        break;

    case RequestType::CARE:
        request = new Request(type, details, action);
        break;

    case RequestType::PURCHASE:
        request = new Request(type, details, action);
        break;

    case RequestType::INVENTORY:
        request = new Request(type, details, action);

    default:
        request = new Request(type, details, action); // this is for GENERAL
        break;
    }

    return request;
}

void Customer::browsePlants()
{
    cout<<clerk->getAvailablePlants();
}

void Customer::startPurchase()
{
    
}

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

void Customer::undoCustomization()
{
}

void Customer::confirmPurchase()
{
}
