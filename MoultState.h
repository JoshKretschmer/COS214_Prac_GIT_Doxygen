#ifndef MOULTSTATE_H
#define MOULTSTATE_H

#include "SeedingState.h"

class MoultState : public SeedingState {
public:
    MoultState() = default;
    int handleCare(Plant* plant) override;
    std::string getStateName() override;
};

#endif // MOULTSTATE_H