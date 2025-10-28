#ifndef REQUEST_H
#define REQUEST_H
/*!
 * @headerfile Request.h
 */
#include "libraries.h"
#include "Staff.h"
#include "Plant.h"

class Staff;
class Plant;

/*!
 * @class Request
 *
 * @brief Used by Staff objects to ask another to do a required action
 */
class Request {
    private:

        static int instanceCount;
        string id; //<---- do not make a getter and setter here

        string description;
        string action;

        Staff* sender;

        // ....... horticulturist related pointers ............//

        Plant* plantObject;

        // ....... Sales Associate related pointers ...........//

        // ....... InventoryClerk related info ............//

        // ....... Manager related info ..................//


    public:
        Request();
        ~Request();

        // ........... setters ..............//
        void setAction(string action);
        void setDescription(string _description);
        void setSender(Staff* _sender);
        void setPlantObject(Plant* plantObject);


        // ........... getters ............. //
        string getID(){return id;};
        string getDetails();
        string getDescription(){return description;};
        string getAction(){return action;};
        Plant* getPlantObject(){return plantObject;};
        Staff* getSender(){return sender;};

        // ......... other functions ...........//

        //maybe a bulk request function specific to different staff
};


#endif //REQUEST_H