#include "Vehicle.h"

class Motorcycle : public Vehicle
{
private :
    string Type;
    bool hasABS;
    int seatHeight;

public:
    //Association (Composition) due to strong relation between Moto and engine ,, moto and battery
    // Moto Can not be made without engine or battary
    Engine *engine;
    Battery *battery;

public:
    Motorcycle(string Brand, string Model, int Year, long long Mileage, double Price, string Transimission, int MaxSpeed,
               string Type, bool hasABS, int seatHeight); // constructor

    string GetType();

    bool GetHasAbs();

    int GetseatHieght();

    void ViewDetails() override;


};
