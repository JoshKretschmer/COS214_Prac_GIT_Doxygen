#include "PlantCare.h"
#include <iostream>

using namespace std;

PlantCare::PlantCare() {

}

bool PlantCare::executeCare() {
    return true;
}

//#############################################

SunlightStrategy::SunlightStrategy() {

}

bool SunlightStrategy::executeCare() {
    cout << "Providing sunlight to the plant." << endl;
    return true;
}

string SunlightStrategy::getCareType() {
    return "Sunlight";
}

//#############################################

WateringStrategy::WateringStrategy() {

}

bool WateringStrategy::executeCare() {
    cout << "Watering the plant." << endl;
    return true;
}

string WateringStrategy::getCareType() {
    return "Watering";
}

//#############################################

FertilizingStrategy::FertilizingStrategy() {

}

bool FertilizingStrategy::executeCare() {
    cout << "Fertilizing the plant." << endl;
    return true;
}

string FertilizingStrategy::getCareType() {
    return "Fertilizing";
}

//#############################################

CompositeCareStrategy::CompositeCareStrategy() {

}

bool CompositeCareStrategy::executeCare() {
    cout << "Executing composite care strategy:" << endl;
    SunlightStrategy sunlight;
    WateringStrategy water;
    FertilizingStrategy fertilize;

    sunlight.executeCare();
    water.executeCare();
    fertilize.executeCare();

    return true;
}

string CompositeCareStrategy::getCareType() {
    return "Composite";
}

PlantCare::~PlantCare() {}
SunlightStrategy::~SunlightStrategy() {}
WateringStrategy::~WateringStrategy() {}
FertilizingStrategy::~FertilizingStrategy() {}
CompositeCareStrategy::~CompositeCareStrategy() {}