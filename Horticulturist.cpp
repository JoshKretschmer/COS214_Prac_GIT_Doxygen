//
// Created by zanri on 30/10/2025.
//

#include "Horticulturist.h"
#include "Inventory.h"  // Need this for movePlantToInventory

Horticulturist::Horticulturist(string _name) : Staff(_name) {
    staffType = "Horticulturist";
}

Horticulturist::~Horticulturist() {
}

void Horticulturist::executeTask(Command* command) {
    //duties related to plantcare and maintanence
    cout << "Horticulturist " << staffName << " executing task" << endl;

    //waiting for command
    
}

void Horticulturist::movePlantToInventory(Plant* plant) {
    //template method pattern: makes request, makes command, sends it off
    cout << "Horticulturist " << staffName << " moving plant to inventory" << endl; //temp
    
    //make a request for this action
    //Request* request = new Request("move_plant", plant->getID(), "Move plant to inventory");
    
    //make a command from the request
    // Command* command = new MovePlantCommand(plant, inventory); //might need a MovePlant command
    
    //execute the command
    //executeTask(command);
    
    //now just print until Command pattern is ready
    cout << "Would move plant " << plant->getID() << " to inventory" << endl;
}