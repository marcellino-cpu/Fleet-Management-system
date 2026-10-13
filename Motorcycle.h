#include "Vehicle.h"

class Motorcycle : public Vehicle
{
private :
    std::string Type;
    bool hasABS;
    int seatHeight;

public:
    //Association (Composition) due to strong relation between Moto and engine ,, moto and battery
    // Moto Can not be made without engine or battary
    Engine *engine;
    Battery *battery;

public:
    Motorcycle(std::string Brand, std::string Model, int Year, long long Mileage, double Price,
               std::string Transimission, int MaxSpeed,
               std::string Type, bool hasABS, int seatHeight); // constructor

    std::string GetType();

    bool GetHasAbs();

    int GetseatHieght();

    void ViewDetails() override;
};
