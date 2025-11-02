#include <iostream>
#include <string>
#include <limits>
#include "../inc/CreateSucculent.h"
#include "../inc/CreateFlower.h"
#include "../inc/CreateShrub.h"
#include "../inc/Inventory.h"
#include "../inc/PlantGroup.h"
#include "../inc/Plant.h"
#include "../inc/PlantCare.h"
#include "../inc/PotDecorator.h"
#include "../inc/WrapDecorator.h"
#include "../inc/ArrangementDecorator.h"
#include "../inc/Request.h"
#include "../inc/Customer.h"
#include "../inc/Staff.h"
#include "../inc/InventoryClerk.h"
#include "../inc/Horticulturist.h"
#include "../inc/Manager.h"
#include "../inc/InventoryCommand.h"
#include "../inc/GreenHouseCommand.h"
#include "../inc/ManagerCommand.h"
#include "../inc/SalesCommand.h"
#include "../inc/SalesAssociate.h"
#include "../inc/Order.h"
#include "../inc/PaymentSystem.h"
#include "../inc/PurchaseFacade.h"

// helper function to clear input buffer
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// helper function to display the main menu
void displayMenu()
{
    std::cout << "\n=== Plant Nursery Demo ===\n";
    std::cout << "1. Browse Plants\n";
    std::cout << "2. Create Custom Order\n";
    std::cout << "3. View Inventory\n";
    std::cout << "4. Process Staff Request\n";
    std::cout << "5. Undo Last Order Action\n";
    std::cout << "6. Redo Last Order Action\n";
    std::cout << "7. Complete Purchase\n";
    std::cout << "8. Exit\n";
    std::cout << "Enter your choice (1-8): ";
}

// helper function to create a plant based on user input
Plant *createPlant()
{
    std::cout << "\nSelect plant type:\n";
    std::cout << "1. Succulent\n2. Flower\n3. Shrub\n";
    int typeChoice;
    std::cin >> typeChoice;
    clearInputBuffer();

    std::string plantName;
    Plant *plant = nullptr;

    if (typeChoice == 1)
    {
        CreateSucculent factory;
        std::cout << "Enter succulent name (PeanutCactus, HouseLeek): ";
        std::getline(std::cin, plantName);
        plant = factory.createPlant(plantName);
    }
    else if (typeChoice == 2)
    {
        CreateFlower factory;
        std::cout << "Enter flower name (Orchid): ";
        std::getline(std::cin, plantName);
        plant = factory.createPlant(plantName);
    }
    else if (typeChoice == 3)
    {
        CreateShrub factory;
        std::cout << "Enter shrub name (HoneySuckle, BeeBlossom): ";
        std::getline(std::cin, plantName);
        plant = factory.createPlant(plantName);
    }
    else
    {
        std::cout << "Invalid plant type.\n";
        return nullptr;
    }

    if (!plant)
    {
        std::cout << "Failed to create plant. Invalid name.\n";
    }
    return plant;
}

// helper function to add customization to a plant
Plant *customizePlant(Plant *plant)
{
    if (!plant)
        return nullptr;

    std::cout << "\nAdd customizations to " << plant->getDetails() << ":\n";
    std::cout << "1. Pot\n2. Wrap\n3. Arrangement\n4. Done\n";

    Plant *current = plant;
    int choice;
    do
    {
        std::cout << "Enter customization choice (1-4): ";
        std::cin >> choice;
        clearInputBuffer();

        if (choice == 1)
        {
            PotDecorator *pot = new PotDecorator();
            pot->setWrapped(current);
            current = pot;
            std::cout << "Added Pot. New details: " << current->getDetails() << ", Cost: $" << current->getCost() << "\n";
        }
        else if (choice == 2)
        {
            WrapDecorator *wrap = new WrapDecorator();
            wrap->setWrapped(current);
            current = wrap;
            std::cout << "Added Wrap. New details: " << current->getDetails() << ", Cost: $" << current->getCost() << "\n";
        }
        else if (choice == 3)
        {
            ArrangementDecorator *arr = new ArrangementDecorator();
            arr->setWrapped(current);
            current = arr;
            std::cout << "Added Arrangement. New details: " << current->getDetails() << ", Cost: $" << current->getCost() << "\n";
        }
        else if (choice != 4)
        {
            std::cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return current;
}

int main()
{
    std::cout << "Welcome to the Plant Nursery Demo\n";

    // initialize system components
    Inventory inventory;
    PaymentSystem paymentSystem;
    SalesAssociate sales("Alice");
    InventoryClerk clerk("Bob");
    Horticulturist horti("Charlie");
    Manager manager("Dave");
    sales.setNextHandler(&clerk);
    clerk.setNextHandler(&horti);
    horti.setNextHandler(&manager);
    clerk.assignJob(&inventory);
    Customer customer("Eve", "CUST001", &sales);
    PurchaseFacade facade(&inventory, &paymentSystem);
    Order *currentOrder = nullptr;

    // seed inventory with some plants
    CreateSucculent succulentFactory;
    CreateFlower flowerFactory;
    CreateShrub shrubFactory;
    inventory.addPlant(succulentFactory.createPlant("PeanutCactus"));
    inventory.addPlant(succulentFactory.createPlant("HouseLeek"));
    inventory.addPlant(flowerFactory.createPlant("Orchid"));
    inventory.addPlant(shrubFactory.createPlant("HoneySuckle"));

    int choice;
    do
    {
        displayMenu();
        std::cin >> choice;
        clearInputBuffer();

        switch (choice)
        {
        case 1:
        { 
            // * Browse Plants
            std::cout << "\nCurrent Inventory:\n";
            InventoryIterator *it = inventory.createIterator();
            for (it->first(); it->hasNext(); it->next())
            {
                Plant *p = it->currentItem();
                if (p)
                {
                    std::cout << "  -> " << p->getDetails()
                              << " | State: " << p->getState()
                              << " | Cost: $" << p->getCost() << "\n";
                }
            }
            delete it;
            break;
        }
        case 2:
        { 
            // * Create Custom Order
            if (!currentOrder)
            {
                Plant *plant = createPlant();
                if (plant)
                {
                    currentOrder = facade.initiatePurchase(&customer, plant);
                    std::cout << "Order created for " << plant->getDetails() << "\n";
                }
            }
            Plant *customizedPlant = createPlant();
            if (customizedPlant)
            {
                customizedPlant = customizePlant(customizedPlant);
                facade.addPlantToOrder(currentOrder, customizedPlant);
                std::cout << "Added to order: " << customizedPlant->getDetails() << ", Cost: $" << customizedPlant->getCost() << "\n";
            }
            break;
        }
        case 3:
        { 
            // * View Inventory
            std::cout << "\nInventory Details:\n";
            std::vector<Plant *> plants = inventory.getPlants();
            std::cout << "Total plants: " << plants.size() << "\n";
            for (Plant *p : plants)
            {
                std::cout << "  -> " << p->getDetails() << ", Cost: $" << p->getCost() << "\n";
            }
            break;
        }
        case 4:
        { 
            // * Process Staff Request
            std::cout << "\nSelect request type:\n";
            std::cout << "1. Sales\n2. Inventory\n3. Greenhouse\n4. Manager\n";
            int reqType;
            std::cin >> reqType;
            clearInputBuffer();

            std::string type;
            if (reqType == 1)
                type = "sales";
            else if (reqType == 2)
                type = "inventory";
            else if (reqType == 3)
                type = "greenhouse";
            else if (reqType == 4)
                type = "manager";
            else
            {
                std::cout << "Invalid request type.\n";
                break;
            }

            std::string plantID;
            std::cout << "Enter plant ID (e.g., PC001): ";
            std::getline(std::cin, plantID);

            Request *req = customer.makeRequest(type, plantID, type == "sales" ? "Pot" : "");
            if (type == "sales")
            {
                SalesCommand cmd(req);
                sales.handleCommand(&cmd);
            }
            else if (type == "inventory")
            {
                InventoryCommand cmd(req);
                sales.handleCommand(&cmd);
            }
            else if (type == "greenhouse")
            {
                GreenHouseCommand cmd(req);
                sales.handleCommand(&cmd);
            }
            else if (type == "manager")
            {
                ManagerCommand cmd(req);
                sales.handleCommand(&cmd);
            }
            delete req;
            break;
        }
        case 5:
        {
            // * Undo Last Order Action
            if (currentOrder)
            {
                facade.undoLastStep(currentOrder);
                std::cout << "Undone last action. Current order:\n";
                currentOrder->printOrder();
            }
            else
            {
                std::cout << "No order to undo.\n";
            }
            break;
        }
        case 6:
        {
            // * Redo Last Order Action
            if (currentOrder)
            {
                facade.redoStep(currentOrder);
                std::cout << "Redone last action. Current order:\n";
                currentOrder->printOrder();
            }
            else
            {
                std::cout << "No order to redo.\n";
            }
            break;
        }
        case 7:
        {
            // * Complete Purchase
            if (currentOrder)
            {
                facade.completePurchase(currentOrder);
                std::cout << "Purchase completed\n";
                delete currentOrder;
                currentOrder = nullptr;
            }
            else
            {
                std::cout << "No order to complete.\n";
            }
            break;
        }
        case 8:
        { 
            // exit
            std::cout << "Thank you for visiting the Plant Nursery\n";
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    // cleanup
    if (currentOrder)
    {
        delete currentOrder;
    }

    return 0;
}