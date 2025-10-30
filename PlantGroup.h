#ifndef PLANTGROUP_H
#define PLANTGROUP_H

#include "InventoryComponent.h"
#include <vector>

class PlantGroup : public InventoryComponent {
private:
    string groupName;
    vector<InventoryComponent*> children;
public:
    PlantGroup(string name);
    ~PlantGroup();

    void add(InventoryComponent* component);
    void remove(InventoryComponent* component);
    vector<Plant*> getPlants();
    void movePlant(Plant* plant, string newState);
};



#endif //PLANTGROUP_H
