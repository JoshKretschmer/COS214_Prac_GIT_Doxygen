#include "Plant.h"
#include "PlantState.h"
#include "PlantCare.h"
#include "Observer.h"
#include "Command.h"
#include "Staff.h"
#include "Order.h"
#include <iostream>

using namespace std;

// ##########################################
// Concrete Observer: Staff performing care
class DemoStaff : public Staff {
private:
    string name;
    PlantCare* careStrategy;
public:
    DemoStaff(const string& n, PlantCare* strategy) : name(n), careStrategy(strategy) {}
    ~DemoStaff() { delete careStrategy; }

    void update(Subject& subject) override {
        Plant* plant = dynamic_cast<Plant*>(&subject);
        if (plant) {
            cout << "\n[Observer] Staff " << name << " notified of plant state: " << plant->getDetails() << endl;
            // Execute care via strategy
            careStrategy->executeCare();
            CareCommand cmd;
            cmd.execute();
        }
    }
};

// ##########################################
// Demo
int main() {
    cout << "--- Plant + Staff + Memento Demo ---\n";

    // Create plants
    Plant* cactus = new PeanutCactus();
    cactus->changeState(new SeedingState());

    Plant* orchid = new Orchid();
    orchid->changeState(new SeedingState());

    //Create staff observers
    DemoStaff* alice = new DemoStaff("Alice", new WateringStrategy());
    DemoStaff* bob = new DemoStaff("Bob", new CompositeCareStrategy());

    cactus->attach(alice);
    cactus->attach(bob);
    orchid->attach(bob); // Bob handles multiple plants

    //Create order
    Order* order = new Order();

    cout << "\n--- Adding plants to order ---\n";
    order->addPlant(cactus);
    cout << order->getDetails() << endl;

    order->addPlant(orchid);
    cout << order->getDetails() << endl;

    //Simulate plant lifecycle
    cout << "\n--- Plant needs care ---\n";
    cactus->needsCare(); // Seeding -> Growing
    orchid->needsCare(); // Seeding -> Growing

    cout << "\n--- Plant needs care again ---\n";
    cactus->needsCare(); // Growing -> Mature
    orchid->needsCare(); // Growing -> Mature

    cout << "\n--- Final Order Details ---\n";
    cout << order->getDetails() << endl;

    //Undo last addition
    order->undoLastAddition();


    std::cout << "After undo:\n" << order->getDetails() << "\n";

    //Cleanup
    delete cactus;
    delete orchid;
    delete alice;
    delete bob;
    delete order;

    return 0;
}
