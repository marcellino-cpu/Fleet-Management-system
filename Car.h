#include "Vehicle.h"

class Car : public Vehicle
{
private:
    int NumberOfSeats;
    int NumberOfDoors;
    int TrunkCapacity;
    std::string BodyType;

public:
    //Association (Composition) due to the strong relation between Car and engine and also Car and Battery
    // Car can not exist without Engine or battery
    Engine *engine;
    Battery *battery;

public :
    Car(std::string Brand, std::string Model, int year, long long Mileage, double price, std::string Transimission, int MaxSpeed,
        int NumberOfSeats, int NumberOfDoors, int TrunkCapacity, std::string BodyType);   // constructor

    int GetNumberOfSeats();

    int GetNumberOfDoors();

    int GetTrunkCapacity();

    std::string GetBodyType();

    void ViewDetails() override;

};
