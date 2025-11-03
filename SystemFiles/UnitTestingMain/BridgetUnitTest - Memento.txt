TEST_CASE("Test Memento") {
    Order order;

    CreateSucculent factory;
    Plant *peanut = factory.createPlant("PeanutCactus");
    Plant *houseleek = factory.createPlant("HouseLeek");

    order.addPlant(peanut);
    order.addPlant(houseleek);

    REQUIRE(order.getPlants().size() == 2);

    order.undoLastAddition();
    REQUIRE(order.getPlants().size() == 1);

    order.redoLastStep();
    REQUIRE(order.getPlants().size() == 2);

    order.undoLastAddition();
    order.undoLastAddition();
    REQUIRE(order.isEmpty());
}