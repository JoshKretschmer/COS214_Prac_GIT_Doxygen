#include <iostream>
#include "Plant.h"
#include "Inventory.h"
#include "Customer.h"
#include "Order.h"
#include "PriceBasedRecommendation.h"
#include "CategoryBasedRecommendation.h"
#include "NurseryMediator.h"
#include "Discussion.h"
#include "SystemState.h"
#include "CareTaker.h"

int main() {
    // ====== Create Inventory ======
    Inventory inventory;
    inventory.addPlant(Plant(1, "Rose", "Flower", 10.5));
    inventory.addPlant(Plant(2, "Aloe Vera", "Succulent", 15.0));
    inventory.addPlant(Plant(3, "Bonsai", "Tree", 50.0));
    inventory.addPlant(Plant(4, "Tulip", "Flower", 8.0));

    // ====== Create Customers ======
    Customer customer1(101, "Alice", "alice@example.com");
    Customer customer2(102, "Bob", "bob@example.com");

    // ====== Browse Plants ======
    std::cout << "===== Browsing Plants =====" << std::endl;
    customer1.browsePlants(&inventory);
    Plant recommendedPlant1 = customer1.requestRecommendation(&inventory);


    // ====== Recommendation Strategies ======
    PriceBasedRecommendation priceStrategy;
    CategoryBasedRecommendation categoryStrategy("Flower");

    customer1.setRecommendationStrategy(&priceStrategy);
    Plant recommendedPlant3 = customer1.requestRecommendation(&inventory);
    std::cout << "\nPrice-based recommendation: " << recommendedPlant3.getDetails() << std::endl;

    customer2.setRecommendationStrategy(&categoryStrategy);
    Plant recommendedPlant2 = customer2.requestRecommendation(&inventory);
    std::cout << "Category-based recommendation: " << recommendedPlant2.getDetails() << std::endl;

    // ====== Orders ======
    Order order1(201, &customer1);
    order1.addPlant(recommendedPlant1);
    order1.addPlant(recommendedPlant2);

    std::cout << "\nOrder total: $" << order1.calculateTotal() << std::endl;

    // ====== Mediator ======
    NurseryMediator mediator;
    mediator.registerCustomer(&customer1);
    mediator.registerCustomer(&customer2);

    mediator.placeOrder(&customer1, &order1);

    Discussion discussion("Plant Care Tips");
    discussion.addMessage("Alice: How often should I water a Bonsai?");
    discussion.addMessage("Bob: Once a week works best.");
    mediator.facilitateDiscussion(&customer1, &discussion);

    std::cout << "\nDiscussion Messages:" << std::endl;
    for (const auto& msg : discussion.getMessages()) {
        std::cout << msg << std::endl;
    }

    // ====== Memento ======
    SystemState system("Initial State");
    CareTaker caretaker;
    caretaker.addMemento(system.saveState());

    system.restoreState(caretaker.getMemento(0));
    std::cout << "\nRestored System State: " << system.getState() << std::endl;

    return 0;
}
