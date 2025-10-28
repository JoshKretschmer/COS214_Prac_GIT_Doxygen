#include "PlantDecorator.h"

/*!
 * @brief Basic constructor function for PlantDecorator
 */
PlantDecorator::PlantDecorator()
{
    wrappedPlant = NULL;
}

/*!
 * @brief Basic destructor function for PlantDecorator
 */
PlantDecorator::~PlantDecorator()
{
    // delete wrappedPlant;   Still nee to verify object flow of control.
}

/*!
 *
 * @return Cost of the Plant with added decoration
 */
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

/*!
 *
 * @return Details of the plant and decoratoin added
 */
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

/*!
 * @brief Basic setter function for wrappedPlant attribute
 *
 * @param _plant Plant object to be attached to the Decorator object
 */
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

/*!
 * @brief Basic constructor for ArrangementDecorator
 */
ArrangementDecorator::ArrangementDecorator() : PlantDecorator()
{
    decorator_price = 10.00;
    decorator_type = toUpperCase("arrangement");
}

/*!
 * @brief Basic destructor for ArrangementDecorator
 */
ArrangementDecorator::~ArrangementDecorator()
{
    // still need to verify object flow
}

/*!
 *
 * @return Clone object ob Decorated Plant object
 */
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

/*!
 * @brief Basic constructor for PotDecorator
 */
PotDecorator::PotDecorator()
{
    decorator_price = 20.00;
    decorator_type = toUpperCase("pot");
}

/*!
 * @brief Basic destructor for PotDecorator
 */
PotDecorator::~PotDecorator()
{
    // still need to verify object flow
}

/*!
 *
 * @return Clone object ob Decorated Plant object
 */
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

/*!
 * @brief Basic constructor for WrapDecorator
 */
WrapDecorator::WrapDecorator()
{
    decorator_price = 15.00;
    decorator_type = toUpperCase("wrap");
}

/*!
 * @brief Basic destructor for WrapDecorator
 */
WrapDecorator::~WrapDecorator()
{
    // still need to verify object flow
}

/*!
 *
 * @return Clone object ob Decorated Plant object
 */
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