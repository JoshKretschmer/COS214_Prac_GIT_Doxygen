#ifndef PEANUTCACTUS_H
#define PEANUTCACTUS_H

#include "Succulent.h"

class PeanutCactus : public Succulent {
public:
    PeanutCactus();
    std::string getDetails();
    double getCost();
};

#endif //PEANUTCACTUS_H
