#include "../inc/InventoryComponent.h"
#include <iostream>
#include "../inc/Plant.h"

/**
 * @brief Default constructor 
 */
InventoryComponent::InventoryComponent() {}

/**
 * @brief Destructor
 */
InventoryComponent::~InventoryComponent() {}

/**
 * @brief Adds a component to the inventory
 * 
 * @param component Pointer to the InventoryComponent's add
 */
void InventoryComponent::add(InventoryComponent *component)
{
    std::cout << "Calling InventoryComponent::add(component="
              << (component ? "non-null" : "null") << ")\n";
}

/**
 * @brief Removes a component from the inventory
 * 
 * @param component Pointer to the InventoryComponent's remove.
 */
void InventoryComponent::remove(InventoryComponent *component)
{
    std::cout << "Calling InventoryComponent::remove(component="
              << (component ? "non-null" : "null") << ")\n";
}

/**
 * @brief Moves a plant to a new state.
 * 
 * @param plant Pointer to the Plant to move.
 * @param newState The new state for the plant.
 */
void InventoryComponent::movePlant(Plant *plant, std::string newState)
{
    std::cout << "Calling InventoryComponent::movePlant(plant="
              << (plant ? plant->getDetails().c_str() : "null")
              << ", newState=\"" << newState << "\")\n";
}