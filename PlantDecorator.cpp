#include "PlantDecorator.h"

PlantDecorator::PlantDecorator()
{
    wrappedPlant = NULL;
}

PlantDecorator::~PlantDecorator()
{
    // delete wrappedPlant;   Still nee to verify object flow of control.
}

double PlantDecorator::getCost()
{
    double cost = decorator_price;

    if (wrappedPlant == NULL)
    {

        cout << errorMessage("Plant to be decorated has not been set");
    }
    else
    {
        cost += wrappedPlant->getCost();
    }

    return cost;
}

string PlantDecorator::getDetails()
{
    string decoratorDetails = "Decoration Type: " + decorator_type + "\n" + "Decoration fee: " + to_string(decorator_price);
    string details = "";

    if (wrappedPlant == nullptr)
    {
        details = "\n" + decoratorDetails + "\n";
        cout << errorMessage("Plant to be decorated has not been set");
    }
    else
    {
        details = wrappedPlant->getDetails() + decoratorDetails + "\n";
    }
    return details;
}

void PlantDecorator::decorate(Plant *_plant)
{
    if (wrappedPlant == NULL)
    {
        wrappedPlant = _plant;
    }
    else
    {
        cout << errorMessage("\nPlant is already decorated\n");
    }
}

// #################################################

ArrangementDecorator::ArrangementDecorator() : PlantDecorator()
{
    decorator_price = 10.00;
    decorator_type = toUpperCase("arrangement");
}

ArrangementDecorator::~ArrangementDecorator()
{
    // still need to verify object flow
}

Plant* ArrangementDecorator::clone()
{
    Plant* copy_wrappedPlant = NULL;
    Plant* copy_decorator = NULL;

    if(wrappedPlant)
    {
        copy_wrappedPlant = wrappedPlant->clone();
        copy_decorator = new ArrangementDecorator();
        copy_decorator->decorate(copy_wrappedPlant);
    }
    else
    {
        copy_decorator = new ArrangementDecorator();
    }

    return copy_decorator;
}
// #################################################

PotDecorator::PotDecorator()
{
    decorator_price = 20.00;
    decorator_type = toUpperCase("pot");
}

PotDecorator::~PotDecorator()
{
    // still need to verify object flow
}

Plant* PotDecorator::clone()
{
    Plant* copy_wrappedPlant = NULL;
    Plant* copy_decorator = NULL;

    if(wrappedPlant)
    {
        copy_wrappedPlant = wrappedPlant->clone();
        copy_decorator = new PotDecorator();
        copy_decorator->decorate(copy_wrappedPlant);
    }
    else
    {
        copy_decorator = new PotDecorator();
    }

    return copy_decorator;
}

// #################################################

WrapDecorator::WrapDecorator()
{
    decorator_price = 15.00;
    decorator_type = toUpperCase("wrap");
}

WrapDecorator::~WrapDecorator()
{
    // still need to verify object flow
}

Plant* WrapDecorator::clone()
{
    Plant* copy_wrappedPlant = NULL;
    Plant* copy_decorator = NULL;

    if(wrappedPlant)
    {
        copy_wrappedPlant = wrappedPlant->clone();
        copy_decorator = new WrapDecorator();
        copy_decorator->decorate(copy_wrappedPlant);
    }
    else
    {
        copy_decorator = new WrapDecorator();
    }

    return copy_decorator;
}