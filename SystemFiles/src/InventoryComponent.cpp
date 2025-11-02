#include "../inc/InventoryComponent.h"
#include <iostream>
#include "../inc/Plant.h"

InventoryComponent::InventoryComponent()
{
}

InventoryComponent::~InventoryComponent()
{
}

void InventoryComponent::add(InventoryComponent *component)
{
    std::cout << "Calling InventoryComponent::add(component="
              << (component ? "non-null" : "null") << ")\n";
}

void InventoryComponent::remove(InventoryComponent *component)
{
    std::cout << "Calling InventoryComponent::remove(component="
              << (component ? "non-null" : "null") << ")\n";
}

void InventoryComponent::movePlant(Plant *plant, std::string newState)
{
    std::cout << "Calling InventoryComponent::movePlant(plant="
              << (plant ? plant->getDetails().c_str() : "null")
              << ", newState=\"" << newState << "\")\n";
}