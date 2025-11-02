#ifndef CUSTOMER_H
#define CUSTOMER_H

/*!
 * @headerfile Customer.h
 */

#include <string>
#include <vector>
class Order;
class Staff;
class Request;
class Plant;

/*!
 * @class Customer
 *
 * @brief Class for objects that execute the purchasing and decoration process on plants
 *
 * Makes request to Staff object to execute processes
 */
class Customer
{
private:
    std::string id;
    std::string name;
    Order *currentOrder;
    Staff *salesPerson;

public:
    Customer(std::string name, std::string id, Staff *_salesPerson);
    ~Customer();
    Request *makeRequest(std::string type, std::string plantID, std::string extra);
    void browsePlants();
    void startPurchase();
    void addPlant(std::string plantID, std::string decor);
    Plant *customizeOrder(Plant *plant, std::string decor);
    void undoAction();
    void confirmPurchase();

    std::string getName() const { return name; }
    std::string getID() const { return id; }
};

#endif // CUSTOMER_H