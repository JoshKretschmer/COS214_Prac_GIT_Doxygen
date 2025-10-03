#include "CategoryBasedRecommendation.h"
#include <stdexcept>


CategoryBasedRecommendation::CategoryBasedRecommendation(const std::string& category)
: category(category) {}


Plant CategoryBasedRecommendation::recommend(const std::vector<Plant>& plants) const {
    for (const auto& plant : plants) {
        if (plant.getCategory() == category) {
            return plant;
        }
    }
    throw std::runtime_error("No plant found for category " + category);
}

