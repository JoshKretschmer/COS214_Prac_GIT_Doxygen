#include "Customer.h"
#include "PlantDecorator.h"

/*!
 * @brief Basic constructor for customer object
 */
Customer::Customer(string _name,string _id, Staff* _salesPerson)
{
    salesPerson = _salesPerson;
    name = _name;
    id = _id;
    startPurchase();
}

/*!
 * @brief Basic destructor for customer object
 */
Customer::~Customer()
{
    // no memory management required
}

Request *Customer::makeRequest(string type, string details, string action)
{
    //used to create request
    //need to be redone once request is set up
}

/*!
 * @brief Create a request to get Information from Plants in Inventory
 */
void Customer::browsePlants()
{
    //inventory request
    //get Plant info from inventory clerk

    //print out plant info
}

/*!
 * @brief Creates an Order object for the customer to make a purchase on
 */
void Customer::startPurchase()
{
    currentOrder = new Order();
}

void Customer::addPlant(string plantID, string decor) {
    if (!currentOrder) {
        cout << "Start a purchase first" << endl;
        return;
    }
   
    //create purchase request
    //this goes thru sales associate
    //get plant object from inventory

    //if statement to customize
        //customizeOrder();

    //this->currentOrder->addPlant(...);

    //create new memento
    
}

/*!
 * @brief Decorate a specified Plant object before adding it to an order
 *
 * @param plant Plant object to be decorated
 * @param decor Decoration to be added to the plant
 * @return Decorated Plant or basic Plant
 */
Plant* Customer::customizeOrder(Plant* plant, string decor){

    if (decor == "Arrange") {
        ArrangementDecorator* newD = new ArrangementDecorator();
        newD->setWrapped(plant);
        return newD;
    } else if (decor == "Pot") {
        PotDecorator* newD = new PotDecorator();
        newD->setWrapped(plant);
        return newD;
    } else if (decor == "Wrap") {
        WrapDecorator* newD = new WrapDecorator();
        newD->setWrapped(plant);
        return newD;
    } else {
        cerr << "Error in Customer::customizeOrder()" << endl;
        return plant;
    }
}

/*!
 * @brief Undo the last action, i.e. remove the last plant added to the Order
 */
void Customer::undoAction()
{
    currentOrder->undoLastAddition();
}


void Customer::confirmPurchase()
{

}
