/**
* @file PriceBasedRecommendation.h
* @brief Implements price-based recommendation strategy.
*/


#ifndef PRICEBASEDRECOMMENDATION_H
#define PRICEBASEDRECOMMENDATION_H


#include "RecommendationStrategy.h"


/**
* @class PriceBasedRecommendation
* @brief Recommends the plant with the lowest price.
*/
class PriceBasedRecommendation : public RecommendationStrategy {
public:
Plant recommend(const std::vector<Plant>& plants) const override;
};


#endif