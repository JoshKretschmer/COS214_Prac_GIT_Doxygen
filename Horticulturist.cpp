#include "Horticulturist.h"

/*!
 *
 * @param command Command object containing request to be executed
 */
void Horticulturist::executeTask(Command* command)
{
    Request* request = command->execute();
    request->getID();

    // types of request it had do is yet to be discussed
    //Plant creation request?
}

/*!
 * @brief Basic constructor
 *
 * @param name Name of new Horticulturist
 */
Horticulturist::Horticulturist(string name) : Staff(name)
{
    staffName = "horticulturist";
}

/*!
 * @brief Basic destructor
 */
Horticulturist::~Horticulturist()
{
    //no memory management as of yet
}

/*!
 * @return Request action for moving/storing a plant
 */
string Horticulturist::getActionForMove() {
    return ACTION_STOREPLANT;  // Specific to Horticulturist
}

/*!
 *
 * @return Request description from moving/storing a plant
 */
string Horticulturist::getDescriptionForMove() {
    return "just store the plant :)";  // Specific to Horticulturist
}