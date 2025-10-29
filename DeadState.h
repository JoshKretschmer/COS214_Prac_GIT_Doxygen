#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "PlantState.h"

class DeadState : public PlantState {
public:
    DeadState() = default;
    int handleCare(Plant* plant) override;
    std::string getStateName() override;
};

#endif // DEADSTATE_H