#include "libraries.h"
#include "Customer.h"
#include "Staff.h"

int main(int argc, char const *argv[])
{
    InventoryClerk* _clerk = new InventoryClerk("CLERK1","John Doe",NULL,NULL); //Who is the nexthanlder if this is the first staff?
    SalesAssociate* _salesPerson = new SalesAssociate("SALES1", "Tam Doe",NULL,NULL);

    _clerk->setNextHandler(_salesPerson);
    // _salesPerson->setNextHandler(_clerk)  <---- causes infinite loop if none can hanle the request.

    Customer* me = new Customer("David","CUST001",_clerk,_salesPerson);

    me->browsePlants();
    return 0;
}
