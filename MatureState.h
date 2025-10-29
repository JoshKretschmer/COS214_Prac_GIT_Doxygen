#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "SeedingState.h"

class MatureState : public SeedingState {
public:
    MatureState() = default;
    int handleCare(Plant* plant) override;
    std::string getStateName() override;
};

#endif // MATURESTATE_H