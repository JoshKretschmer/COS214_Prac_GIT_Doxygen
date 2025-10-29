#ifndef SEEDINGSTATE_H
#define SEEDINGSTATE_H

#include "PlantState.h"

class SeedingState : public PlantState {
public:
    SeedingState() = default;
    int handleCare(Plant* plant) override;
    std::string getStateName() override;
};

#endif // SEEDINGSTATE_H