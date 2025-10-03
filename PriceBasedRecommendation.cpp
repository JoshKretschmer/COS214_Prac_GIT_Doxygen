#include "PriceBasedRecommendation.h"
#include <algorithm>
#include <stdexcept>



Plant PriceBasedRecommendation::recommend(const std::vector<Plant>& plants) const {
    if (plants.empty()) {
        throw std::runtime_error("No plants available");
    }
    Plant cheapest = plants[0];
    for (const auto& plant : plants) {
        if (plant.getPrice() < cheapest.getPrice()) {
            cheapest = plant;
        }
    }
    return cheapest;
}
