#include "PlantFactory.h"

PlantFactory::PlantFactory()
{

}


PlantFactory::~PlantFactory()
{

}


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