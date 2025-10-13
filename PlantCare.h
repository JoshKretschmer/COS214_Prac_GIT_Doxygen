#ifndef PLANTCARE_H
#define PLANTCARE_H



class PlantCare {
    public:
        PlantCare();
        virtual ~PlantCare();
        virtual bool executeCare();
};

class SunlightStrategy : public PlantCare {
    public:
        SunlightStrategy();
        bool executeCare();
};

class WateringStrategy : public PlantCare {
    public:
        WateringStrategy();
        bool executeCare();
};

class FertilizingStrategy : public PlantCare {
    public:
        FertilizingStrategy();
        bool executeCare();
};

class CompositeCareStrategy : public PlantCare {
    public:
        CompositeCareStrategy();
        bool executeCare();
};



#endif //PLANTCARE_H
