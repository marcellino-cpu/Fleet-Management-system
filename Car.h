#include "Vehicle.h"

class Car : public Vehicle
{
private:
    int NumberOfSeats;
    int NumberOfDoors;
    int TrunkCapacity;
    string BodyType;

public:
    //Association (Composition) due to the strong relation between Car and engine and also Car and Battery
    // Car can not exist without Engine or battery
    Engine *engine;
    Battery *battery;

public :
    Car(string Brand, string Model, int year, long long Mileage, double price, string Transimission, int MaxSpeed,
        int NumberOfSeats, int NumberOfDoors, int TrunkCapacity, string BodyType);   // constructor

    int GetNumberOfSeats();

    int GetNumberOfDoors();

    int GetTrunkCapacity();

    string GetBodyType();

    void ViewDetails() override;

};
