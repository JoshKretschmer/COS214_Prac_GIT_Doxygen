#include "PlantFactory.h"

/*!
 * @brief Basic constructor for PlantFactory
 */
PlantFactory::PlantFactory()
{

}


/*!
 * @brief Basic destructor for PlantFactory
 */
PlantFactory::~PlantFactory()
{

}

/*!
 * @brief Creator function for Plant objects of type Succulent
 * Takes "HouseLeek" or "PeanutCactus" as input, or gives an error and returns nullptr
 *
 * @param name Specifies which plant object to create
 * @return Plant object of specified class, or nullptr as error
 */
Plant *CreateSucculent::createPlant(string name)
{
    if(toUpperCase(name) == "PEANUTCACTUS")
    {
        return new PeanutCactus();
    } 
    else if(toUpperCase(name) == "HOUSELEEK")
    {
        return new HouseLeek();
    } 
    else
    {
        std::cout<<errorMessage("Invalid name...");
        return NULL;
    }
}

/*!
 * @brief Creator function for Plant objects of type Flower
 * Takes "Marigold" or "Orchid" as input, or gives an error and returns nullptr
 *
 * @param name Specifies which plant object to create
 * @return Plant object of specified class, or nullptr as error
 */
Plant *CreateFlower::createPlant(string name)
{
    if(toUpperCase(name) == "MARIGOLD")
    {
        return new Marigold();
    } 
    else if(toUpperCase(name) == "ORCHID")
    {
        return new Orchid();
    } 
    else
    {
        std::cout<<errorMessage("Invalid name...");
        return NULL;
    }
}

/*!
 * @brief Creator function for Plant objects of type Shrub
 * Takes "HoneySuckle" or "BeeBlossom" as input, or gives an error and returns nullptr
 *
 * @param name Specifies which plant object to create
 * @return Plant object of specified class, or nullptr as error
 */
Plant *CreateShrub::createPlant(string name)
{
    if (toUpperCase(name) == "HONEYSUCKLE")
    {
        return new HoneySuckle();
    } 
    else if(toUpperCase(name) == "BEEBLOSSOM")
    {
        return new BeeBlossom();
    } 
    else
    {
        std::cout<<errorMessage("Invalid name...");
        return NULL;
    }
}