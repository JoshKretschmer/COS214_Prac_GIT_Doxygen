/**
* @file CategoryBasedRecommendation.h
* @brief Implements category-based recommendation strategy.
*/


#ifndef CATEGORYBASEDRECOMMENDATION_H
#define CATEGORYBASEDRECOMMENDATION_H


#include "RecommendationStrategy.h"
#include <string>


/**
* @class CategoryBasedRecommendation
* @brief Recommends the first plant matching a given category.
*/
class CategoryBasedRecommendation : public RecommendationStrategy {
private:
std::string category;
public:
CategoryBasedRecommendation(const std::string& category);
Plant recommend(const std::vector<Plant>& plants) const override;

};


#endif