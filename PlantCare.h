#ifndef PLANTCARE_H
#define PLANTCARE_H


class Plant;

class PlantCare {
    public:
        PlantCare();
        virtual ~PlantCare();
        virtual bool executeCare();
};

class SunlightStrategy : public PlantCare {
    public:
        SunlightStrategy();
        ~SunlightStrategy() override;
        bool executeCare();
};

class WateringStrategy : public PlantCare {
    public:
        WateringStrategy();
        ~WateringStrategy() override;
        bool executeCare();
};

class FertilizingStrategy : public PlantCare {
    public:
        FertilizingStrategy();
        ~FertilizingStrategy() override;
        bool executeCare();
};

class CompositeCareStrategy : public PlantCare {
    public:
        CompositeCareStrategy();
        ~CompositeCareStrategy() override;
        bool executeCare();
};



#endif //PLANTCARE_H