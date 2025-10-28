#include "libraries.h"
#include "Staff.h"
#include "SimulationTime.h"
#include "PlantFactory.h"
#include "PlantDecorator.h"
#include "Request.h"
#include "Horticulturist.h"
#include "Inventory.h"
#include "InventoryClerk.h"

void plant_test()
{
     Plant *p1 = new Marigold();
     string info = "\n";

     cout << p1->getDetails() << "\n";

     info += p1->getPlantID() + "\n" + p1->getPlantGroup() + "\n" + p1->getPlantType() + "\n" + to_string(p1->getCost()) + "\n" + to_string(p1->getPlantHealth()) + "\n" + p1->getState() + "\n" + p1->getCareRegime();

     cout << info;
}

void plantFactory_test()
{
     PlantFactory *flower = new CreateFlower();
     PlantFactory *shrub = new CreateShrub();
     PlantFactory *succulent = new CreateSucculent();

     Plant *p1 = flower->createPlant("orchid");
     Plant *p2 = flower->createPlant("marigold");
     Plant *p3 = shrub->createPlant("honeysuckle");
     Plant *p4 = shrub->createPlant("beeblossom");
     Plant *p5 = succulent->createPlant("houseleek");
     Plant *p6 = succulent->createPlant("peanutcactus");

     cout << p1->getDetails() << p2->getDetails() << p3->getDetails() << p4->getDetails() << p5->getDetails() << p6->getDetails();
}

void plantPrototype_test()
{
     Plant *p1 = new Orchid();
     Plant *p2 = p1->clone();

     cout << p1->getDetails() << ".........\n"
          << p2->getDetails();
}

void plantState_test()
{
     /*Plant *p1 = new HoneySuckle();
     cout << "\n"
          << p1->getState() << "\n";
     p1->handleCare();
     cout << "\n"
          << p1->getState() << "\n";
     p1->handleCare();
     cout << "\n"
          << p1->getState() << "\n";
     p1->handleCare();
     cout << "\n"
          << p1->getState() << "\n";
     p1->handleCare();
     cout << "\n"
          << p1->getState() << "\n";
     p1->handleCare();
     cout << "\n"
          << p1->getState() << "\n";
     p1->handleCare();
     cout << "\n"
          << p1->getState() << "\n";*/

     // to test this, change hanldeCare() visibility in Plant class public from protected
}

void plantDecorator_test()
{
     // decoration happens at the last step of the purchasing process
     Plant *p1 = new Orchid();
     Plant *pot = new PotDecorator();
     Plant *wrap = new WrapDecorator();
     Plant *arrangement = new ArrangementDecorator();

     pot->decorate(p1);
     wrap->decorate(pot);
     arrangement->decorate(wrap);

     cout << arrangement->getDetails();
     cout << arrangement->getCost();

     cout << "\n................. cloned decorated plant\n";
     Plant *p2 = arrangement->clone();
     cout << p2->getDetails();
     cout << p2->getCost();

     Plant *pot2 = new PotDecorator();
     Plant *clonedDecorator = pot2->clone();
     cout << "\ncopy decorator only\n";
     cout << clonedDecorator->getDetails();
}

void plantStrategy_test()
{
     Plant *orchid = new Orchid();

     // ......... seedling ........//
     cout << orchid->getDetails();

     orchid->nuturePlant();
     orchid->nuturePlant();
     orchid->nuturePlant();
     orchid->nuturePlant();

     // ........ growing .........//
     cout << orchid->getDetails();

     orchid->nuturePlant();
     orchid->nuturePlant();
     orchid->nuturePlant();
     orchid->nuturePlant();

     // ........ mature .........//
     cout << orchid->getDetails();

     orchid->nuturePlant();
     orchid->nuturePlant();
     orchid->nuturePlant();
     orchid->nuturePlant();

     // ........ moult .........//
     cout << orchid->getDetails();

     orchid->nuturePlant();
     orchid->nuturePlant();
     orchid->nuturePlant();
     orchid->nuturePlant();

     // ........ dead .........//
     cout << orchid->getDetails();

     orchid->nuturePlant();
     orchid->nuturePlant();
     orchid->nuturePlant();
     orchid->nuturePlant();

     // ........ dead .........//
     cout << orchid->getDetails();

     orchid->nuturePlant();
     orchid->nuturePlant();
     orchid->nuturePlant();
     orchid->nuturePlant();
}

void request_test()
{
     Request* r2 = new Request();
     Request* r1 = new Request(); //<----- 2 request to test ID works
     r1->setAction("test");
     r1->setDescription("testDetails");

     Plant* p1 = new HoneySuckle();
     r1->setPlantObject(p1);
     r2->getAction();
      
     Plant* p2 = r1->getPlantObject();
     cout<<r1->getID()<<r1->getAction()<<r1->getDetails()<<p2->getDetails()<<endl;
     cout<<r2->getID();

}

void command_test()
{
     Plant* beeBlossom = new BeeBlossom();
     Staff* farmer = new Horticulturist("John Doe");

     Request* request = new Request;
     request->setAction(ACTION_STOREPLANT);
     request->setDescription("testing....");
     request->setSender(farmer);
     request->setPlantObject(beeBlossom);

     Command* command = new InventoryCommand(request);
     cout<<"\nShould return false: "<<command->hasAcess(farmer->getStaffType())<<endl;
     cout<<"\nShould return true: "<<command->hasAcess(toUpperCase("inventoryclerk"))<<endl; 
     
     Request* request_reciever = command->execute();

     cout<<request_reciever->getDetails();
}

void chainOfResponsibility_test_horticulturist()
{
     Inventory* inventory = new Inventory(3);

     InventoryClerk* inventoryClerk = new InventoryClerk("John Doe");
     inventoryClerk->assignJob(inventory);

     Horticulturist* horticulturist = new Horticulturist("Speedy Weedy");

     horticulturist->setNextHandler(inventoryClerk);

     inventory->peak();

     horticulturist->movePlantToInventory(new Orchid());
     horticulturist->movePlantToInventory(new Orchid());
     horticulturist->movePlantToInventory(new Orchid());
     horticulturist->movePlantToInventory(new Orchid());
     horticulturist->movePlantToInventory(new HouseLeek());
     horticulturist->movePlantToInventory(new Marigold());
     horticulturist->movePlantToInventory(new BeeBlossom());
     horticulturist->movePlantToInventory(new PeanutCactus());
     horticulturist->movePlantToInventory(new HoneySuckle());

     inventory->peak();

     

}



int main(int argc, char const *argv[])
{
     plantFactory_test();
     plantPrototype_test();
     plantState_test();
     plantDecorator_test();
     plantStrategy_test();
     plant_test();
     request_test();
     command_test();
     chainOfResponsibility_test_horticulturist();

     /*SimulationTime simulationTime;
     simulationTime.initialize();

     Inventory nursery(4);
     nursery.peak();

     Plant* p1 = new Marigold();
     Plant* p2 = new HouseLeek();

     Box* box1 = new Box(p1);

     Box* box2 = new Box(p2);

     nursery.addBox(box1,"FLOWER");
     nursery.addBox(box2,"SUCCULENT");
     nursery.peak();*/

     return 0;
}
