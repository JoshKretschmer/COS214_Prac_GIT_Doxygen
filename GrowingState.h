#ifndef GROWINGSTATE_H
#define GROWINGSTATE_H

#include "SeedingState.h"

class GrowingState : public SeedingState {
public:
    GrowingState() = default;
    int handleCare(Plant* plant) override;
    std::string getStateName() override;
};

#endif // GROWINGSTATE_H