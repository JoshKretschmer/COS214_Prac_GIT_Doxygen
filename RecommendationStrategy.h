/**
* @file RecommendationStrategy.h
* @brief Defines the interface for recommendation strategies in the Nursery System.
*/


#ifndef RECOMMENDATIONSTRATEGY_H
#define RECOMMENDATIONSTRATEGY_H


#include "Plant.h"
#include <vector>


/**
* @class RecommendationStrategy
* @brief Interface for plant recommendation strategies.
*/
class RecommendationStrategy {
public:
virtual Plant recommend(const std::vector<Plant>& plants) const = 0;
virtual ~RecommendationStrategy() {}
};


#endif